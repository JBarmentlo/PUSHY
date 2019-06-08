/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:53:12 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/08 11:53:12 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
