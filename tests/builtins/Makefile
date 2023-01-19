# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:03:36 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/20 00:18:08 by tdubois          ###   ########.fr        #
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

test.builtins: $(TBLTN_RUNNER)
	@$(MAKE) -s -k --jobs=8 $(TBLTN_LOGFILES);
.PHONY: test.builtins

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

$(TBLTN_LOGFILES): SHUNIT2	:=	$(TBLTN)/include/shunit2
$(TBLTN_LOGFILES): PATH		:=	$(abspath $(TBLTN_SCRIPTS)):$${PATH}

$(sort $(patsubst %/,%,$(dir $(LOGFILES)))):
	@mkdir -p $@;

$(TBLTN_LOGFILES): $(TBLTN_BUILD)/%.log: $(TBLTN_SRC)/%.sh | $$(@D)
	@PATH="$(PATH)" $(SHUNIT2) $< >&$@ || (cat $@ && exit 1);
