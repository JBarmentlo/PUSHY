/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:44:55 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/27 18:26:05 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile_str(int fd)
{
	char	*file_content;
	char	*line;

	file_content = NULL;
	while (ft_readline(fd, &line, RL_NEWLINE) > 0)
	{
		ft_strappend(&file_content, line);
		free(line);
	}
	return (file_content);
}

char	**ft_readfile_tab(int fd)
{
	char	**tab;
	char	*file_content;

	file_content = ft_readfile_str(fd);
	if (file_content == NULL)
		return (NULL);
	tab = ft_strsplit_each(file_content, '\n');
	free(file_content);
	return (tab);
}
