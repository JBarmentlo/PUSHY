/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:12:56 by gregoiretaj       #+#    #+#             */
/*   Updated: 2019/04/17 14:51:48 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <string.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t ft_memccpyn);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_print_memory(void *addr, size_t len);

void			*malloco(size_t size);
void			*calloco(size_t size, size_t n);
void			moult_free(int n, ...);
void			ft_free_doubletab(void **tab);

#endif
