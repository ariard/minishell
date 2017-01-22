/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 17:06:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_process_buffer(char *buffer, t_info *info) 
{
	t_dlist			**list_token;
	t_root			*tree;

	tree = NULL;
	list_token = ft_lex_analyze(buffer);
	if (list_token)
	{
		tree = ft_syntax_analyze(list_token);
//		if (tree)
//			ft_display_prefix(tree->root);
	if (tree)
		ft_execute_ast(tree, info); 
	}
}

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
	info->heredoc = 0;
	info->heredocsize = 0;
	info->previous_eof = NULL;
	info->buff_auxi = ft_strnew(1024);
	while (42)
	{
		c = '\0';
		read(0, &c, 1);
		ft_process_input(c, buffer, screen, info);
		screen->quote = ft_isquote(c, buffer, buffquote, screen);
		if (ft_endheredoc(c))
			if (ft_isinheredoc(buffer, info))
				ft_add_heredoc(buffer, info);
		if (c == 13)
			if (ft_isendheredoc(buffer, info) == 1)
			{
				ft_strcat(buffquote, buffer);
				ft_bzero(buffer, 1024);
				ft_strcpy(buffer, buffquote);
			}
		if (ft_isend(c, buffer, buffquote, screen, info) == 1)
			break;
	}	
	ft_extract_buff_auxi(buffer, info);
	ft_add_history(buffer, info);
	return (buffer);
}

static int			ft_shell(t_info *info)
{
	char			*buffer;
	struct termios	*old_termios;
	t_screen		*screen;

	screen = ft_memalloc(sizeof(t_screen));
	info->delim = ft_memalloc(sizeof(t_dlist));
	*(info->delim) = NULL;
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
		ft_process_buffer(buffer, info);
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
