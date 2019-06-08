/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:36:17 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/19 11:36:17 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_internal_fprintf(int fd, const char *format, va_list ap)
{
	t_conv		conv;
	int			count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			conv = ft_getconv((char*)format);
			if (conv.conv != NULL)
			{
				count += ft_dispatch(fd, &conv, ap);
				format = conv.conv;
			}
		}
		else if (*format == '{' || *format == '[')
			format = (const char*)ft_dispatch_color(fd, (char*)format, &count);
		else
		{
			count++;
			write(fd, format, 1);
		}
		format += *format == '\0' ? 0 : 1;
	}
	return (count);
}
