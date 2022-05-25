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

static void	ft_read_line(int fd, char **str_kept, char **str_line)
{
	char	*index;
	int		count;
	char	*str_read;

	str_read = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	count = read(fd, str_read, BUFFER_SIZE);
	if (count < 0)
		*str_line = 0;
	else
	{
		*str_kept = ft_strjoin(*str_kept, str_read);
		free(str_read);
		index = ft_strchr(*str_kept, '\n');
		if (index)
		{
			*str_line = ft_substr(*str_kept, 0, (index - *str_kept) + 1);
			*str_kept = index + 1;
		}
		else
		{
			if (count != 0)
				ft_read_line(fd, str_kept, str_line);
			else
				*str_line = *str_kept;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*str_stored;
	char		*line;

	if (!str_stored)
		str_stored = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_line(fd, &str_stored, &line);
	if (line[0] == 0)
		return (NULL);
	return (line);
}

int main(void)
{
	int fd;	
	char *line;
	int i;
	fd = open("texte.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}