/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/10 23:28:14 by ariard           ###   ########.fr       */
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

int					main(int __unused ac, char __unused **av, char __unused **ev)
{
	char			*stream;
	char			c;
	struct termios	*old_termios;

	ft_init_term_data();
	old_termios = ft_tty_raw(0);
	stream = ft_strnew(1024);
	c = '\0';
	while (42)
	{
		tputs("ariard-1.0$> ", 1, &ft_puterm);
		read(0, &c, 1);
		if (c == '\033')
		{
			read(0, &c, 1);
			if (c == '[')
				read(0, &c, 1);
		}
		ft_putchar(c);
		ft_putchar(10);
		if (c == 'e')
			break;
	}
	ft_tty_reset(0, old_termios);
	return (0);
}
