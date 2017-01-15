/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:44:07 by ariard            #+#    #+#             */
/*   Updated: 2017/01/07 17:21:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

size_t				ft_intlen(long long int d);

size_t				ft_unsintlen(unsigned long long int d);

int					ft_atoi(const char *str);

int					ft_atoi_base(char *s, size_t size_base);

char				*ft_itoa(int n);

char				*ft_itoa_base(long long int nb, size_t size_base); 

int					ft_recursive_power(int nb, int power);

int					ft_itoacmp(const char *str1, const char *str2);

#endif
