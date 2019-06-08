/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moult_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:18:43 by gtaja             #+#    #+#             */
/*   Updated: 2019/03/05 14:21:34 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	moult_free(int n, ...)
{
	va_list		ap;

	va_start(ap, n);
	while (n-- > 0)
		free(va_arg(ap, void*));
	va_end(ap);
}