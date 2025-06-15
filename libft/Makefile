# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:20:23 by loicpapon         #+#    #+#              #
#    Updated: 2025/02/19 16:46:51 by Lopapon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
              ft_bzero.c \
              ft_calloc.c \
              ft_isalnum.c \
              ft_isalpha.c \
              ft_isascii.c \
              ft_isdigit.c \
              ft_isprint.c \
              ft_itoa.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_memcpy.c \
              ft_memmove.c \
              ft_memset.c \
              ft_putchar_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              ft_putstr_fd.c \
              ft_split.c \
              ft_strchr.c \
              ft_strdup.c \
              ft_striteri.c \
              ft_strjoin.c \
              ft_strlcat.c \
              ft_strlcpy.c \
              ft_strlen.c \
              ft_strmapi.c \
              ft_strncmp.c \
              ft_strnstr.c \
              ft_strrchr.c \
              ft_strtrim.c \
              ft_substr.c \
              ft_tolower.c \
              ft_toupper.c \
              ft_print_char.c \
              ft_print_hex.c \
              ft_print_int.c \
              ft_print_percent.c \
              ft_print_ptr.c \
              ft_print_str.c \
              ft_print_unsigned_int.c \
              ft_printf.c \
              ft_lstadd_back_bonus.c \
              ft_lstadd_front_bonus.c \
              ft_lstclear_bonus.c \
              ft_lstdelone_bonus.c \
              ft_lstiter_bonus.c \
              ft_lstlast_bonus.c \
              ft_lstmap_bonus.c \
              ft_lstnew_bonus.c \
              ft_lstsize_bonus.c \
              ft_putchar.c \
              ft_isspace.c

OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c libft.h
	${CC} ${CFLAGS} -I. -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re