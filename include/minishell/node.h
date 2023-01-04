typedef enum e_node_type
{
	PIPE,
	EXECVE,
	BUILTIN,
	AND,
	OR
}	t_node_type;

typedef struct s_node
{
	t_node_type		type;
	t_node			*left;
	t_node			*right;
	t_token			*tokens;
}	t_node;

t_node *parse(t_token *toks)
{
	return (parse(*toks.next))
}
