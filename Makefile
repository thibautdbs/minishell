# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:37:10 by tdubois           #+#    #+#              #
#    Updated: 2023/01/17 17:13:16 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			=	/usr/bin/bash
.SHELLFLAGS		=	-ec
.ONESHELL:

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --silent
.DEFAULT_GOAL	=	all

################################################################################
### LIBFT TARGET

NAME		=	minishell

SRC			=	src
INCLUDE		=	include

BUILD		=	.build

################################################################################
### STANDARD TARGETS

all:
	$(info Building...)
	$(MAKE) --jobs=8 --output-sync=recurse $(NAME);
	echo;
.PHONY: all

clean:
	$(info Cleaning...)
	$(MAKE) -C $(dir $(LIBFT)) clean;
	rm -rf $(BUILD);
.PHONY: clean

fclean:
	$(info Cleaning(full)...)
	$(MAKE) -C $(dir $(LIBFT)) fclean;
	rm -rf $(BUILD);
	rm -rf $(NAME);
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### LIBFT TARGET

LIBFT	=	libft/libft.a

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT));

################################################################################
### FLAGS

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -O3
CPPFLAGS	=	-MP -MMD -I$(INCLUDE) -I$(dir $(LIBFT))/include
LDFLAGS     =	-L$(dir $(LIBFT)) -l:$(notdir $(LIBFT)) -lreadline

#SRCS		:=

################################################################################
### OBJS TARGET

OBJS	=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS	=	$(SRCS:%.c=$(BUILD)/%.d)

$(BUILD)/src/%.o: src/%.c
	mkdir -p $(@D);
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -xc $< -o $@;
	echo -n '.';

-include $(DEPS) dev.mk

################################################################################
### NAME TARGET 

$(NAME): $(LIBFT) $(OBJS)
	echo objs:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME);

################################################################################

