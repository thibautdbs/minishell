# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 10:40:50 by tdubois           #+#    #+#              #
#    Updated: 2022/12/26 23:39:45 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ##############################################################################
# ## VARS                                                                      #
# ##############################################################################

################################################################################
### TARGET

NAME		:=	libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
BUILD		:=	build
INCLUDE		:=	include

################################################################################
### FLAGS

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -O3
CPPFLAGS	:=	-MMD -MP -I $(INCLUDE)

################################################################################
### FILES

### Memory

SRCS	+=	ft_bzero.c			\
			ft_calloc.c			\
			ft_memset.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memdel.c			\
			ft_memdup.c			\

### Maths

SRCS 	+=	ft_min.c			\
			ft_min_arr.c		\
			ft_max.c			\
			ft_isneg.c			\
			ft_count_digits.c	\
			ft_mod.c			\

### Strings

SRCS	+=	ft_tochar.c			\

SRCS 	+=	ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\

SRCS	+=	ft_atoi.c			\
			ft_atoidup.c		\
			ft_isint.c			\

SRCS	+=	ft_itoa.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
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
			ft_strtrim.c		\
			ft_strdup.c			\
			ft_strndup.c		\
			ft_substr.c			\
			ft_split.c			\

SRCS	+=	ft_search_str.c		\
	
SRCS	+=	ft_strmapi.c		\
			ft_striteri.c		\

SRCS	+=	ft_tolower.c		\
			ft_toupper.c		\

SRCS	+=	ft_strendswith.c	\

### ARRAYS

SRCS	+=	ft_indexof.c		\

SRCS	+=	ft_mtrx2_new.c		\
			ft_mtrx2_del.c		\

### IO

SRCS	+=	ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_puterr.c			\
			ft_puterr_endl.c	\

SRCS	+=	ft_gnl.c			\

### Linked lists

SRCS 	+=	ft_lstnew.c			\
			ft_lstnew_int.c		\
			ft_lstpush.c		\
			ft_lstload.c		\
			ft_lstflat.c		\

SRCS	+=	ft_lstadd_front.c	\
			ft_lstadd_back.c	\
			ft_lstpop.c			\
			ft_lstdelone.c		\
			ft_lstclear.c		\

SRCS	+=	ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstat.c			\
			ft_lstindex.c		\
			ft_lstuniq.c		\

SRCS	+=	ft_lstiter.c		\
			ft_lstmap.c			\

SRCS	+=	ft_lstget_int.c		\

SRCS	+=	ft_lstreadlines.c	\

################################################################################

OBJS	:=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS	:=	$(SRCS:%.c=$(BUILD)/%.d)

# ##############################################################################
# ## RULES                                                                     #
# ##############################################################################

################################################################################
### DEFAULT

all:
	@$(MAKE) $(OBJS) -j
	@$(MAKE) $(NAME)
.PHONY: all

################################################################################
### LIBFT

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(BUILD)/%.o: $(SRC)/%.c
	@$(DIRDUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

################################################################################

test:
	@$(MAKE) -C ./tests
.PHONY: test

################################################################################

-include $(DEPS)

# ##############################################################################
# ## UTILS                                                                     #
# ##############################################################################

clean:
	$(RM) -r $(BUILD)
.PHONY: clean

fclean: clean
	$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################

SHELL		:=	sh
MAKEFLAGS   +=	--no-print-directory		\
				--warn-undefined-variables	\
				--no-builtin-rules			\

RM			:=	rm -f
DIRDUP		=	mkdir -p $(@D)

ifeq (DEBUG,1)
	CFLAGS	+=	-ggdb3
endif
