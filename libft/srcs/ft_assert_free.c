/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:15:57 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 16:33:15 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_assert_free(int condition, char *freechain_id, char *err)
{
	if (!condition)
	{
		ft_freechain_free(freechain_id);
		ft_exit_error(err);
	}
}
