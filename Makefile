#******************************************************************************#
#** CONFIGURATION *************************************************************#

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --output-sync

.SECONDEXPANSION:
.DELETE_ON_ERROR:

#******************************************************************************#
#** GOALS *********************************************************************#

NAME		:=	minishell
LIBFT		:=	libft/libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
INCLUDE		:=	include
BUILD		:=	.build

################################################################################
### COMPILATION FLAGS

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-MP -MMD -I$(INCLUDE) -I$(dir $(LIBFT))/include
LDFLAGS     =	-L$(dir $(LIBFT)) -lft -lreadline

ifdef DEBUG
CFLAGS	+=	-ggdb3
else
CFLAGS	+=	-Ofast
endif

################################################################################
### SOURCE FILES

SRCS		:=	$(shell fd -g '*.c' src)

################################################################################
### GENERATED FILES

OBJS		=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS		=	$(SRCS:%.c=$(BUILD)/%.d)
DIRS		=	$(shell dirname $(OBJS) | sort -u)

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> PHONY RULES

.PHONY: all bonus libft clean fclean re

all: libft $(NAME)

bonus: all

libft:
	@$(MAKE) -C $(dir $(LIBFT))

clean::
	$(MAKE) -C $(dir $(LIBFT)) clean
	rm -rf $(BUILD)

fclean:: clean
	$(MAKE) -C $(dir $(LIBFT)) fclean
	rm -rf $(NAME)

re: fclean all

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> BUILD RULES

$(NAME): $(OBJS)
	$(INFO)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

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

-include test.mk
