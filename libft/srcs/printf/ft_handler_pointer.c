/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:27:59 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 18:27:59 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_handler_pointer(t_conv *conv, va_list ap)
{
	void		*addr;
	char		*buffer;
	char		*temp;
	t_biguint	nb;

	if (conv == NULL)
		return (0);
	addr = va_arg(ap, void*);
	nb = (t_biguint)addr;
	if (conv->prec_set && conv->prec == 0 && nb == 0)
		temp = ft_strnew(0);
	else
	{
		temp = ft_itoa_base(nb, 16, 0);
		while (conv->prec_set && (size_t)conv->prec > ft_strlen(temp))
			ft_strjoin_realloc(&temp, "0", 1);
	}
	buffer = ft_strjoin("0x", temp);
	free(temp);
	return (buffer);
}
