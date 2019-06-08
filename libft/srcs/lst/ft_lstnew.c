/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:57:47 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/09 10:57:47 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ls;

	if (!(ls = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		ls->content = NULL;
		ls->content_size = 0;
	}
	else
	{
		if (!(ls->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(ls->content, content, content_size);
		ls->content_size = content_size;
	}
	ls->next = NULL;
	return (ls);
}
