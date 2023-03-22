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
CFLAGS	+=	-O3
endif

################################################################################
### SOURCE FILES

SRCS		:=	src/builtins/builtin.c\
				src/builtins/builtin_cd.c\
				src/builtins/builtin_echo.c\
				src/builtins/builtin_env.c\
				src/builtins/builtin_exit.c\
				src/builtins/builtin_export.c\
				src/builtins/builtin_pwd.c\
				src/builtins/builtin_unset.c\
				src/builtins/is_builtin.c\
				src/builtins/is_valid_identifier.c\
				src/main.c\
				src/parser/parse.c\
				src/parser/parse_cmd.c\
				src/parser/parse_cmdtree.c\
				src/parser/parse_pipeline.c\
				src/parser/parse_redir.c\
				src/parser/parse_word.c\
				src/prompter/prompt.c\
				src/prompter/prompt_heredoc.c\
				src/prompter/prompt_heredocs.c\
				src/runner/execve.c\
				src/runner/expand/do_word_split.c\
				src/runner/expand/expand.c\
				src/runner/expand/expand_qtd_vars.c\
				src/runner/expand/expand_vars.c\
				src/runner/expand/expand_wildcards.c\
				src/runner/expand/expand_words.c\
				src/runner/expand/pattern_match.c\
				src/runner/get_path.c\
				src/runner/redirect/redirect.c\
				src/runner/redirect/redirect_one_appnd.c\
				src/runner/redirect/redirect_one_heredoc.c\
				src/runner/redirect/redirect_one_infile.c\
				src/runner/redirect/redirect_one_outfile.c\
				src/runner/run.c\
				src/runner/run_cmd.c\
				src/runner/run_pipeline.c\
				src/types/cmd/cmdlst_add_back.c\
				src/types/cmd/cmdlst_del.c\
				src/types/cmd/cmdlst_del_one.c\
				src/types/cmd/cmdlst_last.c\
				src/types/cmd/cmdlst_new.c\
				src/types/cmd/cmdlst_pop_front.c\
				src/types/cmd/cmdlst_size.c\
				src/types/cmd/cmdtree_del.c\
				src/types/cmd/cmdtree_new.c\
				src/types/envlst/envlst_addback.c\
				src/types/envlst/envlst_addfront.c\
				src/types/envlst/envlst_apply.c\
				src/types/envlst/envlst_appnd.c\
				src/types/envlst/envlst_del.c\
				src/types/envlst/envlst_find_var.c\
				src/types/envlst/envlst_get_value.c\
				src/types/envlst/envlst_init.c\
				src/types/envlst/envlst_new.c\
				src/types/envlst/envlst_pop_front.c\
				src/types/envlst/envlst_pop_var.c\
				src/types/envlst/envlst_set.c\
				src/types/envlst/envlst_size.c\
				src/types/envlst/envlst_to_envp.c\
				src/types/envlst/sort_envp.c\
				src/types/redirlst/redirlst_add_back.c\
				src/types/redirlst/redirlst_add_front.c\
				src/types/redirlst/redirlst_del.c\
				src/types/redirlst/redirlst_del_one.c\
				src/types/redirlst/redirlst_last.c\
				src/types/redirlst/redirlst_new.c\
				src/types/redirlst/redirlst_pop_front.c\
				src/types/tok/tok_is_blank.c\
				src/types/tok/tok_is_redir.c\
				src/types/tok/tok_is_redir_or_word.c\
				src/types/tok/tok_is_redir_word_or_lpar.c\
				src/types/tok/tok_skip_blanks.c\
				src/types/tok/tok_skip_blanks_plus.c\
				src/types/tok/tok_type.c\
				src/types/wordlst/wordlst_add_back.c\
				src/types/wordlst/wordlst_at.c\
				src/types/wordlst/wordlst_del.c\
				src/types/wordlst/wordlst_last.c\
				src/types/wordlst/wordlst_new.c\
				src/types/wordlst/wordlst_pop_front.c\
				src/types/wordlst/wordlst_size.c\
				src/types/wordlst/wordlst_to_args.c\
				src/types/wtoklst/wtoklst_add_back.c\
				src/types/wtoklst/wtoklst_add_front.c\
				src/types/wtoklst/wtoklst_concat.c\
				src/types/wtoklst/wtoklst_del.c\
				src/types/wtoklst/wtoklst_del_one.c\
				src/types/wtoklst/wtoklst_extract.c\
				src/types/wtoklst/wtoklst_handle_ast.c\
				src/types/wtoklst/wtoklst_handle_chars.c\
				src/types/wtoklst/wtoklst_handle_dbl_quotes.c\
				src/types/wtoklst/wtoklst_handle_dollar.c\
				src/types/wtoklst/wtoklst_handle_sgl_quotes.c\
				src/types/wtoklst/wtoklst_last.c\
				src/types/wtoklst/wtoklst_new.c\
				src/types/wtoklst/wtoklst_pop_front.c\
				src/types/wtoklst/wtoklst_wildcards2chars.c\
				src/utils/close_all.c\
				src/utils/exit_or_raise.c\
				src/utils/getpid.c\
				src/utils/raise.c\
				src/utils/signal.c\
				src/utils/waitall.c\
				src/utils/waitpid.c\

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
