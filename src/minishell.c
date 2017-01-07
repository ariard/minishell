/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 22:34:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_process_stream(char *stream, char **env, t_cht *sym_tab)
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
}

int					main(int __unused ac, char __unused **av, char **ev)
{
	char	*stream;
	char	c;
	char	**env;
	t_cht	*sym_tab;
	
	stream = ft_strnew(1024);
	c = '\0';
	env = ft_array_strdup(ev);
//	ft_read_env(env);
	sym_tab = ft_gen_symtab(env);
//	ft_read_entry(sym_tab);
	while (42)
	{
		ft_putstr("ariard-0.1$ ");
		while (c != '\n')
		{
			ft_strncat(stream, &c, 1);
			ft_getchar(0, &c);
		}
		if (ft_strcmp(stream, "exit") == 0)
			break;
		ft_process_stream(stream, env, sym_tab);
		c = '\0';
		ft_bzero(stream, 1024);
	}
	ft_putstr("exit");
	return (0);
}
