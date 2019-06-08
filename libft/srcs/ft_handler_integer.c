/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:30:52 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 16:30:52 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_biguint	ft_get_value(t_conv *conv, va_list ap)
{
	if (*conv->conv != 'd' && *conv->conv != 'i')
	{
		if (ft_strncmp(conv->len_modifier, "hh", 2) == 0)
			return ((t_biguint)((unsigned char)va_arg(ap, int)));
		else if (ft_strncmp(conv->len_modifier, "ll", 2) == 0)
			return ((t_biguint)((unsigned long long)va_arg(ap, long long)));
		else if (ft_strncmp(conv->len_modifier, "h", 1) == 0)
			return ((t_biguint)((unsigned short)va_arg(ap, int)));
		else if (ft_strncmp(conv->len_modifier, "l", 1) == 0)
			return ((t_biguint)((unsigned long)va_arg(ap, long)));
		return ((t_biguint)((unsigned int)va_arg(ap, int)));
	}
	else
	{
		if (ft_strncmp(conv->len_modifier, "hh", 2) == 0)
			return ((t_biguint)((char)va_arg(ap, int)));
		else if (ft_strncmp(conv->len_modifier, "ll", 2) == 0)
			return ((t_biguint)va_arg(ap, long long));
		else if (ft_strncmp(conv->len_modifier, "h", 1) == 0)
			return ((t_biguint)((short)va_arg(ap, int)));
		else if (ft_strncmp(conv->len_modifier, "l", 1) == 0)
			return ((t_biguint)va_arg(ap, long));
		return ((t_biguint)va_arg(ap, int));
	}
}

static char			*ft_bufinteger(t_biguint nb, int is_signed)
{
	char	*result;

	if (is_signed && (t_bigint)nb < 0)
	{
		nb = (t_biguint)((t_bigint)nb * -1LL);
		result = ft_itoa_base(nb, 10, 0);
		ft_strjoin_realloc(&result, "-", 1);
	}
	else
		result = ft_itoa_base(nb, 10, 0);
	return (result);
}

static char			*ft_apply_flags_next(t_conv *conv, char *buffer, char *sign)
{
	int		is_null;

	is_null = ft_strlen(buffer) == 0
		|| (ft_strlen(buffer) == 1 && buffer[0] == '0');
	if (!conv->left_justify && conv->add_zero)
	{
		conv->size -= ft_strlen(sign);
		if (conv->hashtag && ft_strchr("oxX", *conv->conv))
			conv->size -= ft_strchr("xX", *conv->conv) ? 2 : 1;
		conv->size = conv->size < 0 ? 0 : conv->size;
		while ((int)ft_strlen(buffer) < conv->size)
			ft_strjoin_realloc(&buffer, "0", 1);
	}
	if (conv->hashtag && ft_strchr("oxX", *conv->conv))
	{
		if (*conv->conv == 'o' && buffer[0] != '0')
			ft_strjoin_realloc(&buffer, "0", 1);
		else if (*conv->conv != 'o' && !is_null)
			ft_strjoin_realloc(&buffer, *conv->conv == 'x' ? "0x" : "0X", 1);
	}
	if (sign[0] != '\0')
		ft_strjoin_realloc(&buffer, sign, 1);
	return (buffer);
}

static char			*ft_apply_flags(t_conv *conv, char *buffer)
{
	char	sign[2];
	int		is_signed;

	is_signed = *conv->conv == 'd' || *conv->conv == 'i';
	ft_bzero((void*)sign, 2);
	if (buffer[0] == '-')
	{
		ft_strcpy(sign, "-");
		ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
	}
	if (is_signed && sign[0] == '\0' && (conv->sign_space || conv->show_sign))
		sign[0] = conv->show_sign ? '+' : ' ';
	conv->add_zero = !conv->prec_set && conv->add_zero;
	while (conv->prec_set && (int)ft_strlen(buffer) < conv->prec)
		ft_strjoin_realloc(&buffer, "0", 1);
	return (ft_apply_flags_next(conv, buffer, sign));
}

char				*ft_handler_integer(t_conv *conv, va_list ap)
{
	int			is_signed;
	t_biguint	value;
	char		*buffer;

	buffer = NULL;
	is_signed = *conv->conv == 'd' || *conv->conv == 'i';
	value = ft_get_value(conv, ap);
	if (conv->prec_set && conv->prec == 0 && value == 0)
		return (ft_apply_flags(conv, ft_strdup("")));
	if (*conv->conv == 'o')
		buffer = ft_itoa_base(value, 8, 0);
	else if (*conv->conv == 'x' || *conv->conv == 'X')
		buffer = ft_itoa_base(value, 16, *conv->conv == 'X');
	else if (*conv->conv == 'b')
		buffer = ft_itoa_base(value, 2, 0);
	else
		buffer = ft_bufinteger(value, is_signed);
	return (ft_apply_flags(conv, buffer));
}
