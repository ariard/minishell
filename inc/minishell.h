/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:50:17 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 14:45:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./../libft/inc/free.h"
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <sys/types.h>
# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>

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


typedef struct		s_screen
{
	int				cursor;
	int				vertical;
	int				left;
	int				amplitude;
	int				start;
	int				edit;
	int				down;
	int				col;
	int				insert;
	char			*save;
}					t_screen;

typedef struct		s_info
{
	t_cht			*sym_tab;
	char			**env;
}					t_info;


t_dlist		**ft_lex_analyze(char *stream);

t_root		*ft_syntax_analyze(t_dlist **list_token);

t_dlist		**ft_lexer(char *stream);

int			ft_isoperand(char *stream);

int			ft_isoperator(char *stream);

t_cht		*ft_gen_symtab(char **env);

t_btree		*ft_ast_insert_sequence(t_root *tree, t_btree *father, t_dlist *operand,
		t_dlist *operator);

t_btree		*ft_ast_insert_cmd(t_root *tree, t_btree *father, t_dlist *operand);

t_btree		*ft_goto_nxt_operand(t_btree *node, t_btree *father);


/*
** Function to process input control 
*/

int			ft_process_input(char c, char *stream, t_screen *screen);

/*
** Functions to execute command according to its operator
*/

int			ft_execute_regular(char *path, t_btree *node, char **env,
		int isinpipe);

int			ft_execute_pipe(char *path, t_btree *node, char **env);

int			ft_redir_out(char *path, t_btree *node, t_btree *father,
		char **env);

int			ft_redir_in(char *path, t_btree *node, t_btree *father,
		char **env);

int			ft_app_redir_out(char *path, t_btree *node, t_btree *father,
		char **env);

/*
** Functions to execute builtin utility
*/

int			ft_builtin(t_btree *node, t_btree *father, char **env);

int			ft_echo(char **arg, char **env);

int			ft_cd(char **arg, char **env);

int			ft_env(char **arg, char **env);

char		**ft_setenv(char *arg, char **env);

int			ft_unsetenv(char **arg, char **env);

char		*ft_builtin_option(char **arg, char *builtin);

int			ft_check_dir(char *path);

/*
** Functions to print errors
*/

int			ft_home_error(void);

int			ft_syntax_error(t_dlist *list_token);

int			ft_semantic_error(char *s);

int			ft_permission_error(char *s, char **env);

int			ft_existence_error(char *cmd, char *path);

/*
** Library functions of termcaps
*/

extern NCURSES_EXPORT(char *) tgoto(const char *cstring, int hpos, int vpos);

extern NCURSES_EXPORT(int) tputs(const char *str, int affcnt, int (*putc)(int));

extern int tgetent(char *bp, const char *name);

extern char *tgetstr(char *name, char **area);

extern int tgetnum(char *name);

/*
** Functions to mainpulate the terminal device driver
*/

struct termios 			*ft_tty_raw(int fd);

int						ft_tty_reset(int fd, struct termios *old_termios);

int						ft_puterm(int c);

int						ft_init_term_data(void);

/*
** Functions to manipulate termcaps library
*/

void					ft_move_left(t_screen *screen);

void					ft_move_right(t_screen *screen);

void					ft_insert_char(char c, t_screen *screen);

void					ft_delete_char(t_screen *screen);

void					ft_next_line(t_screen *screen);

void					ft_prev_line(t_screen *screen);

/*
** Functions to manipulate termcaps library
*/

void					ft_save_home(void);

void					ft_return_home(void);

void					ft_insert(char c);

void					ft_delete(void);

void					ft_cursor_left(void);

void					ft_cursor_right(void);

void					ft_go_next_line(void);

void					ft_go_prev_line(t_screen *screen);

void					ft_go_cursor(int pos, t_screen *screen);

/*
** Macros to extract data from node
*/

int						ft_node_typeis(t_btree *node);

int						ft_node_islast(int size, char *s);

char					*ft_node_nameis(t_btree *node);

char					**ft_node_argis(t_btree *node);

/*
** Macros to detect operator type
*/

int						ft_ispipe(t_btree *father);

int						ft_isregular(t_btree *father);

int						ft_isredir_out(t_btree *father);

int						ft_isredir_in(t_btree *father);

int						ft_isappredir_out(t_btree *father);

/*
** Macros to operate on environnement
*/

char					**ft_grep_env(char **env, char *value);

char					*ft_grep_envdata(char **env, char *value);

/*
**	Macro to control input processing
*/

int						ft_isend(int c, int quote, t_screen *screen);

int						ft_isquote(int c, int quote);

int						ft_isedit(int c, t_screen *screen);

int						ft_iscol(void);

int						ft_isendline(int n, t_screen *screen);

int						ft_isbeginline(int n, t_screen *screen);

int						ft_set_info_screen(char *stream, t_screen *screen);

int						ft_overflow(char *stream, int line , t_screen *screen);

/*
** Read functions to verify struct generation
*/

void					ft_read_entry(t_cht *htb);

void					ft_read_env(char **str);

void					ft_read_list(t_dlist **list);

#endif
