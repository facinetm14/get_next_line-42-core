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

static void	ft_read_line(int fd, char **str_kept,
			char **str_read, char **str_line)
{
	char	*index;
	int		count_read;

	*str_kept = ft_strjoin(*str_kept, *str_read);
	index = ft_strchr(*str_kept, '\n');
	if (index)
	{
		*str_line = ft_substr(*str_kept, 0, (index - *str_kept + 1));
		if (!(index + 1))
			*str_kept = "";
		else
			*str_kept = index + 1;		
	}
	else
	{
		count_read = read(fd, *str_read, 1);
		if (count_read <= 0)
		{
			*str_line = *str_kept;
			*str_kept = "";
		}
		else
			ft_read_line(fd, str_kept, str_read, str_line);
	}
}

char	*get_next_line(int fd)
{
	static char	*str_stored;
	char		*line;
	char		*str_buff;
	int			count;

	if (!str_stored)
		str_stored = "";
	str_buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
	count = read(fd, str_buff, 1);
	if (count <= 0 && str_stored == (char *)"")
		return (NULL);
	ft_read_line(fd, &str_stored, &str_buff, &line);
	if (!(line != ""))
		return (NULL);
	return (line);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	printf("ligne 1 : %s", get_next_line(fd));
// 	return (0);
// }
