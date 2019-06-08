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

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = ft_internal_fprintf(fd, format, ap);
	va_end(ap);
	return (count);
}
