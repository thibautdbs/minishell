# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:37:10 by tdubois           #+#    #+#              #
#    Updated: 2023/02/10 17:35:08 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### SHELL OPTS

SHELL			:=	/usr/bin/bash
.SHELLFLAGS		:=	-e -o pipefail -c --
MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --output-sync
.DEFAULT_GOAL	:=	all

.DELETE_ON_ERROR:
.SECONDEXPANSION:
.SECONDARY:

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
LDFLAGS     =	-L$(dir $(LIBFT)) -lft -lreadline

################################################################################
### FILES

SRCS		=	$(shell find $(SRC) -name '*.c')

OBJS		=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS		=	$(SRCS:%.c=$(BUILD)/%.d)

################################################################################
### MANDATORY CMDS

all: $(NAME)
.PHONY: all

clean::
	$(MAKE) -C $(dir $(LIBFT)) clean;
	rm -rf $(BUILD);
.PHONY: clean

fclean::
	$(MAKE) -C $(dir $(LIBFT)) fclean;
	rm -rf $(BUILD);
	rm -rf $(NAME);
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### CUSTOM CMDS

fast:
	$(MAKE) --jobs=8 all;
.PHONY: fast

refast: fclean fast
.PHONY: refast

################################################################################
### NAME TARGET 

$(NAME): $(LIBFT) $(OBJS)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@;

################################################################################
### OBJS TARGET

$(sort $(shell dirname $(OBJS))):
	$(LOG_TARGET)
	mkdir -p $@;

$(BUILD)/%.o: %.c | $$(@D)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@;

-include $(DEPS)

################################################################################
### LIBFT TARGET

#Makes libft PHONY if needs rebuild.
$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT));
$(shell make -q -C $(dir $(LIBFT)) >&/dev/null)
ifneq ($(.SHELLSTATUS), 0)
.PHONY: $(LIBFT)
endif

################################################################################
### TOOLS

MAGENTA	:=	$(shell echo -e '\033[0;35m')
BLUE	:=	$(shell echo -e '\033[0;34m')
NC		:=	$(shell echo -e '\033[0m')

define LOG_TARGET
	$(info $(MAGENTA)Building $@:$(NC))
endef

-include test.mk
