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

int	ft_read_line(int fd, char **str_kept, char **line, int *count)
{
	char	str_read[BUFFER_SIZE + 1];
	char	*index;
	char	*tmp;

	index = ft_strchr(*str_kept, '\n');
	if (index != 0)
	{
		tmp = ft_substr(*str_kept, 0, ((index - *str_kept) + 1));
		*line = tmp;
		if (*(index + 1) != 0)
			*str_kept = index + 1;
		else
			*str_kept = "";
		return (1);
	}
	*count = read(fd, str_read, BUFFER_SIZE);
	str_read[*count] = 0;
	tmp = ft_strjoin(*str_kept, str_read);
	*str_kept = tmp;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str_kept;
	static int	count;
	char		*line;

	count = 0;
	if (!str_kept)
		str_kept = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read_line(fd, &str_kept, &line, &count) == 1)
		return (line);
	if (count == 0)
	{
		line = str_kept;
		str_kept = "";
		return (line);
	}
	if (count < 0)
		return (NULL);
	return (get_next_line(fd));
}

#include <stdio.h>
int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *test;
	int i;
	i = 1;
	while (i <= 39)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free(test);
		i++;
	}
	return (0);
}