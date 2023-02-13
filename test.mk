# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 16:06:15 by tdubois           #+#    #+#              #
#    Updated: 2023/02/13 15:16:54 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export PATH	:=	$(abspath ./scripts):$(PATH)

test: test.unit test.norm
.PHONY: test

################################################################################
### TOBJS (OBJS with debug informations).

TOBJS				:=	$(OBJS:%.o=%.dbg.o)
TDEPS				:=	$(OBJS:%.o=%.dbg.d)
-include $(TDEPS)

$(TOBJS): CFLAGS	:=	-Wall -Wextra -Werror -ggdb3

$(TOBJS): $(BUILD)/%.dbg.o: %.c | $$(@D)
	$(LOG_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@;

################################################################################
### TEST.UNIT (run unit tests from tests/unit folder.)

UNIT_RUNNER	:=	tests/unit/run_tests

UNIT_SRCS	:=	$(shell fd -g '*.c' tests/unit)
UNIT_OBJS	:=	$(UNIT_SRCS:%.c=$(BUILD)/%.o)
UNIT_DEPS	:=	$(UNIT_SRCS:%.c=$(BUILD)/%.d)
-include $(UNIT_DEPS)

$(UNIT_OBJS):	CFLAGS		:=	-Wall -Wextra -Werror -ggdb3
$(UNIT_OBJS):	CPPFLAGS	+=	-I$(SRC)

$(UNIT_RUNNER): LDFLAGS		+=	-Xlinker --allow-multiple-definition
	
$(sort $(shell dirname $(UNIT_OBJS))):
	$(LOG_TARGET)
	mkdir -p $@;

$(UNIT_RUNNER): $(TOBJS) $(UNIT_OBJS)
	$(LOG_TARGET)
	greatest_mkrunner $(UNIT_SRCS) |\
		$(CC) -I$(INCLUDE) $(UNIT_OBJS) $(TOBJS) -xc - $(LDFLAGS) -o $@;

test.unit.build: $(LIBFT) $(UNIT_RUNNER)
	@:;
.PHONY: test.unit.build

test.unit:
	@$(MAKE) -j$(shell nproc) test.unit.build
	@greatest_parallel $(UNIT_RUNNER);
.PHONY: test.unit

test.unit.log:
	@$(MAKE) -j$(shell nproc) test.unit.build
	@greatest_parallel -v $(UNIT_RUNNER);
.PHONY: test.unit.log

clean::
	rm -rf $(UNIT_RUNNER);

################################################################################
### TEST.EXPAND

EXPAND_RUNNER	:=	tests/expand/expand
EXPAND_SRCS		:=	tests/expand/expand.c
EXPAND_OBJS		:=	$(EXPAND_SRCS:%.c=$(BUILD)/%.o)
EXPAND_DEPS		:=	$(EXPAND_SRCS:%.c=$(BUILD)/%.d)
-include $(EXPAND_DEPS)

$(EXPAND_OBJS):	CFLAGS		:=	-Wall -Wextra -Werror -ggdb3
$(EXPAND_OBJS):	CPPFLAGS	+=	-I$(SRC)

$(UNIT_RUNNER): LDFLAGS		+=	-Xlinker --allow-multiple-definition

$(sort $(shell dirname $(EXPAND_OBJS))):
	$(LOG_TARGET)
	mkdir -p $@;

$(EXPAND_RUNNER): $(TOBJS) $(EXPAND_OBJS)
	$(LOG_TARGET)
	$(CC) $(EXPAND_OBJS) $(TOBJS) $(LDFLAGS) -o $@;

test.expand:
.PHONY: test.expand

test.expand.build: $(LIBFT) $(EXPAND_RUNNER)
	@:;
.PHONY: test.expand.build

test.expand:
	@$(MAKE) -j$(shell nproc) test.expand.build
	@shunit_parallel $(shell find tests/expand -name '*.test.sh');
.PHONY: test.unit

test.expand.log:
	@$(MAKE) -j$(shell nproc) test.expand.build
	@shunit_parallel -v $(shell find tests/expand -name '*.test.sh');
.PHONY: test.unit.log

clean::
	rm -rf $(EXPAND_RUNNER);

################################################################################
### TEST.NORM

test.norm:
	@norminette $(SRC) $(INCLUDE)/minishell | { ! grep Error; };
.PHONY: test.norm
