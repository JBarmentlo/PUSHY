/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:18:08 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 16:18:08 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_blank(int fd, t_conv *conv, int *len)
{
	char	c;

	c = conv->left_justify || !conv->add_zero ? ' ' : '0';
	while (*len < conv->size)
	{
		ft_putchar_fd(c, fd);
		*len = *len + 1;
	}
}

static int	ft_check_null(int fd, t_conv *conv)
{
	int len;

	len = 0;
	if (conv->conv == NULL || *conv->conv == '\0'
		|| ft_strchr(ALL_CONVERSION, *conv->conv) == NULL)
	{
		if (conv->conv != NULL && *conv->conv != '\0')
		{
			len = 1;
			if (!conv->left_justify)
				ft_fill_blank(fd, conv, &len);
			write(fd, conv->conv, 1);
			if (conv->left_justify)
				ft_fill_blank(fd, conv, &len);
		}
		else
			ft_fill_blank(fd, conv, &len);
		return (len);
	}
	else
		return (-1);
}

static int	ft_exec_handler(int fd, t_handler handler, t_conv *conv, va_list ap)
{
	int		len;
	char	*result;

	result = (handler.fct)(conv, ap);
	len = ft_strlen(result);
	if (!conv->left_justify)
		ft_fill_blank(fd, conv, &len);
	if (handler.fct == &ft_handler_char && result[0] == -1)
		write(fd, "\0", 1);
	else
		write(fd, result, ft_strlen(result));
	if (conv->left_justify)
		ft_fill_blank(fd, conv, &len);
	free(result);
	return (len);
}

int			ft_dispatch(int fd, t_conv *conv, va_list ap)
{
	int			i;
	int			len;
	t_handler	*handlers;

	i = 0;
	if ((len = ft_check_null(fd, conv)) >= 0)
		return (len);
	if (conv->is_array)
		return (ft_exec_handler_array(fd, conv, ap));
	handlers = ft_get_handlers();
	while (handlers[i].conv != NULL)
	{
		if (ft_strchr(handlers[i].conv, *(conv->conv)) != NULL)
		{
			len = ft_exec_handler(fd, handlers[i], conv, ap);
			free(handlers);
			return (len);
		}
		i++;
	}
	free(handlers);
	return (0);
}
