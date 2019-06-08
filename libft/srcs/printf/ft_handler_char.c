/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:37:30 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 16:37:30 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_handler_char(t_conv *conv, va_list ap)
{
	char	*buffer;
	char	c;

	if (conv == NULL)
		return (NULL);
	if (!(buffer = ft_strnew(1)))
		return (NULL);
	c = (char)va_arg(ap, int);
	if (c == 0)
	{
		buffer[0] = -1;
		conv->prec = 0;
	}
	else
		buffer[0] = c;
	return (buffer);
}
