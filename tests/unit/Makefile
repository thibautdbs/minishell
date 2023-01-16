# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/17 00:41:31 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: run
.PHONY: all

SHELL	:=	/usr/bin/bash
DIRDUP	=	mkdir -p $(@D)

ROOT	:=	$(shell git rev-parse --show-cdup)
BUILD	:=	.build

################################################################################
### LIBFT

LIBFT	:=	$(ROOT)/libft/libft.a

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

################################################################################
### ARCHIVE

SRCS	:=	$(shell find $(ROOT)/src -name '*.c')
OBJS	:=	$(SRCS:$(ROOT)/src/%.c=$(BUILD)/src/%.o)
DEPS	:=	$(OBJS:%.o=%.d)

ARCHIVE	:=	$(BUILD)/minishell.a

$(BUILD)/src/%.o: $(ROOT)/src/%.c
	@$(DIRDUP)
	clang						\
		-Wall					\
		-Wextra					\
		-Wno-unused-command-line-argument \
		-Werror					\
		-ggdb3					\
		-O3						\
		-c						\
		-MP						\
		-MMD					\
		-I$(ROOT)/include		\
		-I$(ROOT)/libft/include	\
		-xc $<					\
		-L$(ROOT)/libft			\
		-l:libft.a				\
		-lreadline				\
		-o$@

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

################################################################################
### RUNNERS

SUITES		:=	$(shell find . -name '*.test.c')

RUNNERS		:=	$(SUITES:%.c=$(BUILD)/runners/%.out)

$(BUILD)/runners/%.test.out: ./%.test.c $(LIBFT) $(ARCHIVE)
	@$(DIRDUP)
	- scripts/mkrunner $< | clang			\
					-Wall					\
					-Wextra					\
					-Wno-unused-command-line-argument \
					-Werror					\
					-ggdb3					\
					-O3						\
					-I./src					\
					-I./include				\
					-I$(ROOT)/src			\
					-I$(ROOT)/include		\
					-I$(ROOT)/libft/include	\
					-xc -					\
					-xc $<					\
					-L$(dir $(ARCHIVE))		\
					-l:$(notdir $(ARCHIVE))	\
					-L$(dir $(LIBFT))		\
					-l:$(notdir $(LIBFT))	\
					-o$@

################################################################################
### TAPFILES

TAPFILES	:=	$(RUNNERS:%.out=%.tap)

$(TAPFILES): MAKEFlAGS += -j

$(BUILD)/runners/%.test.tap: $(BUILD)/runners/%.test.out
	@$(DIRDUP)
	- >&$@ timeout --kill-after=5s 3s valgrind						\
											--quiet					\
											--leak-check=full		\
											--show-reachable=yes	\
											$<

################################################################################
### TEST

run:
	rm -rf $(BUILD)
	$(MAKE) -j $(TAPFILES)
	- 2>/dev/null cat $(TAPFILES)
.PHONY: run
