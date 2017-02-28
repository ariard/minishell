/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable..h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 17:20:31 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:55:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTB_H
# define HTB_H

# include "dlist.h"

typedef struct		s_cht
{
	int				capacity;
	int				size;
	int				(*h)(const void *key, int size);
	t_dlist			**head;
}					t_cht;

/*
** Hash a string and return a key
*/

int					ft_hash_string(const void *s, int size);

/*
** Init a chained hash table
*/

void				ft_cht_init(t_cht *htb, int capacity,
		int (*h)(const void *key, int size), void (*destroy)(void *data));

/*
** Destroy a chained hash table
*/

void				ft_cht_destroy(t_cht *htb, void (*destroy)(void *data));

/*
** Check if data already exists in a chained hash table
*/

void				*ft_cht_lookup(const t_cht *htb, void *data,
		int (*match)(const char *key1, const char *key2));

/*
** Insert data in a chained hash table if it doesn't already exist
*/

void				ft_cht_insert(t_cht *htb, void *data, void *key,
		int (*match)(const char *key1, const char *key2));

/*
** Remove data from a chained hash table
*/

void				*ft_cht_remove(t_cht *htb, void *data,
		int (*match)(const char *key1, const char *key2));

#endif
