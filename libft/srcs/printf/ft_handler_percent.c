/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:17:19 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 18:17:19 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_handler_percent(t_conv *conv, va_list ap)
{
	char	*buffer;

	if (conv == NULL || ap == 0)
		return (NULL);
	if (!(buffer = ft_strnew(1)))
		return (NULL);
	buffer[0] = '%';
	return (buffer);
}
