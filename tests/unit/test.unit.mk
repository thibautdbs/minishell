# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.unit.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/02/03 13:16:01 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TUNIT_SRC		:=	tests/unit/src
TUNIT_INCLUDE	:=	tests/unit/include
TUNIT_BUILD		:=	tests/unit/build

################################################################################
### FILES

TUNIT_SUITES	:=	$(shell find $(TUNIT_SRC) -name '*.test.c')

################################################################################
### GOALS

TUNIT_MAINS		:=	$(TUNIT_SUITES:$(TUNIT_SRC)/%.c=$(TUNIT_BUILD)/%.main.c)
TUNIT_RUNNERS	:=	$(TUNIT_SUITES:$(TUNIT_SRC)/%.c=$(TUNIT_BUILD)/%.out)
TUNIT_LOGFILES	:=	$(TUNIT_SUITES:$(TUNIT_SRC)/%.c=$(TUNIT_BUILD)/%.log)

################################################################################
### CMDS

test.unit: test.unit.clean
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE);
	@$(MAKE) -s -k --jobs=8 $(TUNIT_LOGFILES);
.PHONY: test.unit

test.unit.log: test.unit.clean
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE);
	@-$(MAKE) -s -k --jobs=8 $(TUNIT_LOGFILES);
	@find $(TUNIT_BUILD) -name '*.log' | xargs -r -L1 cat;
.PHONY: test.unit.log

test.unit.gdb: test.unit.clean
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE);
	@-$(MAKE) -s -k --jobs=8 $(TUNIT_RUNNERS);
	@tests/unit/scripts/fzf_gdb;
.PHONY: test.unit.gdb

test.unit.clean:
	@rm -rf $(TUNIT_BUILD);
.PHONY: test.unit.clean

################################################################################
### DIRECTORIES TARGETS

$(sort $(patsubst $(TUNIT_SRC)/%/,$(TUNIT_BUILD)/%,$(dir $(TUNIT_SUITES)))):
	mkdir -p $@;

################################################################################
### MAINS TARGETS

$(TUNIT_MAINS): MKRUNNER	:=	tests/unit/scripts/mkrunner

$(TUNIT_MAINS): $(TUNIT_BUILD)/%.main.c: $(TUNIT_SRC)/%.c | $$(@D)
	$(MKRUNNER) $< >$@;

################################################################################
### RUNNERS TARGETS

$(TUNIT_RUNNERS): CFLAGS	:=	-Wall										\
								-Wextra										\
								-Wno-unused-command-line-argument			\
								-Werror										\
								-ggdb3										\

$(TUNIT_RUNNERS): CPPFLAGS	:=	-MP -MMD									\
								-I$(SRC)									\
								-I$(INCLUDE)								\
								-I$(TUNIT_SRC)								\
								-I$(TUNIT_INCLUDE)							\
								-I$(dir $(LIBFT))/include					\

$(TUNIT_RUNNERS): LDFLAGS	:=	-L$(dir $(ARCHIVE)) -l:$(notdir $(ARCHIVE))	\
								-L$(dir $(LIBFT)) -l:$(notdir $(LIBFT))		\
								-lreadline									\

$(TUNIT_RUNNERS): $(TUNIT_BUILD)/%.out: $(TUNIT_SRC)/%.c $(TUNIT_BUILD)/%.main.c | $$(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(@:%.out=%.main.c) $< $(LDFLAGS) -o $@;

################################################################################
### LOGFILES TARGETS

$(TUNIT_LOGFILES): TIMEOUT	:=	timeout						\
									--verbose				\
									--kill-after=5s			\
									3s						\

$(TUNIT_LOGFILES): VALGRIND	:=	valgrind					\
									--quiet					\
									--leak-check=full		\
									--show-reachable=yes	\

$(TUNIT_LOGFILES): $(TUNIT_BUILD)/%.log: $(TUNIT_BUILD)/%.out | $$(@D)
	$(TIMEOUT) $(VALGRIND) -- $< >&$@ || ( cat $@ && exit 1 );
