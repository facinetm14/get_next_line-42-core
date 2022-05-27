/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:23:29 by fakouyat          #+#    #+#             */
/*   Updated: 2022/05/19 17:23:29 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int	ft_check(char **str_kept, char **line)
{
	char	*index;

	index = ft_strchr(*str_kept, '\n');
	if (index)
	{
		*line = ft_substr(*str_kept, 0, (index - *str_kept) + 1);
		*str_kept = index + 1;
		if (*(index + 1) == 0)
			free(*str_kept);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static int	count;
	static char	*str_kept;
	char		*str_read;
	char		*line;

	if (!str_kept)
		str_kept = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_check(&str_kept, &line) == 1)
		return (line);
	str_read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	count = read(fd, str_read, BUFFER_SIZE);
	if (count == 0)
	{
		line = str_kept;
		str_kept = NULL;
		free(str_read);
		return (line);
	}
	str_kept = ft_strjoin(str_kept, ft_substr(str_read, 0, count));
	free(str_read);
	if (count < 0)
		return (NULL);
	return (get_next_line(fd));
}
