/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array..h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:19:13 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:53:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

/*
** Save a copy of a an array of string
*/

char			**ft_array_strdup(char **array);

/*
** Add a new string to an array
*/

char			**ft_array_add(char **array, char *string);

/*
** Macro to get the size of an array
*/

size_t			ft_array_size(char **array);

/*
** Delete a string from an array
*/

char			**ft_array_del(char **array, char *string);

/*
** Clean an array of string
*/

void			ft_array_clean(char **array);

#endif
