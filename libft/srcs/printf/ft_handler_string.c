/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:41:27 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 17:41:27 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_str(t_conv *conv, va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		if (conv->add_zero && !conv->left_justify)
		{
			while ((size_t)conv->prec > ft_strlen(str))
				ft_strjoin_realloc(&str, "0", 1);
		}
	}
	else
		str = ft_strdup(str);
	return (str);
}

char		*ft_handler_string(t_conv *conv, va_list ap)
{
	char	*str;
	char	*temp;

	if (conv == NULL)
		return (0);
	str = ft_get_str(conv, ap);
	if ((int)ft_strlen(str) > conv->prec && conv->prec_set)
	{
		temp = str;
		str = ft_strsub(str, 0, conv->prec);
		free(temp);
	}
	return (str);
}
