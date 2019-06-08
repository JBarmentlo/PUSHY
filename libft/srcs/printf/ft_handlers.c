/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:19:01 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 16:19:01 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_handler	new_handler(char *conv, char *(*fct)(t_conv *, va_list))
{
	t_handler	result;

	result.conv = conv;
	result.fct = fct;
	return (result);
}

t_handler			*ft_get_handlers(void)
{
	t_handler	*handlers;

	handlers = (t_handler*)malloc(7 * sizeof(t_handler));
	if (handlers == NULL)
		return (NULL);
	handlers[0] = new_handler("diouxXb", &ft_handler_integer);
	handlers[1] = new_handler("c", &ft_handler_char);
	handlers[2] = new_handler("s", &ft_handler_string);
	handlers[3] = new_handler("p", &ft_handler_pointer);
	handlers[4] = new_handler("f", &ft_handler_float);
	handlers[5] = new_handler("%", &ft_handler_percent);
	handlers[6] = new_handler(NULL, NULL);
	return (handlers);
}
