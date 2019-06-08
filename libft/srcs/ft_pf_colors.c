/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:39:26 by gtaja             #+#    #+#             */
/*   Updated: 2018/12/08 12:39:26 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searchcolor(int fd, char **format, char *id, char *result)
{
	size_t	len_id;

	len_id = ft_strlen(id);
	if (ft_strncmp(*format, id, len_id) == 0)
	{
		*format = *format + len_id - 1;
		write(fd, result, ft_strlen(result));
		return (ft_strlen(result));
	}
	return (0);
}

static int	ft_writedeafault(int fd, char *format)
{
	if (*format == '{')
	{
		write(fd, "{", 1);
		return (1);
	}
	if (*format == '[')
	{
		write(fd, "[", 1);
		return (1);
	}
	return (0);
}

char		*ft_dispatch_color(int fd, char *format, int *count)
{
	*count += ft_searchcolor(fd, &format, "{black}", PF_BLACK);
	*count += ft_searchcolor(fd, &format, "{red}", PF_RED);
	*count += ft_searchcolor(fd, &format, "{green}", PF_GREEN);
	*count += ft_searchcolor(fd, &format, "{yellow}", PF_YELLOW);
	*count += ft_searchcolor(fd, &format, "{blue}", PF_BLUE);
	*count += ft_searchcolor(fd, &format, "{magenta}", PF_MAGENTA);
	*count += ft_searchcolor(fd, &format, "{cyan}", PF_CYAN);
	*count += ft_searchcolor(fd, &format, "{reset}", PF_RESET);
	*count += ft_searchcolor(fd, &format, "[black]", PF_BLACK_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[red]", PF_RED_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[green]", PF_GREEN_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[yellow]", PF_YELLOW_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[blue]", PF_BLUE_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[magenta]", PF_MAGENTA_UNDERLINE);
	*count += ft_searchcolor(fd, &format, "[cyan]", PF_CYAN_UNDERLINE);
	*count += ft_writedeafault(fd, format);
	return (format);
}
