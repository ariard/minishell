/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:54:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 21:20:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_extract_buff_auxi(char *buffer, t_info *info)
{
	char	*tmp;
	char	*new;

	tmp = buffer;
	new = ft_strnew(1024);
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		tmp++;
		if (*tmp)
			ft_strcpy(new, tmp);
	}
	info->buff_auxi = new;
}	

char		*ft_extract_file(char *eof, char *buffer, t_info *info)
{
	char	*tmp;
	char	*new;
	int		len;
	
	new = ft_strnew(1024);
	tmp = new;
	while (ft_strncmp(buffer, eof, ft_strlen(eof)) != 0)
	{
		*new++ = *buffer;
		*buffer++ = 0;
	}
	*--new = 0;
	len = ft_strlen(eof);
	while (len--)
		*buffer++ = 0;
	info->buff_auxi = buffer;
	return (tmp);
}	

void		ft_add_heredoc(char *buffer, t_info *info)
{
	char	*buf;
	char	*tmp;
	char	c;

	buf = ft_strnew(1024);
	tmp = buffer;
	c = '\0';
	while (*(tmp + 1))
		tmp++;
	tmp--;
	while (*(tmp - 1) && *(tmp - 1) != '<')
		tmp--;
	while (*tmp && ft_isspace(*tmp) == 1)
		tmp++;
	while (*tmp && ft_isalnum(*tmp) == 1)
	{
		c = *tmp;
		ft_strncat(buf, &c, 1);
		tmp++;
	}
	ft_list_push_back(info->delim, ft_strdup(buf), NULL);
	info->heredocsize++;
	ft_strdel(&buf);
}

int			ft_execute_heredoc(char *path, t_btree *node, t_btree *father,
		char **env, t_info *info)
{
	char	**arg;
	char	**arg2;
	char	*eof;
	char	*file;
	int		fd;
	t_btree	*tmp;
	pid_t	status;

	arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
	{	
		if (!*(arg + 1))
		{
			tmp = ft_goto_nxt_operand(node, father);
			eof = ft_node_nameis(tmp);
			arg2 = ft_node_argis(tmp);	
			if (*(arg2 + 1))
			{
				*arg2 = *arg;
				arg = arg2;
			}
			else
			{
				fd = open("/tmp/heredoc", O_CREAT | O_RDWR, 0644);
				file = ft_extract_file(eof, info->buff_auxi, info);
				ft_putstr_fd(file, fd);
				close(fd);
				fd = open("/tmp/heredoc", O_CREAT | O_RDWR, 0644);
				dup2(fd, 0);
			}
			execve(path, arg, env);
		}
	}
	if (status > 0)
		wait(0);
	return (1);
}
