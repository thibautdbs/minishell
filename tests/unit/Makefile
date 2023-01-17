# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/17 17:50:38 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=	/usr/bin/bash
.SHELLFLAGS		=	-ec
.ONESHELL:

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --silent
.DEFAULT_GOAL	:=	all

################################################################################
### DIRECTORIES

ROOT		:=	$(shell git rev-parse --show-cdup)

SRC			:=	src
INCLUDE		:=	include

BUILD		:=	.build

################################################################################
### STANDARD TARGETS

all: clean
	$(info Building runners...)
	$(MAKE) --jobs=8 --output-sync=recurse $(RUNNERS);
.PHONY: all

clean:
	$(info Cleaning runners...)
	$(RM) $(BUILD);
.PHONY: clean

################################################################################
### RUNNERS

SUITES		:=	$(shell find src -name '*.test.c')
RUNNERS		:=	$(SUITES:%.c=$(BUILD)/runners/%.out)

CC			:=	clang

CFLAGS		:=	-Wall								\
				-Wextra								\
				-Wno-unused-command-line-argument	\
				-Werror								\
				-ggdb3								\
				-c									\

CPPFLAGS	:=	-MP									\
				-MMD								\
				-I$(SRC)							\
				-I$(INCLUDE)						\
				-I$(ROOT)/src						\
				-I$(ROOT)/include					\
				-I$(ROOT)/libft/include				\

LDFLAGS		:=	-L$(ROOT)/tests -l:minishell.a		\
				-L$(ROOT)/libft -l:libft.a			\
				-lreadline							\

$(BUILD)/runners/%.test.out: ./%.test.c
	mkdir -p $(@D);
	-scripts/mkrunner $< | $(CC) $(CFLAGS) $(CPPFLAGS) -xc $< $(LDFLAGS) -o $@;

################################################################################
### TAPFILES

TAPFILES	:=	$(RUNNERS:%.out=%.tap)

$(BUILD)/runners/%.test.tap: $(BUILD)/runners/%.test.out
	@$(DIRDUP)
	- >&$@ timeout --kill-after=5s 3s valgrind						\
											--quiet					\
											--leak-check=full		\
											--show-reachable=yes	\
											-- $<

################################################################################
### TEST

run:
	rm -rf $(BUILD)
	$(MAKE) -j $(TAPFILES)
	- 2>/dev/null cat $(TAPFILES)
.PHONY: run
