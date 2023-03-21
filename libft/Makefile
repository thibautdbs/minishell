#******************************************************************************#
#** CONFIGURATION *************************************************************#

MAKEFLAGS   	+=	--no-builtin-rules --no-print-directory --output-sync

.SECONDEXPANSION:
.DELETE_ON_ERROR:

#******************************************************************************#
#** GOALS *********************************************************************#

NAME		:=	libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
BUILD		:=	.build
INCLUDE		:=	include

################################################################################
### COMPILATION FLAGS

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-MP -MMD -I$(INCLUDE)

ifdef DEBUG
CFLAGS	+=	-ggdb3
else
CFLAGS	+=	-O1
endif

################################################################################
### SOURCE FILES

#== MEMORY ====================================================================#

SRCS	+=	ft_bzero.c			\
			ft_calloc.c			\
			ft_memset.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memdel.c			\
			ft_memdup.c			\

#== MATHS =====================================================================#

SRCS 	+=	ft_min.c			\
			ft_min_arr.c		\
			ft_max.c			\
			ft_abs.c			\
			ft_count_digits.c	\
			ft_mod.c			\

#== STRINGS ===================================================================#

SRCS	+=	ft_tochar.c			\

SRCS 	+=	ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\

SRCS	+=	ft_atoi.c			\
			ft_atol.c			\
			ft_isint.c			\
			ft_islong.c			\

SRCS	+=	ft_itoa.c			\
			ft_sitoa.c			\
			ft_strtol.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strrev.c			\
			ft_strlen.c			\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strspn.c			\
			ft_strcspn.c		\
			ft_strtok.c			\
			ft_strtok_r.c		\

SRCS	+=	ft_strjoin.c		\
			ft_strjoin_sep.c	\
			ft_strtrim.c		\
			ft_strdup.c			\
			ft_substr.c			\
			ft_split.c			\
			ft_strsdel.c		\

SRCS	+=	ft_search_str.c		\
	
SRCS	+=	ft_strmapi.c		\
			ft_striteri.c		\

SRCS	+=	ft_tolower.c		\
			ft_toupper.c		\

SRCS	+=	ft_strendswith.c	\

#== ARRAYS ====================================================================#

SRCS	+=	ft_mtrx2_new.c		\
			ft_mtrx2_del.c		\

#== IO ========================================================================#

SRCS	+=	ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putstr_rpt_fd.c	\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_puterr.c			\
			ft_puterr_endl.c	\

SRCS	+=	ft_gnl.c			\

################################################################################
### GENERATED FILES

OBJS	:=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS	:=	$(SRCS:%.c=$(BUILD)/%.d)
DIRS	:=	$(shell dirname $(OBJS) | sort -u)

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> PHONY RULES

.PHONY: all clean fclean re

all: $(NAME)
	@:;

clean:
	rm -rf $(BUILD);

fclean:
	rm -rf $(BUILD);
	rm -rf $(NAME);

re: fclean all

#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#>> BUILD RULES

$(NAME): $(OBJS)
	$(INFO)
	ar rcs $@ $(OBJS);

$(DIRS):
	$(INFO)
	mkdir -p $@;

$(OBJS): $(BUILD)/%.o: $(SRC)/%.c | $$(@D)
	$(INFO)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@;

-include $(DEPS)

#******************************************************************************#
#** TOOLS *********************************************************************#

MAGENTA	:=	$(shell echo -e '\033[0;35m')
NC		:=	$(shell echo -e '\033[0m')

INFO	=	$(info $(MAGENTA)Building $@:$(NC))
