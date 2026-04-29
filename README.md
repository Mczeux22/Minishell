# 🐚 Minishell — As beautiful as a shell

> Projet 42 — Recréer un shell Bash simplifié en C.  
> Objectif : comprendre en profondeur les processus, les file descriptors et le fonctionnement d'un shell Unix.

---

## 📚 Sources & Références

- [Guide Minishell 42 — Medium](https://medium.com/@laamirimarouane8/42-minishell-guide-53600f49742b)
- [Spreadsheet de progression](https://docs.google.com/spreadsheets/d/1uJHQu0VPsjjBkR4hxOeCMEt3AOM1Hp_SmUzPFhAH-nA/edit?gid=0#gid=0)
- [README de référence — GitHub](https://github.com/Hqndler/42-minishell/blob/main/README.md)

---

## 🧠 Technologies & Concepts clés

| Concept | Rôle |
|---|---|
| **Tokenization** | Découper la ligne brute en unités atomiques (tokens) |
| **AST** | Représenter la structure logique des commandes |
| **fork()** | Créer un processus fils pour exécuter une commande |
| **execve()** | Remplacer l'image du processus par un exécutable |
| **Pipes** | Connecter stdout d'une commande au stdin de la suivante |
| **Redirections** | Réorienter les fd (stdin/stdout) vers des fichiers |
| **Signaux** | Gérer ctrl-C, ctrl-D, ctrl-\ proprement |

---

## 🏗️ Architecture du projet

```
minishell/
├── Makefile
├── includes/
│   └── minishell.h
└── src/
    ├── main.c          ← Boucle REPL principale
    ├── signal.c        ← Gestion des signaux
    ├── lexer.c         ← Tokenisation de la ligne
    ├── parser.c        ← Construction de l'AST
    ├── expand.c        ← Expansion des variables $VAR / $?
    ├── executor.c      ← fork + execve + PATH
    ├── pipes.c         ← Gestion des pipelines
    ├── redirections.c  ← < > << >>
    ├── builtins.c      ← Commandes internes
    └── utils.c         ← Fonctions utilitaires
```

---

## 🔄 Pipeline d'exécution

Chaque commande tapée par l'utilisateur passe par ces étapes dans l'ordre :

```
Entrée utilisateur
       │
       ▼
  1. READLINE         ← Affiche le prompt, lit la ligne, gère l'historique
       │
       ▼
  2. LEXER            ← Découpe en tokens (mots, pipes, redirections, quotes)
       │
       ▼
  3. PARSER           ← Construit l'AST / liste de commandes
       │
       ▼
  4. EXPANSION        ← Remplace $VAR et $? par leurs valeurs
       │
       ▼
  5. EXÉCUTION        ← Fork + execve, ou builtin direct
       │
       ▼
  6. WAIT             ← Parent attend le fils, récupère le code de sortie → $?
```

---

## 📦 Étapes d'implémentation

### ✅ Étape 1 — Boucle principale (REPL)
La boucle Read-Eval-Print Loop est le squelette du shell.  
`readline` affiche le prompt et retourne la ligne saisie allouée sur le heap.  
`add_history` permet la navigation avec les flèches.  
`NULL` retourné par readline = ctrl-D = quitter proprement.

**Règle importante** : une seule variable globale autorisée (`int g_signal`) pour les signaux.

---

### 🔤 Étape 2 — Lexer (Tokenisation)

Le lexer transforme la chaîne brute en une liste de tokens typés.

Types de tokens à gérer :

| Token | Exemple |
|---|---|
| WORD | `echo`, `hello`, `/bin/ls` |
| PIPE | `\|` |
| REDIR_IN | `<` |
| REDIR_OUT | `>` |
| HEREDOC | `<<` |
| REDIR_APPEND | `>>` |

**Règles des quotes :**
- `'single quote'` → tout est littéral, aucune interprétation
- `"double quote"` → tout est littéral **sauf** `$` qui est expansé
- Quote non fermée → erreur de syntaxe, ne pas exécuter

---

### 🌳 Étape 3 — Parser (AST)

Le parser transforme la liste de tokens en une structure exploitable.

Pour le **mandatory** : une liste chaînée de commandes séparées par des pipes suffit.  
Chaque nœud contient : le nom de la commande, ses arguments, ses redirections.

Pour le **bonus** (`&&`, `||`, parenthèses) : il faut un vrai **AST** (Abstract Syntax Tree) car les priorités changent l'ordre d'évaluation.

---

### 💲 Étape 4 — Expansion des variables

Avant l'exécution, chaque token de type WORD est analysé :

- `$NOM` → chercher dans l'environnement, remplacer par la valeur (ou `""` si absente)
- `$?` → remplacer par le code de sortie de la dernière commande

L'expansion se fait **après** le lexing, **avant** l'exécution.

---

### ⚙️ Étape 5 — Exécution (fork + execve)

Pour chaque commande externe (non builtin) :

1. **`fork()`** — crée un processus fils identique au parent
2. **Dans le fils** — `execve(chemin, args, env)` remplace le processus par l'exécutable
3. **Dans le parent** — `waitpid()` attend la fin du fils et récupère son exit code

**Trouver l'exécutable :**
- La commande contient un `/` → chemin direct, on appelle `execve` directement
- Sinon → parcourir chaque entrée de `$PATH`, tester avec `access()` si le fichier est exécutable

---

### 🔧 Étape 6 — Builtins

Les builtins s'exécutent **dans le processus shell lui-même**, sans fork.  
C'est obligatoire car ils modifient l'état du shell.

| Builtin | Pourquoi sans fork |
|---|---|
| `cd` | Change le répertoire du shell lui-même |
| `export` | Modifie l'environnement du shell |
| `unset` | Supprime une variable d'environnement |
| `exit` | Doit quitter le shell parent |
| `pwd` | Lit l'état courant du shell |
| `echo -n` | Simple écriture sur stdout |
| `env` | Affiche l'environnement courant |

**Exception** : dans une pipeline (`echo hello | cat`), même les builtins sont forkés car ils s'exécutent dans un sous-shell.

---

### 📁 Étape 7 — Redirections

Les redirections manipulent les file descriptors **avant** l'exécution de la commande, via `dup2`.

| Syntaxe | Comportement |
|---|---|
| `< fichier` | `open` en lecture + `dup2` vers stdin (fd 0) |
| `> fichier` | `open` en écriture avec troncature + `dup2` vers stdout (fd 1) |
| `>> fichier` | `open` en append + `dup2` vers stdout (fd 1) |
| `<< DELIM` | Lire les lignes jusqu'au délimiteur, rediriger depuis un pipe temporaire |

Si une commande a pipes **et** redirections, les redirections ont la priorité.

---

### 🔗 Étape 8 — Pipes

Un pipe connecte le stdout d'une commande au stdin de la suivante via la syscall `pipe()` qui retourne deux fd : un en lecture, un en écriture.

Pour une pipeline `cmd1 | cmd2 | cmd3` :
- On crée N-1 pipes pour N commandes
- Chaque fils redirige ses fd avec `dup2` avant d'appeler `execve`
- **Tous les fd inutilisés doivent être fermés** dans chaque processus — sinon les processus se bloquent indéfiniment à attendre une fermeture qui n'arrive jamais

---

### 📡 Étape 9 — Signaux

La gestion des signaux change selon le contexte d'exécution :

| Contexte | ctrl-C (SIGINT) | ctrl-\ (SIGQUIT) |
|---|---|---|
| Prompt interactif | Nouveau prompt sur nouvelle ligne | Ne rien faire |
| Pendant une commande | Transmettre au fils (comportement bash) | Transmettre au fils |
| Dans un heredoc | Interrompre la saisie | Ne rien faire |

`sigaction` est à préférer à `signal()` pour une gestion fiable.  
La variable globale `g_signal` (type `int` uniquement) permet au handler de communiquer avec le reste du programme sans accéder aux structures de données.

---

### 🌍 Étape 10 — Environnement

Le shell reçoit l'environnement via `char **envp` (3ème param de `main`).  
Il faut en faire **sa propre copie** dès le départ car `export` et `unset` vont le modifier.

Quand on `execve`, on passe notre environnement courant au fils, qui en hérite.

---

## 🎁 Bonus

| Bonus | Description |
|---|---|
| `&&` et `\|\|` | Opérateurs logiques avec gestion des priorités |
| Parenthèses `()` | Groupement de commandes, nécessite un vrai AST |
| Wildcards `*` | Expansion glob dans le répertoire courant |

> ⚠️ Le bonus n'est évalué que si le mandatory est **100% fonctionnel et sans bug**.

---

## ⚡ Règles importantes du sujet

- Une seule variable globale autorisée : un `int` pour le numéro de signal
- Pas de fuites mémoire dans **ton** code (les fuites de `readline` sont tolérées)
- Les fonctions ne doivent pas quitter inopinément (segfault, double free…)
- En cas de doute sur un comportement, `bash` fait référence
- Tout ce qui n'est pas demandé n'est pas requis

---

## 📋 Makefile — Règles obligatoires

```makefile
make        # compile le projet
make clean  # supprime les .o
make fclean # supprime les .o et le binaire
make re     # recompile tout
make bonus  # compile avec les fichiers _bonus.c
```

Flags obligatoires : `-Wall -Wextra -Werror`