/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:23:13 by gtaja             #+#    #+#             */
/*   Updated: 2019/01/30 16:23:13 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_single_format(t_conv *conv)
{
	int		res;
	char	*flags;
	char	*tmp;

	flags = ft_strdup("%");
	res = conv->add_zero ? ft_strappend(&flags, "0") : 1;
	res += conv->left_justify ? ft_strappend(&flags, "-") : 1;
	res += conv->show_sign ? ft_strappend(&flags, "+") : 1;
	res += conv->sign_space ? ft_strappend(&flags, " ") : 1;
	res += conv->hashtag ? ft_strappend(&flags, "#") : 1;
	tmp = ft_itoa(conv->size);
	res += ft_strappend(&flags, tmp);
	free(tmp);
	if (conv->prec_set)
	{
		tmp = ft_itoa(conv->prec);
		res += ft_strappend(&flags, ".");
		res += ft_strappend(&flags, tmp);
		free(tmp);
	}
	res += ft_strappend(&flags, conv->len_modifier);
	res += ft_straddchar(&flags, *(conv->conv));
	return (flags);
}

static int	ft_print_conv_next(int fd, char *format, t_conv *conv, int i)
{
	if (*(conv->conv) == 'c')
		return (ft_fprintf(fd, format, ((char*)(conv->array))[i]));
	else if (*(conv->conv) == 's')
		return (ft_fprintf(fd, format, ((char*)(conv->array))[i]));
	else if (*(conv->conv) == 'p')
		return (ft_fprintf(fd, format, ((void**)(conv->array))[i]));
	else
		return (0);
}

static int	ft_print_conv(int fd, char *format, t_conv *conv, int i)
{
	if (ft_strchr("diouxXb", *(conv->conv)) != NULL)
	{
		if (ft_strequ(conv->len_modifier, "hh"))
			return (ft_fprintf(fd, format, ((char*)(conv->array))[i]));
		else if (ft_strequ(conv->len_modifier, "h"))
			return (ft_fprintf(fd, format, ((short*)(conv->array))[i]));
		else if (ft_strequ(conv->len_modifier, "l"))
			return (ft_fprintf(fd, format, ((long*)(conv->array))[i]));
		else if (ft_strequ(conv->len_modifier, "ll"))
			return (ft_fprintf(fd, format, ((long long*)(conv->array))[i]));
		else
			return (ft_fprintf(fd, format, ((int*)(conv->array))[i]));
	}
	else if (*(conv->conv) == 'f')
	{
		if (ft_strequ(conv->len_modifier, "L")
			|| ft_strequ(conv->len_modifier, "l"))
			return (ft_fprintf(fd, format, ((long double*)(conv->array))[i]));
		else
			return (ft_fprintf(fd, format, ((double*)(conv->array))[i]));
	}
	else
		return (ft_print_conv_next(fd, format, conv, i));
}

int			ft_exec_handler_array(int fd, t_conv *conv, va_list ap)
{
	int		size;
	int		res;
	int		i;
	char	*format;

	i = 0;
	conv->array = va_arg(ap, void*);
	size = va_arg(ap, int);
	res = ft_fprintf(fd, "{");
	format = ft_get_single_format(conv);
	while (i < size)
	{
		if (i > 0)
			res += ft_fprintf(fd, ", ");
		res += ft_print_conv(fd, format, conv, i);
		i++;
	}
	res += ft_fprintf(fd, "}");
	free(format);
	return (res);
}
