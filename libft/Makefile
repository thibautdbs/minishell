# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 10:40:50 by tdubois           #+#    #+#              #
#    Updated: 2023/01/17 16:43:00 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=	/usr/bin/bash
.SHELLFLAGS		:=	-ec
.ONESHELL:

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --silent 
.DEFAULT_GOAL	:=	all

################################################################################
### GOAL

NAME		:=	libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
INCLUDE		:=	include

BUILD		:=	.build

################################################################################
### STANDARD TARGETS

all: $(NAME)
.PHONY: all

clean:
	rm -rf $(BUILD);
.PHONY: clean

fclean:
	rm -rf $(BUILD);
	rm -rf $(NAME);
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### FLAGS

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -O3
CPPFLAGS	:=	-MP -MMD -I$(INCLUDE)

################################################################################
### FILES

### Memory

SRCS	+=	ft_bzero.c			\
			ft_calloc.c			\
			ft_memset.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memdel.c			\
			ft_memdup.c			\

### Maths

SRCS 	+=	ft_min.c			\
			ft_min_arr.c		\
			ft_max.c			\
			ft_isneg.c			\
			ft_count_digits.c	\
			ft_mod.c			\

### Strings

SRCS	+=	ft_tochar.c			\

SRCS 	+=	ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\

SRCS	+=	ft_atoi.c			\
			ft_atoidup.c		\
			ft_isint.c			\

SRCS	+=	ft_itoa.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strspn.c			\
			ft_strcspn.c		\
			ft_strtok.c			\
			ft_strtok_r.c		\

SRCS	+=	ft_strjoin.c		\
			ft_strjoin_sep.c	\
			ft_strtrim.c		\
			ft_strdup.c			\
			ft_strndup.c		\
			ft_substr.c			\
			ft_split.c			\
			ft_strsdel.c		\

SRCS	+=	ft_search_str.c		\
	
SRCS	+=	ft_strmapi.c		\
			ft_striteri.c		\

SRCS	+=	ft_tolower.c		\
			ft_toupper.c		\

SRCS	+=	ft_strendswith.c	\

### ARRAYS

SRCS	+=	ft_indexof.c		\

SRCS	+=	ft_mtrx2_new.c		\
			ft_mtrx2_del.c		\

### IO

SRCS	+=	ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putstr_rpt_fd.c	\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_puterr.c			\
			ft_puterr_endl.c	\

SRCS	+=	ft_gnl.c			\

### Linked lists

SRCS 	+=	ft_lstnew.c			\
			ft_lstnew_int.c		\
			ft_lstpush.c		\
			ft_lstload.c		\
			ft_lstflat.c		\

SRCS	+=	ft_lstadd_front.c	\
			ft_lstadd_back.c	\
			ft_lstpop.c			\
			ft_lstdelone.c		\
			ft_lstclear.c		\

SRCS	+=	ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstat.c			\
			ft_lstindex.c		\
			ft_lstuniq.c		\

SRCS	+=	ft_lstiter.c		\
			ft_lstmap.c			\

SRCS	+=	ft_lstget_int.c		\

SRCS	+=	ft_lstreadlines.c	\

################################################################################
### OBJS TARGET

OBJS	:=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS	:=	$(SRCS:%.c=$(BUILD)/%.d)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(@D);
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -xc $< -o $@;
	echo -n '.';

-include $(DEPS)

################################################################################
### NAME TARGET

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS);
