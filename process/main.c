/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:37:30 by ariard            #+#    #+#             */
/*   Updated: 2017/01/02 23:10:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int			main(int ac, char **av)
{
	pid_t	father;
	int		qdeux;

	(void)ac;
	(void)av;
	father = fork();
	qdeux = 5;
	if (father > 0)
	{
		while (42)
		{
			wait(0);
			printf("hello world !\n");
		}
	}
	if (father == 0)
	{
		while (qdeux--)
		{
			sleep(2);
			printf("coucou\n");
		}
	}
	return (0);
}
