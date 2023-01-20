# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.builtins.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:03:36 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/20 17:31:42 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TBLTN			:=	tests/builtins
TBLTN_SRC		:=	$(TBLTN)/src
TBLTN_BUILD		:=	$(TBLTN)/build
TBLTN_SCRIPTS	:=	$(TBLTN)/scripts

################################################################################
### FILES

TBLTN_SUITES :=	$(shell find "$(TBLTN_SRC)" -name '*.test.sh')

################################################################################
### TARGETS

TBLTN_RUNNER	:=	$(TBLTN)/run_bltn
TBLTN_LOGFILES	:=	$(TBLTN_SUITES:$(TBLTN_SRC)/%.sh=$(TBLTN_BUILD)/%.log)

################################################################################
### MAIN RULE

test.builtins: test.builtins.clean $(TBLTN_RUNNER)
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE) $(TBLTN_RUNNER);
	@$(MAKE) -s -k --jobs=8 $(TBLTN_LOGFILES);
.PHONY: test.builtins

test.builtins.log: test.builtins.clean
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE) $(TBLTN_RUNNER);
	-@$(MAKE) -s -k --jobs=8 $(TBLTN_LOGFILES);
	@find $(TBLTN_LOGFILES) -name '*.log' | xargs -r -L1 cat;
.PHONY: test.builtins.log

test.builtins.gdb: export PATH	:=	$(abspath $(TBLTN_SCRIPTS)):$(PATH)

test.builtins.gdb: test.builtins.clean
	@$(MAKE) -s --jobs=8 $(LIBFT) $(ARCHIVE) $(TBLTN_RUNNER);
	@fzf_gdb $(abspath $(TBLTN_RUNNER));
.PHONY: test.builtins.gdb

test.builtins.clean:
	@rm -rf $(TBLTN_BUILD);
	@rm -rf $(TBLTN_RUNNER);
.PHONY: test.builtins.clean

################################################################################
### RUNNER TARGET

$(TBLTN_RUNNER): CFLAGS		:=	-Wall -Wextra -Werror -ggdb3
$(TBLTN_RUNNER): CPPFLAGS	:=  -Iinclude -I$(dir $(LIBFT))/include
$(TBLTN_RUNNER): LDFLAGS	:=	-L$(dir $(ARCHIVE)) -l:$(notdir $(ARCHIVE))	\
								-L$(dir $(LIBFT)) -l:$(notdir $(LIBFT))		\
								-lreadline									\

$(TBLTN_RUNNER): $(TBLTN_RUNNER).c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< $(LDFLAGS) -o $@;

################################################################################
### LOGFILES TARGET

$(TBLTN_LOGFILES): export PATH	:=	$(abspath $(TBLTN_SCRIPTS)):$(PATH)

$(sort $(patsubst %/,%,$(dir $(TBLTN_LOGFILES)))):
	@mkdir -p $@;

$(TBLTN_LOGFILES): $(TBLTN_BUILD)/%.log: $(TBLTN_SRC)/%.sh | $$(@D)
	run_suite $(TBLTN_RUNNER) $< >&$@ || (cat $@ && exit 1);
