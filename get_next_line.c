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

static void	free_mem(void *pointer)
{
	free(pointer);
	pointer = 0;
}

static char	*ft_read_line(int fd, char **str_kept)
{
	char	*index;
	char	*str_read;
	char	*line;
	int		count;

	str_read = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	count = read(fd, str_read, BUFFER_SIZE);
	if (count <= 0)
	{
		line = *str_kept;
		*str_kept = NULL;
		return (line);
	}
	*str_kept = ft_strjoin(*str_kept, str_read);
	free_mem(str_read);
	index = ft_strchr(*str_kept, '\n');
	if (index != 0)
	{
		line = ft_substr(*str_kept, 0, (index - *str_kept) + 1);
		free_mem(*str_kept);
		*str_kept = index + 1;
	}
	else
		return (ft_read_line(fd, str_kept));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str_stored;
	char		*line;

	if (!str_stored)
		str_stored = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, &str_stored);
	return (line);
}

int main(void)
{
	int fd;	
	int i;
	fd = open("bible.txt", O_RDONLY);
	i = 0;
	char *line;
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line = 0;
		i++;
	}
}