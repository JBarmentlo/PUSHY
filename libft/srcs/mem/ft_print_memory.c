/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:19:55 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/25 22:19:55 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_char(unsigned char *content, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && i < 16)
	{
		if (ft_isprint((int)content[i]))
			ft_putchar(content[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("\t");
}

static void	ft_print_hex(unsigned char *content, size_t len)
{
	size_t	i;
	char	*buf;

	i = 0;
	while (i < len && i < 16)
	{
		if (i % 2 == 0 && i > 0)
			ft_putchar(' ');
		buf = ft_itoa_base(content[i], 16, 1);
		if (ft_strlen(buf) == 1)
			ft_putchar('0');
		ft_putstr(buf);
		free(buf);
		i++;
	}
	ft_putchar('\n');
}

void		ft_print_memory(void *addr, size_t len)
{
	unsigned char	*content;

	content = (unsigned char*)addr;
	ft_print_char(content, len);
	ft_print_hex(content, len);
	if (len > 16)
		ft_print_memory(addr + 16, len - 16);
}
