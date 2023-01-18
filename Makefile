# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:37:10 by tdubois           #+#    #+#              #
#    Updated: 2023/01/18 12:35:06 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### SHELL OPTS

SHELL		:=	/usr/bin/bash
.SHELLFLAGS	:=	-e -o pipefail -c --

.SECONDEXPANSION:

################################################################################
### MAKE OPTS

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --output-sync

.DEFAULT_GOAL	:=	all

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

all:
	$(LOG_PHONY)
	@$(MAKE) $(NAME);
.PHONY: all

clean:
	$(LOG_PHONY)
	$(MAKE) -C $(dir $(LIBFT)) clean;
	rm -rf $(BUILD);
.PHONY: clean

fclean:
	$(LOG_PHONY)
	$(MAKE) -C $(dir $(LIBFT)) fclean;
	rm -rf $(BUILD);
	rm -rf $(NAME);
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### CUSTOM TARGETS

fast:
	$(MAKE) --jobs=8 all;
.PHONY: fast

refast: fclean fast
.PHONY: refast

################################################################################
### NAME TARGET 

$(NAME): $(LIBFT) $(OBJS)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME);

################################################################################
### OBJS TARGET

$(sort $(patsubst %/,%,$(dir $(OBJS)))):
	$(LOG_TARGET)
	mkdir -p $@;

$(OBJS): $(BUILD)/%.o: %.c | $$(@D)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@;

-include $(DEPS)

################################################################################
### LIBFT TARGET

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT));

################################################################################
### TOOLS

MAGENTA	:=	$(shell echo -e '\033[0;35m')
BLUE	:=	$(shell echo -e '\033[0;34m')
NC		:=	$(shell echo -e '\033[0m')

define LOG_TARGET
	$(info $(MAGENTA)Building $@:$(NC))
endef

define LOG_PHONY
	$(info $(BLUE)$@!$(NC))
endef
