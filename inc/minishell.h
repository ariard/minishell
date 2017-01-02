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

void		ft_lex_analyze(char *tab);

void		ft_lexer(char *tab);

int			ft_isoperand(char *stream);

int			ft_isoperator(char *stream);

t_cht		*ft_gen_symtab(char **env);

#endif

