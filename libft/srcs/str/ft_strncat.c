/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:30:30 by gtaja             #+#    #+#             */
/*   Updated: 2018/09/03 14:30:31 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		start;

	i = 0;
	start = 0;
	while (s1[start] != '\0')
	{
		start++;
	}
	while (s2[i] != '\0' && i < n)
	{
		s1[start + i] = s2[i];
		i++;
	}
	s1[start + i] = '\0';
	return (s1);
}
