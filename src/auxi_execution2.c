/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:57:21 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 16:33:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_fddir(char **arg, t_info *info, int n)
{
	int		fd;
	char	*last;

	if (!arg || !*arg)
		return ;
	while (*(arg + 1))
		arg++;
	last = *arg;
	fd = ft_atoi(last);
	if (n == 0)
		dup2(info->file, fd);
	else if (n == 1)
		dup2(fd, info->file);
	ft_strdel(&last);
	*arg = NULL;
}

int			ft_check_permission(char *path)
{
	int		fd;

	fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	else
		close(fd);
	return (0);
}

int			ft_redir(t_btree *father)
{
	if (!father)
		return (0);
	if (ft_isredir_in(father) || ft_isredir_out(father)
		|| ft_isappredir_out(father))
		return (1);
	return (0);
}
