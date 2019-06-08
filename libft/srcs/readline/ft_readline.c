/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:26:38 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/05 13:26:38 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_rl_buff	*get_buff(int fd, t_list **buff_list)
{
	t_list			*it;
	t_rl_buff		*result;

	it = *buff_list;
	while (it != NULL)
	{
		result = (t_rl_buff*)(it->content);
		if (result->fd == fd)
			return (result);
		it = it->next;
	}
	if (!(result = (t_rl_buff*)malloc(sizeof(t_rl_buff))))
		return (NULL);
	result->fd = fd;
	result->end = 0;
	result->buffer[0] = '\0';
	ft_lstadd(buff_list, ft_lstitem(result, sizeof(t_rl_buff)));
	return (result);
}

static void			ft_del_buff(int fd, t_list **buff_list)
{
	t_list			*it;
	t_list			*prev;
	t_rl_buff		*result;

	it = *buff_list;
	prev = NULL;
	while (it != NULL)
	{
		result = (t_rl_buff*)(it->content);
		if (result->fd == fd)
		{
			if (prev != NULL)
				prev->next = it->next;
			else
				*buff_list = it->next;
			free(it->content);
			free(it);
			return ;
		}
		prev = it;
		it = it->next;
	}
}

static int			set_line_end(int fd, char **line, int flags,
	t_list **buff_list)
{
	t_rl_buff	*last;

	last = get_buff(fd, buff_list);
	last->buffer[0] = '\0';
	if (ft_strlen(*line) > 0)
	{
		return (1);
	}
	else
	{
		if (flags & RL_LASTEMPTYLINE && !last->end)
		{
			last->end = 1;
			return (1);
		}
		free(*line);
		*line = NULL;
		ft_del_buff(fd, buff_list);
		return (0);
	}
}

static int			set_line(int fd, char **line, int flags, t_list **buff_list)
{
	char		*tmp;
	char		*newline;
	t_rl_buff	*last;

	last = get_buff(fd, buff_list);
	newline = ft_strchr(*line, '\n');
	if (newline != NULL)
	{
		tmp = *line;
		ft_strcpy(last->buffer, newline + 1);
		if (flags & RL_NEWLINE)
			*line = ft_strsub(*line, 0, newline - *line + 1);
		else
			*line = ft_strsub(*line, 0, newline - *line);
		free(tmp);
		return (1);
	}
	else
		return (set_line_end(fd, line, flags, buff_list));
}

int					ft_readline(const int fd, char **line, int flags)
{
	int				len;
	t_rl_buff		*last;
	char			*result;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*buff_list = NULL;

	len = 1;
	last = get_buff(fd, &buff_list);
	result = ft_strdup(last->buffer);
	while (ft_strchr(result, '\n') == NULL && len > 0)
	{
		len = read(fd, buffer, BUFF_SIZE);
		if (len < 0)
			return (-1);
		buffer[len] = '\0';
		ft_strappend(&result, buffer);
	}
	len = set_line(fd, &result, flags, &buff_list);
	if (line != NULL)
		*line = result;
	else
		free(result);
	return (len);
}
