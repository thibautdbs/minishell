# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 23:13:56 by tdubois           #+#    #+#              #
#    Updated: 2022/12/12 14:00:34 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=	sh
MAKEFLAGS   	+=	--no-print-directory		\
					--warn-undefined-variables	\
					--no-builtin-rules			\

DIRDUP			=	mkdir -p $(dir $@)
ENDCOLOR		:=	\\e[0m
MAGENTA			:=	\\e[95m
LIGHTRED		:=	\\e[31m

################################################################################

LIBFT			:=	./.build/libft.a

LIBFTBUILD		:=	./.build/libft/
TESTSBUILD		:=	./.build/tests/

LIBFTSRC		:=	../src/
TESTSSRC		:=	./

INCLUDE			:=	./include ../include/ $(LIBFTSRC)

################################################################################

TESTSSRCS		:=	$(shell fd -g '*.c' '$(TESTSSRC)')
TESTSDEPS		:=	$(TESTSSRCS:$(TESTSSRC)%.c=$(TESTSBUILD)%.d)
TESTSRUNNERS	:=	$(TESTSSRCS:$(TESTSSRC)%.c=$(TESTSBUILD)%.out)
TAPFILES		:=	$(TESTSSRCS:$(TESTSSRC)%.c=$(TESTSBUILD)%.tap)

LIBFTSRCS		:=	$(shell fd -g '*.c' '$(LIBFTSRC)')
LIBFTDEPS		:=	$(LIBFTSRCS:$(LIBFTSRC)%.c=$(LIBFTBUILD)%.d)
LIBFTOBJS		:=	$(LIBFTSRCS:$(LIBFTSRC)%.c=$(LIBFTBUILD)%.o)

################################################################################

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Wno-format -O3 -ggdb3
CPPFLAGS		:=	-MMD -MP $(addprefix -I,$(INCLUDE))
LDFLAGS     	:=	$(addprefix -L,$(dir $(LIBFT)))
LDLIBS      	:=	$(addprefix -l:,$(notdir $(LIBFT)))

################################################################################

all: run show
.PHONY: all

run:
	@echo $(MAGENTA)building $(LIBFT)$(ENDCOLOR)
	@$(MAKE) $(LIBFT)
	@echo $(MAGENTA)building tests$(ENDCOLOR)
	@$(MAKE) tests
	@echo $(MAGENTA)running tests$(ENDCOLOR)
	@$(MAKE) -j tapfiles
.PHONY: run

show:
	@tappy $(TAPFILES)
.PHONY: show

tap:
	@echo $(abspath $(TAPFILES))
.PHONY: tap

################################################################################

tapfiles: $(TAPFILES)
.PHONY: tapfiles

$(TAPFILES): $(TESTSRUNNERS)
	@valgrind	--quiet					\
				--leak-check=full		\
				--show-reachable=yes	\
				$(@:.tap=.out) -v 2>&1	\
		| ./scripts/entapment > $@
.PHONY: $(TAPFILES)

################################################################################

tests: $(TESTSRUNNERS)
.PHONY:tests

$(TESTSBUILD)%.out: $(TESTSSRC)%.c
	$(DIRDUP)
	./scripts/mkrunner $<	\
		| $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -xc - $< $(LDLIBS) -o $@

################################################################################

$(LIBFT): $(LIBFTOBJS)
	$(DIRDUP)
	ar rcs $(LIBFT) $(LIBFTOBJS)

$(LIBFTBUILD)%.o: $(LIBFTSRC)%.c
	$(DIRDUP)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

################################################################################

-include $(TESTSDEPS) $(LIBFTDEPS)

################################################################################

RM	:=	rm -rf

clean:
	@echo $(MAGENTA)cleaning tests$(ENDCOLOR)
	$(RM) .build
.PHONY: clean

fclean: clean
	@echo $(MAGENTA)full cleaning libft$(ENDCOLOR)
.PHONY: fclean

re: fclean all
.PHONY: re
