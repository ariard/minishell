/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/02/28 15:01:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_process_buffer(char *buffer, t_info *info)
{
	t_dlist			**list_token;
	t_root			*tree;

	tree = NULL;
	list_token = ft_lex_analyze(buffer, info);
	if (list_token)
		tree = ft_syntax_analyze(list_token);
	if (tree)
		ft_execute_ast(tree, info);
	if (list_token)
		ft_list_clear(list_token, &ft_token_free);
	if (tree)
	{
		ft_apply_postfix(tree->root, &free);
		free(tree);
	}
	ft_strdel(&buffer);
	ft_strdel(&info->buff_auxi);
}

static void			ft_init_read(t_info *info, t_screen *screen)
{
	screen->cursor = 0;
	screen->vertical = 1;
	screen->quote = 0;
	info->pipe = 0;
	info->quote = 0;
	info->previous_eof = NULL;
	info->buff_auxi = ft_strnew(1024);
}

static char			*ft_read_input(t_screen *screen, t_info *info)
{
	char			*buffer;
	char			c;

	ft_init_read(info, screen);
	buffer = ft_strnew(1024);
	while (42)
	{
		c = '\0';
		read(0, &c, 1);
		ft_process_input(c, buffer, screen, info);
		if (ft_interrupt(c, buffer, screen))
			break ;
		if (ft_isend(c) == 1)
			break ;
		if (ft_strlen(buffer) >= 1024)
			return (ft_buffer_error());
	}
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
	info->prev_path = NULL;
	info->prev_father = NULL;
	info->prev_node = NULL;
	while (42)
	{
		old_termios = ft_tty_raw(0);
		ft_insert_str("ariard-1.0$> ", screen);
		buffer = ft_read_input(screen, info);
		ft_insert(10);
		ft_tty_reset(0, old_termios);
		if (buffer)
			ft_process_buffer(buffer, info);
	}
	return (0);
}

int					main(int ac, char **av, char **ev)
{
	t_info			*info;

	(void)ac;
	if (isatty(0) == 0)
		return (-1);
	signal(SIGINT, ft_sigint_handler);
	info = ft_memalloc(sizeof(t_info));
	info->env = ft_array_strdup(ev);
	ft_putstr_fd("env youhou", 3);
	info->list_bin = ft_memalloc(sizeof(t_dlist));
	*(info->list_bin) = NULL;
	info->sym_tab = ft_gen_symtab(info);
	ft_putstr_fd("sym tab youhou", 3);
	if (*(info->list_bin))
	{
		ft_insert_cmpsort(info->list_bin, &ft_stralphcmp);
		ft_list_reverse(info->list_bin);
	}
	ft_init_term_data();
	info->av = av;
	ft_shell(info);
	return (0);
}
