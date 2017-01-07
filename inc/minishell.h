	int				taken_buckets;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:50:17 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 17:11:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./../libft/inc/free.h"
# include <sys/wait.h>
# include <dirent.h>

typedef struct		s_entry
{
	char			*bin;
	char			*path;
	int				perm;
}					t_entry;

typedef struct		s_token
{
	char			*name;
	char			*id;
}					t_token;

typedef struct		s_expr
{
	char			*id1;
	char			*id2;
	char			*id3;
}					t_expr;

t_dlist		**ft_lex_analyze(char *tab);

t_root		*ft_syntax_analyze(t_dlist **list_token);

t_dlist		**ft_lexer(char *tab);

int			ft_isoperand(char *stream);

int			ft_isoperator(char *stream);

t_cht		*ft_gen_symtab(char **env);

int			ft_syntax_error(t_dlist *list_token);

int			ft_semantic_error(char *s);

int			ft_permission_error(char *s, char **env);

t_btree		*ft_ast_insert_sequence(t_root *tree, t_btree *father, t_dlist *operand,
		t_dlist *operator);

t_btree		*ft_ast_insert_cmd(t_root *tree, t_btree *father, t_dlist *operand);

t_btree		*ft_goto_nxt_operand(t_btree *node, t_btree *father);

/*
** Functions to execute command according to its operator
*/

int			ft_execute_regular(char *path, t_btree *node, char **env,
		int isinpipe);

int			ft_execute_pipe(char *path, t_btree *node, char **env);

int			ft_execute_redir_out(char *path, t_btree *node, t_btree *father,
		char **env);

int			ft_execute_redir_in(char *path, t_btree *node, t_btree *father,
		char **env);

/*
** Macros to extract data from node
*/

int			ft_node_typeis(t_btree *node);

int			ft_node_islast(int size, char *s);

char		*ft_node_nameis(t_btree *node);

char		**ft_node_argis(t_btree *node);

/*
** Macros to detect operator type
*/

int			ft_ispipe(t_btree *father);

int			ft_isregular(t_btree *father);

int			ft_isredir_out(t_btree *father);

int			ft_isredir_in(t_btree *father);

/*
** Read functions to verify struct generation
*/

void		ft_read_entry(t_cht *htb);

void		ft_read_env(char **str);

void		ft_read_list(t_dlist **list);

#endif

