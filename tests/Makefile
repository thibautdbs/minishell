# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/04 17:40:54 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILD			:=	.build

################################################################################
### LIBS

LIBFT			:=	../libft/libft.a
MINISHELL		:=	$(BUILD)/minishell.a

################################################################################
### FILES

SUITES			:=	$(shell find src -name '*.test.c')
RUNNERS			:=	$(SUITES:src/%.c=$(BUILD)/tests/%.out)
TAPFILES		:=	$(SUITES:src/%.c=$(BUILD)/tests/%.tap)

MINISHELL_SRCS	:=	$(shell find ../src -name '*.c')
MINISHELL_OBJS	:=	$(MINISHELL_SRCS:../src/%.c=$(BUILD)/minishell/%.o)
MINISHELL_DEPS	:=	$(MINISHELL_SRCS:../src/%.c=$(BUILD)/minishell/%.d)

################################################################################

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -ggdb3
CPPFLAGS	:=	-MP -MMD -Iinclude -I../include -I../src -I../libft/include
LDFLAGS		:=	-L$(dir $(MINISHELL)) -L$(dir $(LIBFT))
LDLIBS		:=	-l:$(notdir $(MINISHELL)) -l:$(notdir $(LIBFT))

MKRUNNER	:=	./scripts/mkrunner

test:
	@$(ECHO) "$(MAGENTA)Building $(LIBFT)!$(NC)"
	@$(MAKE)  $(LIBFT)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building objects files!$(NC)"
	@$(MAKE) -j $(MINISHELL_OBJS)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building archive!$(NC)"
	@$(MAKE) -j $(MINISHELL)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building runners!$(NC)"
	@$(MAKE) -j runners
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Running tests!$(NC)"
	@$(MAKE) -j tapfiles
	cat $(TAPFILES)
.PHONY: test

################################################################################
### TESTS

runners: $(RUNNERS)
.PHONY: runners

$(RUNNERS):

$(BUILD)/tests/%.test.out: src/%.test.c
	@$(DIRDUP)
	$(MKRUNNER) $<	 													\
		| $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $< -xc - $(LDLIBS) -o $@

tapfiles: $(TAPFILES)

%.test.tap: %.test.out
	@$(DIRDUP)
	-valgrind --leak-check=full --show-reachable=yes -q $< >$@ 2>&1

################################################################################
### LIBFT

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

################################################################################
### MINISHELL


$(MINISHELL): CPPFLAGS	:=	-MP -MMD -I ../include/ -I $(dir $(LIBFT))

$(MINISHELL): $(MINISHELL_OBJS)
	ar rcs $(MINISHELL) $(MINISHELL_OBJS)

$(BUILD)/minishell/%.o: ../src/%.c
	@$(DIRDUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(MINISHELL_DEPS)

################################################################################
### UTILS

SHELL			:=	bash
MAKEFLAGS   	+=	--no-print-directory		\
					--warn-undefined-variables	\
					--no-builtin-rules			\

DIRDUP			=	mkdir -p $(dir $@)
ECHO			:=	echo -e

NC				:=	\\e[0m
MAGENTA			:=	\\e[95m
LIGHTRED		:=	\\e[31m
