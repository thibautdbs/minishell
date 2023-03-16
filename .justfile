[private]
@default:
	just --list --list-prefix '‧‧‧‧ '

#******************************************************************************#
#** BUILD *********************************************************************#

@build:
	make -j$(nproc)

@re:
	make fclean
	just build

#******************************************************************************#
#** TESTS *********************************************************************#

@test TEST="all":
	just test-{{TEST}}

[private]
@test-all: test-norm

[private]
@test-norm:
	norminette src include/minishell | { ! grep Error; } && echo "OK!";
