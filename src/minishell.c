/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 14:30:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void			ft_process_stream(char *stream, char **env, t_cht *sym_tab)
  {
  t_dlist			**list_token;
  t_root			*tree;

  tree = NULL;
  list_token = ft_lex_analyze(stream);
  if (list_token)
  {
  tree = ft_syntax_analyze(list_token);		
//		ft_clear_list;
//		if (tree)
//			ft_display_prefix(tree->root);	
}
if (tree)
ft_execute_ast(tree, env, sym_tab);
}*/

static char			*ft_read_input(t_screen *screen)
{
	char			*stream;
	char			c;
	int				quote;

	screen->cursor = 0; 
	screen->vertical = 1;
	stream = ft_strnew(1024);
	quote = 0;
	while (42)
	{
		c = '\0';
		read(0, &c, 1);
		ft_process_input(c, stream, screen);
		quote = ft_isquote(c, quote);
		if (ft_isend(c, quote, screen) == 1 || ft_strcmp(stream, "exit") == 0)
			break;
	}
	ft_putstr("\n\n");
	ft_putstr(stream);
	return (stream);
}

static int			ft_shell(t_info *info)
{
	char			*stream;
	struct termios	*old_termios;
	t_screen		*screen;

	(void)info;	
	screen = ft_memalloc(sizeof(t_screen));
	screen->left = ft_strlen("ariard-1.0$> ");
	while (42)
	{
		old_termios = ft_tty_raw(0);
		tputs("ariard-1.0$> ", 0, &ft_puterm);
		stream = ft_read_input(screen);	
		tputs("\n", 1, &ft_puterm);
		ft_tty_reset(0, old_termios);
		if (ft_strcmp(stream, "exit") == 0)
			break;
	}
	return (0);
}

int					main(int __unused ac, char __unused **av, char **ev)
{
	t_info			*info;

	(void)ev;
	info = ft_memalloc(sizeof(t_info));
	info->env = ft_array_strdup(ev);
	info->sym_tab = ft_gen_symtab(info->env);
	ft_init_term_data();
	ft_shell(info);
	return (0);
}
