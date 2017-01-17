/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/17 22:09:39 by ariard           ###   ########.fr       */
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

static char			*ft_read_input(t_screen *screen, t_info *info)
{
	char			*buffer;
	char			*buffquote;
	char			c;

	screen->cursor = 0; 
	screen->vertical = 1;
	buffer = ft_strnew(1024);
	buffquote = ft_strnew(1024);
	screen->quote = 0;
	while (42)
	{
		c = '\0';
		read(0, &c, 1);
		ft_process_input(c, buffer, screen, info);
		screen->quote = ft_isquote(c, buffer, buffquote, screen);
		if (ft_isend(c, buffer, buffquote, screen) == 1 
				|| ft_strcmp(buffer, "exit") == 0)
			break;
	}
	ft_add_history(buffer, info);
	ft_putstr("\n\n");
	ft_putstr(buffer);
	return (buffer);
}

static int			ft_shell(t_info *info)
{
	char			*buffer;
	struct termios	*old_termios;
	t_screen		*screen;

	screen = ft_memalloc(sizeof(t_screen));
	screen->left = ft_strlen("ariard-1.0$> ");
	while (42)
	{
		old_termios = ft_tty_raw(0);
		ft_insert_str("ariard-1.0$> ", screen);
		buffer = ft_read_input(screen, info);
		ft_insert(10);
		ft_tty_reset(0, old_termios);
		if (ft_strcmp(buffer, "exit") == 0)
			break;
	}
	return (0);
}

int					main(int __unused ac, char __unused **av, char **ev)
{
	t_info			*info;

	info = ft_memalloc(sizeof(t_info));
	info->env = ft_array_strdup(ev);
	info->list_bin = ft_memalloc(sizeof(t_dlist));
	*(info->list_bin) = NULL;
	info->sym_tab = ft_gen_symtab(info->env, info->list_bin);
	ft_insert_cmpsort(info->list_bin, &ft_stralphcmp);
	ft_list_reverse(info->list_bin);
	ft_gen_history(info);
	ft_init_term_data();
	ft_shell(info);
	ft_update_history(info);
	return (0);
}
