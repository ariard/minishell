/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:20:36 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 22:48:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_process_stream(char *stream)
{
	t_dlist			**list_token;

	list_token = ft_lex_analyze(stream);
	ft_read_list(list_token);
	if (list_token)
		ft_syntax_analyze(list_token);		

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
	sym_tab = ft_gen_symtab(env);
	while (42)
	{
		ft_putstr("ariard-0.1$ ");
		while (c != '\n')
		{
			ft_strncat(stream, &c, 1);
			ft_getchar(0, &c);
		}
		if (ft_strcmp(stream, "exit") == 0)
		{
			ft_putstr("exit");
			break;
		}
		ft_process_stream(stream);
		c = '\0';
		ft_bzero(stream, 1024);
	}
	return (0);
}
