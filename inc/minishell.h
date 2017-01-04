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
	int				x;
}					t_entry;

typedef struct		s_token
{
	char			*name;
	char			*id;
}					t_token;

t_dlist		*ft_lex_analyze(char *tab);

t_dlist		*ft_lexer(char *tab);

int			ft_isoperand(char *stream);

int			ft_isoperator(char *stream);

t_cht		*ft_gen_symtab(char **env);

void		ft_read_entry(t_cht *htb);

void		ft_read_env(char **str);

void		ft_read_list(t_dlist *list);

#endif

