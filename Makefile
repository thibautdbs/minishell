# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:37:10 by tdubois           #+#    #+#              #
#    Updated: 2023/01/05 09:23:33 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ##############################################################################
# ## VARS                                                                      #
# ##############################################################################

################################################################################
### TARGETS

NAME		:=	minishell

LIBFT		:=	libft/libft.a

################################################################################
### DIRECTORIES

SRC			:=	src
BUILD		:=	.build
INCLUDE		:=	include

################################################################################
### FLAGS

CC			:=	clang
CFLAGS		:=	-Wall -Werror -Wextra -O3
CPPFLAGS	:=	-MMD -MP -I $(INCLUDE) -I $(dir $(LIBFT))/include
LDFLAGS     :=	-L$(dir $(LIBFT))
LDLIBS		:=	-l:$(notdir $(LIBFT))

################################################################################
### FILES

SRCS		:=

OBJS		=	$(SRCS:%.c=$(BUILD)/%.o)
DEPS		=	$(SRCS:%.c=$(BUILD)/%.d)
	
# ##############################################################################
# ## RULES                                                                     #
# ##############################################################################

all:
	@$(ECHO) "$(MAGENTA)Building $(LIBFT)!$(NC)"
	@$(MAKE)  $(LIBFT)
	@$(ECHO) "$(MAGENTA)Building objects files!$(NC)"
	@$(MAKE) -j $(OBJS)
	@$(ECHO)
	@$(ECHO) "$(MAGENTA)Building $(NAME)!$(NC)"
	@$(MAKE) -j $(NAME)
.PHONY: all

################################################################################
### minishell

$(NAME): $(OBJS)
	@$(DIRDUP)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(BUILD)/%.o: %.c
	@$(DIRDUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

################################################################################
### libft

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

-include $(DEPS)

# ##############################################################################
# ## UTILS                                                                     #
# ##############################################################################

################################################################################
### RULES

clean:
	@$(ECHO) "$(MAGENTA)removing build files!$(NC)"
	$(MAKE) -C $(dir $(LIBFT)) clean
	$(RM) -r $(BUILD)
.PHONY: clean

fclean:
	@$(ECHO) "$(MAGENTA)cleaning everything!$(NC)"
	$(MAKE) -C $(dir $(LIBFT)) fclean
	$(RM) -r $(BUILD)
	$(RM) $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

################################################################################
### ALIASES

RM			:=	rm -f
ECHO		:=	echo -e
DIRDUP		 =	mkdir -p $(@D)

################################################################################
### VARS

SHELL		:=	/bin/bash
MAKEFLAGS	:=	--no-builtin-rules			\
				--no-print-directory		\

NC			:=	\\e[0m
MAGENTA		:=	\\e[95m

-include dev.mk test.mk
