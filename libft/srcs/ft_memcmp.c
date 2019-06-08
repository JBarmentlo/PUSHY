/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:37:44 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 15:37:44 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	if (n == 0)
		return (0);
	c1 = (unsigned char*)str1;
	c2 = (unsigned char*)str2;
	if (n > 1 && *c1 == *c2)
		return (ft_memcmp(str1 + 1, str2 + 1, n - 1));
	return (*c1 - *c2);
}
