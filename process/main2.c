/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:10:41 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 18:40:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <strings.h>

int			main(int __unused ac, char __unused **av, char **ev)
{
	printf("%lu\n", sizeof(char));
	while (*ev)
		printf("%s\n", *ev++);
	return (0);
}
