/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:29:13 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 19:40:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

int					ft_putchar(char c);

int					ft_putstr(char const *s);

int					ft_putstrn(char const *s, int n);

void				ft_putendl(char const *s);

void				ft_putnbr(long long int n);

void				ft_putunsnbr(unsigned long long n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

int					ft_putwchar(wchar_t w);

int					ft_putwstr(wchar_t *w);

#endif
