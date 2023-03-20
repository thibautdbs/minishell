[private]
@default:
	just --list --list-prefix '‧‧‧‧ '

#******************************************************************************#
#** BUILD *********************************************************************#

@build:
	make -j$(nproc) DEBUG=1

@re:
	make fclean
	just build

#******************************************************************************#
#** TESTS *********************************************************************#

@test +TEST="all":
	just test-{{TEST}}

@retest +TEST="all":
	make -f .unit.mk fclean
	just test-{{TEST}}

[private]
@test-all: test-norm test-unit

[private]
@test-norm:
	norminette src include/minishell | { ! grep Error; } && echo "OK!";

[private]
@test-unit *ARGS:
	make -f .unit.mk -j$(nproc)
	./scripts/greatest_parallel {{ARGS}} {{absolute_path("./test")}}
