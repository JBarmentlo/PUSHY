/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:28:50 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/06 20:28:50 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = -1;
	while (*str == '\f' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 - (*str - '0');
		str++;
	}
	return (result * sign);
}
