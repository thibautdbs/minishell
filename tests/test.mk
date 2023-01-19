# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 16:06:15 by tdubois           #+#    #+#              #
#    Updated: 2023/01/19 19:54:37 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARCHIVE (for testing)

ARCHIVE		:=	tests/minishell.a

A_BUILD		:=	tests/.build

A_OBJS		:=	$(SRCS:%.c=$(A_BUILD)/%.o)
A_DEPS		:=	$(SRCS:%.c=$(A_BUILD)/%.d)

A_CFLAGS	:=	-Wall								\
				-Wextra								\
				-Wno-unused-command-line-argument	\
				-Werror								\
				-ggdb3								\
				-c									\

$(A_OBJS): $(A_BUILD)/%.o: %.c
	mkdir -p $(@D);
	$(CC) $(A_CFLAGS) -c $(CPPFLAGS) $< -o $@;

$(ARCHIVE): $(A_OBJS)
	ar rcs $(ARCHIVE) $(A_OBJS);

-include $(A_DEPS)

################################################################################
### CMDS

T_MODS	:=	$(shell find tests -mindepth 2 -maxdepth 2 -name 'test.*.mk')

-include $(T_MODS)

test: $(notdir $(T_MODS:%.mk=%))
.PHONY: test

test.clean: $(notdir $(T_MODS:%.mk=%.clean))
	@rm -rf tests/.build;
	@rm -rf $(ARCHIVE);
.PHONY: test.clean
