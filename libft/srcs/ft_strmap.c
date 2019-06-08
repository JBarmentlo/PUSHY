/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:11:25 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/08 15:11:25 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if (!(result = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
