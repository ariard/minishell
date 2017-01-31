/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:16:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 10:08:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_execute_child_heredoc(char *eof, t_info *info)
{
	char	*file;
	int		fd;

	fd = open("/tmp/heredoc", O_CREAT | O_RDWR, 0644);
	file = ft_extract_file(eof, info->buff_auxi, info);
	ft_putstr_fd(file, fd);
	close(fd);
	fd = open("/tmp/heredoc", O_CREAT | O_RDWR, 0644);
	dup2(fd, 0);
}

void		ft_execute_rm(char *path, char **arg, char **env)
{
	pid_t	status;
	char	*arg_spec[3];

	status = fork();
	arg_spec[0] = "rm";
	arg_spec[1] = "/tmp/heredoc";
	arg_spec[2] = NULL;
	if (status == 0)
		execve(path, arg, env);
	if (status > 0)
	{
		wait(0);
		execve("/bin/rm", arg_spec, env);
	}
}

int			ft_execute_heredoc(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	char	**arg2;
	char	*eof;
	t_btree	*tmp;
	pid_t	status;

	arg = ft_node_argis(node);
	tmp = ft_goto_nxt_operand(node, father);
	eof = ft_node_nameis(tmp);
	arg2 = ft_node_argis(tmp);
	if (ft_builtin(ft_node_nameis(node), arg, info))
		status = -1;
	else
		status = fork();	
	if (status == 0)
	{	
			if (*(arg2 + 1))
			{
				*arg2 = *arg;
				arg = arg2;
				execve(path, arg, info->env);
			}
			else
			{
				ft_execute_child_heredoc(eof, info);
				ft_execute_rm(path, arg, info->env);
			}	
	}
	if (status > 0)
		waitpid(status, 0, WUNTRACED | WCONTINUED);
	info->previous_eof = eof;
	return (1);
}
