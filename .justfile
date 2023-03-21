[private]
@default:
	just --list --unsorted --list-prefix '‧‧‧‧ '

GREEN	:=	`echo '\e[92m'`
NC		:=	`echo '\e[0m'`

#******************************************************************************#
#** BUILD *********************************************************************#

[private]
alias b	:=	build
[private]
alias r	:=	re

# build project
@build:
	make -j$(nproc) DEBUG=1

# clean and rebuild project
@re:
	make fclean
	just build

#******************************************************************************#
#** TESTS *********************************************************************#

[private]
alias t		:=	test
[private]
alias tu	:=	test-unit
[private]
alias tn	:=	test-norm

# build and run all tests (unit, norm)
@test +TEST="all":
	just test-{{TEST}}
	echo "{{GREEN}}TESTS OK!{{NC}}"

# clean, build and run all tests
@retest +TEST="all":
	make -f .unit.mk fclean
	just test {{TEST}}

[private]
@test-all: test-norm test-unit

[private]
@test-norm:
	norminette src include/minishell | { ! grep Error; }

[private]
@test-unit *ARGS:
	make -f .unit.mk -j$(nproc)
	./scripts/greatest_parallel {{ARGS}} {{absolute_path("./test")}}
