/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:14:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/16 19:50:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_update_history(t_info *info)
{
	int		fd;
	char	c;
	char	*mask;
	t_dlist	*tmp;

	fd = open("/Users/ariard/.ariard_history", O_WRONLY | O_CREAT);
	tmp = ft_list_last(&info->history);
	c = 10;	
	while (tmp)
	{
		mask = tmp->data;
		if (ft_strlen(mask) > 0)
		{		
			ft_putstr_fd(mask, fd);
			if (tmp->previous)
				ft_putchar_fd(10, fd);	

		}
		tmp = tmp->previous;
	}
	close(fd);
}
