# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:37:10 by tdubois           #+#    #+#              #
#    Updated: 2023/01/18 00:33:43 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=	/usr/bin/bash
MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory

.DEFAULT_GOAL	:=	all

LOG		=	@echo -e '\033[0;35m'$(1)'\033[0m'

-include dev.mk

################################################################################
### GOALS

NAME		:=	minishell
LIBFT		:=	libft/libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
INCLUDE		:=	include
BUILD		:=	.build

################################################################################
### FLAGS

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -O3
CPPFLAGS	=	-MP -MMD -I$(INCLUDE) -I$(dir $(LIBFT))/include
LDFLAGS     =	-L$(dir $(LIBFT)) -l:$(notdir $(LIBFT)) -lreadline

################################################################################
### FILES

# SRCS	:=

OBJS	:=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS	:=	$(SRCS:%.c=$(BUILD)/%.d)

################################################################################
### STANDARD TARGETS

all: libft objs name
.PHONY: all

clean:
	$(call LOG,clean!);
	$(MAKE) -C $(dir $(LIBFT)) clean;
	rm -rf $(BUILD);
.PHONY: clean

fclean:
	$(call LOG,fclean!);
	$(MAKE) -C $(dir $(LIBFT)) fclean;
	rm -rf $(BUILD);
	rm -rf $(NAME);
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### NAME TARGET 

name: $(NAME)
.PHONY: name

$(NAME): $(LIBFT) $(OBJS)
	$(call LOG,building $@:);
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME);

################################################################################
### OBJS TARGET

objs:
	@parallel -j8 "$(MAKE) -q {} || $(MAKE) {}" ::: $(OBJS);
.PHONY: objs

# $(sort $(patsubst %/,%,$(dir $(OBJS)))):
# 	$(call LOG,building $@:);
# 	mkdir -p $@;

$(OBJS): $(BUILD)/%.o: %.c
	$(call LOG,building $@:);
	mkdir -p $(@D);
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@;

-include $(DEPS)

################################################################################
### LIBFT TARGET

libft: $(LIBFT)
.PHONY: libft

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT));
