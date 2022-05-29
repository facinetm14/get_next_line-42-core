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

char	*ft_read_line(char **str_kept, char *tmp, int fd, int *end)
{
	char	*index;
	char	*buffer;
	char	*tmp_2;
	int		count_read;

	index = ft_strchr(tmp, '\n');
	if (index != 0)
	{
		*str_kept = 0;
		if (*(index + 1) != 0)
			*str_kept = index + 1;
		return (ft_substr(tmp, 0, (index - tmp) + 1));
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	count_read = read(fd, buffer, BUFFER_SIZE);
	if (count_read > 0)
	{
		buffer[count_read] = '\0';
		tmp_2 = ft_strjoin(tmp, buffer);
		free(buffer);
		return (ft_read_line(str_kept, tmp_2, fd, end));
	}
	*end = -1;
	*str_kept = tmp;
	return (*str_kept);
}

char	*get_next_line(int fd)
{
	static char	*str_kept;
	char		*str_read;
	int			count;
	char		*line;
	char		*tmp;

	if (!str_kept)
		str_kept = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_read = (char *)malloc(sizeof(char) * BUFFER_SIZE * 1);
	count = read(fd, str_read, BUFFER_SIZE);
	if (count < 0)
		return (NULL);
	str_read[count] = '\0';
	tmp = ft_strjoin(str_kept, str_read);
	free(str_read);
	line = ft_read_line(&str_kept, tmp, fd, &count);
	if (count == -1)
		str_kept = NULL;
	if (line[0] != 0)
		return (line);
	return (NULL);
}	

// #include <stdio.h>

// int main(void)
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	int i;
// 	char	*test;
// 	i = 0;
// 	while (i < 10)
// 	{
// 		test = get_next_line(fd);
// 		printf("%d, %s", i+1, test);
// 		free(test);
// 		i++;
// 	}
// 	return (0);
// }