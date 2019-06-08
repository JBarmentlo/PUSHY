/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:07:38 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 19:07:38 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			ft_round_buffer(char *buffer, double next)
{
	int		len;
	char	retain;
	char	c;

	retain = 1;
	len = (int)ft_strlen(buffer) - 1;
	if (next < 0.5)
		return (0);
	while (len >= 0 && retain > 0)
	{
		c = buffer[len] + retain;
		retain = c > '9';
		if (c > '9')
			c = '0';
		buffer[len] = c;
		len--;
	}
	return (retain);
}

static char			*ft_bufdecimalpart(long double nb, unsigned int nb_dec,
	char *retain)
{
	char			*buffer;
	long double		result;
	unsigned int	i;
	char			c[2];

	i = 0;
	result = (nb - (long)nb);
	c[1] = '\0';
	if (!(buffer = ft_strnew(nb_dec)))
		return (NULL);
	while (i++ < nb_dec)
	{
		result = (result - (long)result) * 10;
		c[0] = (long)(result) + '0';
		ft_strjoin_realloc(&buffer, c, 0);
	}
	*retain = ft_round_buffer(buffer, result - (long)result);
	return (buffer);
}

static char			*ft_bufdouble(long double nb, t_conv *conv)
{
	char		*buffer;
	char		*temp;
	long double	positive;
	char		retain;

	positive = nb * (nb >= 0 ? 1 : -1);
	if (!(temp = ft_bufdecimalpart(positive, conv->prec, &retain)))
		return (NULL);
	positive += retain;
	if (!(buffer = ft_itoa_base((t_biguint)(positive), 10, 1)))
		return (NULL);
	if (nb < 0)
		ft_strjoin_realloc(&buffer, "-", 1);
	if (conv->prec > 0)
	{
		ft_strjoin_realloc(&buffer, ".", 0);
		ft_strjoin_realloc(&buffer, temp, 0);
	}
	free(temp);
	return (buffer);
}

static char			*ft_apply_flags(t_conv *conv, char *buffer)
{
	char	sign[2];
	int		is_null;

	is_null = ft_strlen(buffer) == 1 && buffer[0] == '0';
	ft_bzero((void**)&sign, 2);
	if (buffer[0] == '-')
	{
		ft_strcpy(sign, "-");
		ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
	}
	while (!conv->left_justify && conv->add_zero
		&& (int)ft_strlen(buffer) < conv->size)
		ft_strjoin_realloc(&buffer, "0", 1);
	if (conv->hashtag && ft_strchr(buffer, '.') == NULL)
		ft_strjoin_realloc(&buffer, ".", 0);
	if (sign[0] == '\0' && (conv->sign_space || conv->show_sign))
		sign[0] = conv->show_sign ? '+' : ' ';
	if (sign[0] != '\0')
		ft_strjoin_realloc(&buffer, sign, 1);
	return (buffer);
}

char				*ft_handler_float(t_conv *conv, va_list ap)
{
	long double	nb;
	char		*output;

	conv->prec = conv->prec_set ? conv->prec : 6;
	if (ft_strcmp(conv->len_modifier, "L") == 0
		|| ft_strcmp(conv->len_modifier, "l") == 0)
		nb = va_arg(ap, long double);
	else
		nb = (long double)(va_arg(ap, double));
	if (!(output = ft_bufdouble(nb, conv)))
		return (NULL);
	return (ft_apply_flags(conv, output));
}
