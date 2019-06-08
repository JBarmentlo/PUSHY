/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:41:00 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/09 09:41:00 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_itoa_rec(long n, int index, int *len, int sign)
{
	char	*result;

	if (n < 0)
	{
		n *= -1;
		sign = 1;
		*len = *len + 1;
	}
	*len = *len + 1;
	if (n >= 10)
		result = ft_itoa_rec(n / 10, index + 1, len, sign);
	else
	{
		if (!(result = (char*)malloc((*len + 1) * sizeof(char))))
			return (NULL);
		result[*len] = '\0';
		if (sign)
			result[0] = '-';
	}
	if (result == NULL)
		return (NULL);
	result[*len - index - 1] = n % 10 + '0';
	return (result);
}

char		*ft_itoa(int n)
{
	int		len;

	len = 0;
	return (ft_itoa_rec((long)n, 0, &len, 0));
}
