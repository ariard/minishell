/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:37:30 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 19:00:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int			test(char **av)
{
	pid_t	father;
	
	father = fork();
	if (father == 0)
		execve("/bin/pwd", av, NULL);
	wait(0);
	return (0);
}

int			main(int ac, char **av)
{
	(void)ac;
	while (42)
	{
		test(av);
		sleep(2);
	}
	return (0);
}
