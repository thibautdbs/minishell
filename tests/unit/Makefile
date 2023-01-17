# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/17 15:18:06 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=	/usr/bin/bash

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory 
.DEFAULT_GOAL	:=	all

################################################################################
### TOOLS

RM				:=	rm -rf

MAGENTA			:=	$(shell echo -e "\033[0;35m")
NC				:=	$(shell echo -e "\033[0m")

define log
    $(info $(MAGENTA)$(1)$(NC))
endef

.SECONDEXPANSION:
DIRDUP	=	$$(@D)_dir
%_dir:
	mkdir -p $(@:%_dir=%);

################################################################################
### DIRECTORIES

SRC			:=	src
INCLUDE		:=	include

BUILD		:=	.build

################################################################################
### STANDARD TARGETS

all:
	$(call log,all:)
	$(MAKE) --jobs=8 --output-sync=recurse $(RUNNERS);
.PHONY: all

clean:
	$(call log,clean:)
	$(MAKE) -C $(dir $(LIBFT)) clean;
	$(RM) $(BUILD);
.PHONY: clean

re: fclean all
.PHONY: re

################################################################################
### LIBFT

LIBFT	:=	$(ROOT)/libft/libft.a

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT));

################################################################################
### ARCHIVE

SRCS	:=	$(shell find $(ROOT)/src -name '*.c')
OBJS	:=	$(SRCS:$(ROOT)/src/%.c=$(BUILD)/archive/%.o)
DEPS	:=	$(OBJS:%.o=%.d)

ARCHIVE	:=	$(BUILD)/minishell.a

$(OBJS): CC				:=	clang

$(OBJS): CFLAGS			:=	-Wall								\
							-Wextra								\
							-Wno-unused-command-line-argument	\
							-Werror								\
							-ggdb3								\
							-c									\

$(OBJS): CPPFLAGS		:=	-MP									\
							-MMD								\
							-I$(ROOT)/include					\
							-I$(ROOT)/libft/include				\

$(OBJS): LDFLAGS		:=	-L$(ROOT)/libft -l:libft.a			\
							-lreadline							\

$(BUILD)/src/%.o: $(ROOT)/src/%.c | $(DIRDUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -xc $< $(LDFLAGS) -o $@;

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

################################################################################
### RUNNERS

SUITES		:=	$(shell find src -name '*.test.c')

RUNNERS		:=	$(SUITES:%.c=$(BUILD)/runners/%.out)

$(RUNNERS): CC			:=	clang

$(RUNNERS): CFLAGS		:=	-Wall								\
							-Wextra								\
							-Wno-unused-command-line-argument	\
							-Werror								\
							-ggdb3								\
							-c									\

$(RUNNERS): CPPFLAGS	:=	-MP									\
							-MMD								\
							-I$(ROOT)/include					\
							-I$(ROOT)/libft/include				\

$(RUNNERS): LDFLAGS		:=	-L$(ROOT)/libft -l:libft.a			\
							-lreadline							\

$(BUILD)/runners/%.test.out: ./%.test.c $(LIBFT) $(ARCHIVE) | $(DIRDUP)
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
