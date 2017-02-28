/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:21:29 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 17:27:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void	*dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t size);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				ft_memdel(void **ap);

void				*ft_memalloc(size_t size);

#endif
