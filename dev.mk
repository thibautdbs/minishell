# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dev.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:39:52 by tdubois           #+#    #+#              #
#    Updated: 2023/01/18 13:31:29 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### SRCS AUTOGREP

SRCS	=	$(shell find src -name '*.c')

################################################################################
### TESTS

test: test.unit test.builtins
.PHONY: test

test.unit:
	@$(MAKE) -q $(LIBFT) || $(MAKE) --jobs=8 $(LIBFT);
	@$(MAKE) -q $(ARCHIVE) || $(MAKE) --jobs=8 $(ARCHIVE);
	@$(MAKE) -C ./tests/unit
.PHONY: test.unit

test.builtins:
	@$(MAKE) -q $(LIBFT) || $(MAKE) --jobs=8 $(LIBFT);
	@$(MAKE) -q $(ARCHIVE) || $(MAKE) --jobs=8 $(ARCHIVE);
	@$(MAKE) -C ./tests/builtins
.PHONY: test.builtins

################################################################################
### ARCHIVE (for testing)

ARCHIVE	:=	tests/minishell.a

$(ARCHIVE): CFLAGS		:=	-Wall								\
							-Wextra								\
							-Wno-unused-command-line-argument	\
							-Werror								\
							-ggdb3								\
							-c									\

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS);
