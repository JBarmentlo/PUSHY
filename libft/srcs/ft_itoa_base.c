/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:35:17 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/22 13:35:17 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_generate_base(unsigned int base, int maj)
{
	unsigned int	i;
	char			*charset;

	i = 0;
	base = base > 16 ? 16 : base;
	base = base < 2 ? 2 : base;
	if (!(charset = ft_strnew(base)))
		return (NULL);
	while (i < base)
	{
		if (i < 10)
			charset[i] = i + '0';
		else if (maj)
			charset[i] = i - 10 + 'A';
		else
			charset[i] = i - 10 + 'a';
		i++;
	}
	charset[i] = '\0';
	return (charset);
}

static int		ft_get_nb_base_len(t_biguint nb, t_biguint base_len)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(t_biguint nb, unsigned int base_len, int maj)
{
	char	*result;
	char	*base;
	int		result_size;
	int		i;

	base = ft_generate_base(base_len, maj);
	result_size = ft_get_nb_base_len(nb, base_len);
	i = 0;
	if (!(result = ft_strnew(result_size)))
		return (NULL);
	result[0] = base[0];
	while (nb > 0)
	{
		result[result_size - i - 1] = base[nb % base_len];
		nb /= base_len;
		i++;
	}
	free(base);
	return (result);
}
