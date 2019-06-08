/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:10:34 by gtaja             #+#    #+#             */
/*   Updated: 2019/01/29 13:10:34 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_safe_atoi(const char *str, int *err)
{
	long	result;
	int		sign;

	result = 0;
	sign = -1;
	*err = 0;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (ft_strlen(str) <= 0)
		return ((*err = 1));
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 - (*str - '0');
		if (result * (long)sign < (long)INT_MIN
			|| result * (long)sign > (long)INT_MAX)
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	*err = *str != '\0';
	return ((int)result * sign);
}
