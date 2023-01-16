# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.unit.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 15:35:41 by tdubois           #+#    #+#              #
#    Updated: 2023/01/16 15:47:33 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### FILES

SUITES		:=	$(shell find tests -name '*.test.c')

################################################################################
### TARGETS

RUNNERS		:=	$(SUITES:%.c=$(BUILD)/%.out)
TAPFILES	:=	$(SUITES:%.c=$(BUILD)/%.tap)

ARCHIVE		:=	$(BUILD)/minishell.a

################################################################################
### MAIN RULE

test.unit:
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
	@$(ECHO) "$(MAGENTA)Building runners!$(NC)"
	@$(MAKE) -j $(RUNNERS)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Running tests!$(NC)"
	@$(MAKE) -j $(TAPFILES)
	cat $(TAPFILES)
.PHONY: test

################################################################################
### TESTS

$(RUNNERS): CFLAGS		+=	-ggdb3
$(RUNNERS): CPPFLAGS	+=	-I tests -I src
$(RUNNERS): LDFLAGS		+=	-L$(dir $(ARCHIVE))
$(RUNNERS): LDLIBS		:=	-l:$(notdir $(ARCHIVE)) -l:$(notdir $(LIBFT))

$(BUILD)/tests/%.test.out: tests/%.test.c
	@$(DIRDUP)
	-$(MKRUNNER) $< | $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $< -xc - $(LDLIBS) -o $@

%.test.tap: %.test.out
	@$(DIRDUP)
	-valgrind --leak-check=full --show-reachable=yes -q $< >$@ 2>&1

################################################################################
### ARCHIVE

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

$(OBJS): CFLAGS += -ggdb3

################################################################################
### TOOLS

MKRUNNER	:=	./tests/scripts/mkrunner
