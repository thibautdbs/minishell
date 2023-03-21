#******************************************************************************#
#** CONFIGURATION *************************************************************#

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --output-sync

.SECONDEXPANSION:
.DELETE_ON_ERROR:

#******************************************************************************#
#** GOALS *********************************************************************#

NAME		:=	test
LIBFT		:=	libft/libft.a

################################################################################
### DIRECTORIES

SRC			:=	src tests
INCLUDE		:=	$(SRC) include
BUILD		:=	.build-unit

################################################################################
### COMPILATION FLAGS

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -ggdb3 			\
				-Wno-unused-command-line-argument		\
				-Xlinker --allow-multiple-definition
CPPFLAGS	=	-MP -MMD $(addprefix -I,$(INCLUDE)) -I$(dir $(LIBFT))/include
LDFLAGS     =	-L$(dir $(LIBFT)) -lft -lreadline

################################################################################
### SOURCE FILES

MAIN		=	tests/main.gen.c

SRCS		:=	$(MAIN) $(shell fd -g '*.c' -E 'main.gen.c' $(SRC))

################################################################################
### GENERATED FILES

OBJS		=	$(SRCS:%.c=$(BUILD)/%.o) 
DEPS		=	$(SRCS:%.c=$(BUILD)/%.d)
DIRS		=	$(shell dirname $(OBJS) | sort -u)

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> PHONY RULES

.PHONY: all bonus libft clean fclean re

all: libft $(NAME)

libft:
	@$(MAKE) -C $(dir $(LIBFT))

fclean::
	$(MAKE) -C $(dir $(LIBFT)) fclean
	rm -rf $(BUILD)
	rm -rf $(NAME)

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> BUILD RULES

$(NAME): $(OBJS)
	$(INFO)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(MAIN): $(filter-out $(MAIN), $(SRCS))
	./scripts/greatest_mkrunner $(SRCS) > $@

$(DIRS):
	$(INFO)
	mkdir -p $@

$(OBJS): $(BUILD)/%.o: %.c | $$(@D)
	$(INFO)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

-include $(DEPS)

#******************************************************************************#
#** TOOLS *********************************************************************#

MAGENTA	:=	$(shell echo -e '\033[0;35m')
NC		:=	$(shell echo -e '\033[0m')

INFO	=	$(info $(MAGENTA)Building $@:$(NC))
