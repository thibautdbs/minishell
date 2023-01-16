# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.builtins.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 14:03:36 by ffeaugas          #+#    #+#              #
#    Updated: 2023/01/16 17:11:29 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### FILES

BUILTINS_SUITES :=	$(shell find test_builtins -name '*.test.sh')

################################################################################
### TARGETS

BUILTINS_RUNNER_SRC	:=	test_builtins/main.c
BUILTINS_RUNNER		:=	$(BUILD)/tests.builtins/runner
BUILTINS_TAPFILES	:=	$(BUILTINS_SUITES:test_builtins/%.test.sh=$(BUILD)/tests.builtins/%.test.tap)

ARCHIVE		:=	$(BUILD)/minishell.a

################################################################################
### MAIN RULE

test.builtins:
	@$(MAKE) fclean
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building $(LIBFT)!$(NC)"
	@$(MAKE)  $(LIBFT)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building objects files!$(NC)"
	@$(MAKE) -j $(OBJS)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building archive!$(NC)"
	@$(MAKE) -j $(ARCHIVE)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building runner!$(NC)"
	@$(MAKE) $(BUILTINS_RUNNER)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Running tests!$(NC)"
	@$(MAKE) -j $(BUILTINS_TAPFILES)
	cat $(BUILTINS_TAPFILES)
.PHONY: test

################################################################################
### TESTS

$(BUILTINS_RUNNER): CFLAGS		+=	-ggdb3
$(BUILTINS_RUNNER): CPPFLAGS	+=	-I tests -I src
$(BUILTINS_RUNNER): LDFLAGS		+=	-L$(dir $(ARCHIVE))
$(BUILTINS_RUNNER): LDLIBS		:=	-l:$(notdir $(ARCHIVE)) -l:$(notdir $(LIBFT))

$(BUILTINS_RUNNER):
	@$(DIRDUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(BUILTINS_RUNNER_SRC) $(LDLIBS) -o $@

$(BUILD)/tests.builtins/%.test.tap: test_builtins/%.test.sh
	@$(DIRDUP)
	-bash $< $(BUILTINS_RUNNER) >$@ 2>&1

################################################################################
### ARCHIVE

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

$(OBJS): CFLAGS += -ggdb3
