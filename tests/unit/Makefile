# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/18 17:37:16 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### SHELL OPTS

SHELL		:=	/usr/bin/bash
.SHELLFLAGS	:=	-e -o pipefail -c --

.SECONDEXPANSION:

################################################################################
### MAKE OPTS

MAKEFLAGS   	+=	--no-builtin-rules 		\
					--no-print-directory	\
					--output-sync			\
					--keep-going			\
					--silent				\

.DEFAULT_GOAL	:=	all

################################################################################
### DIRECTORIES

ROOT		:=	$(shell git rev-parse --show-cdup)

SRC			:=	src
INCLUDE		:=	include

BUILD		:=	build

################################################################################
### FILES

LIBFT		:=	$(ROOT)/libft/libft.a
ARCHIVE		:=	$(ROOT)/tests/minishell.a

SUITES		:=	$(shell find $(SRC) -name '*.test.c')

################################################################################
### GOALS

RUNNERS		:=	$(SUITES:$(SRC)/%.c=$(BUILD)/runners/%.out)
LOGFILES	:=	$(SUITES:$(SRC)/%.c=$(BUILD)/logfiles/%.log)

################################################################################
### FLAGS

CC			:=	clang

CFLAGS		:=	-Wall								\
				-Wextra								\
				-Wno-unused-command-line-argument	\
				-Werror								\
				-ggdb3								\

CPPFLAGS	:=	-MP -MMD							\
				-I$(SRC)							\
				-I$(INCLUDE)						\
				-I$(ROOT)/src						\
				-I$(ROOT)/include					\
				-I$(ROOT)/libft/include				\

LDFLAGS		:=	-L$(dir $(ARCHIVE)) -l:$(notdir $(ARCHIVE))	\
				-L$(dir $(LIBFT)) -l:$(notdir $(LIBFT))		\
				-lreadline									\

################################################################################
### STANDARD TARGETS

all: clean run
.PHONY: all

run:
	$(MAKE) --jobs=8 $(LOGFILES);
.PHONY: build

report: clean
	-$(MAKE) run;
	find build/logfiles -name '*.log' -exec "cat" "{}" ";";
.PHONY: report

gdb:
	-$(MAKE) run;
	type fzf >&/dev/null && find build/runners -name '*.out'	\
		| fzf													\
		| xargs -i -r bash -c "gdb </dev/tty {}";
.PHONY: gdb

clean:
	rm -rf $(BUILD);
.PHONY: clean

################################################################################
### DIRECTORIES TARGETS

$(sort $(patsubst %/,%,$(dir $(RUNNERS) $(LOGFILES)))):
	mkdir -p $@;

################################################################################
### RUNNERS TARGETS

MKRUNNER	:=	scripts/mkrunner

$(RUNNERS): $(BUILD)/runners/%.out: $(SRC)/%.c | $$(@D)
	$(MKRUNNER) $< | $(CC) $(CFLAGS) $(CPPFLAGS) $< -xc - $(LDFLAGS) -o $@;

################################################################################
### LOGFILES TARGETS

TIMEOUT		:=	timeout --verbose --kill-after=5s 3s
VALGRIND	:=	valgrind --quiet --leak-check=full --show-reachable=yes

$(LOGFILES): $(BUILD)/logfiles/%.log: $(BUILD)/runners/%.out | $$(@D)
	$(TIMEOUT) $(VALGRIND) -- $< >&$@ || ( cat $@ && exit 1 );
