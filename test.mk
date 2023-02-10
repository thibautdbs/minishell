# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 16:06:15 by tdubois           #+#    #+#              #
#    Updated: 2023/02/10 17:53:19 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test: test.unit test.builtins test.expansions test.norm
.PHONY: test

################################################################################
### TOBJS (OBJS with debug informations).

TOBJS				:=	$(OBJS:$(BUILD)/%.o=$(BUILD)/tests/%.o)
TDEPS				:=	$(OBJS:$(BUILD)/%.o=$(BUILD)/tests/%.d)
-include $(TDEPS)

$(TOBJS): CFLAGS	:=	-Wall -Wextra -Werror -ggdb3

$(TOBJS): $(BUILD)/tests/%.o: %.c | $$(@D)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@;

################################################################################
### TEST.UNIT (run unit tests from tests/unit folder.)

UNIT_RUNNER	:=	tests/unit/run_tests

UNIT_SRCS	:=	$(shell find tests/unit -name '*.c')
UNIT_OBJS	:=	$(UNIT_SRCS:%.c=$(BUILD)/%.o)
UNIT_DEPS	:=	$(UNIT_SRCS:%.c=$(BUILD)/%.d)
-include $(UNIT_DEPS)

$(UNIT_OBJS):	CFLAGS		:=	-Wall -Wextra -Werror -ggdb3
$(UNIT_OBJS):	CPPFLAGS	:=	-Itests/unit -I$(SRC)

$(UNIT_RUNNER): LDFLAGS	+=	-Xlinker --allow-multiple-definition

$(UNIT_RUNNER): $(LIBFT) $(TOBJS) $(UNIT_OBJS)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(UNIT_OBJS) $(OBJS) $(LDFLAGS) -o $@;

test.unit:
	@$(MAKE) --jobs=8 $(UNIT_RUNNER);
	@./scripts/greatest_parallel $(UNIT_RUNNER);
.PHONY: test.unit

clean::
	rm -rf $(UNIT_RUNNER);

################################################################################
### TEST.NORM

test.norm:
	@norminette $(SRC) $(INCLUDE)/minishell | { ! grep Error; };
.PHONY: test.norm
