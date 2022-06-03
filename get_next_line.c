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

char    *ft_append(char *str_kept, char *str_read)
{
    char *str_appended;
    str_appended = ft_strjoin(str_kept, str_read);
    if (!str_kept)
        free(str_kept);
    if (!str_read)
        free(str_read);
    free(str_read);
    return (str_appended);
}

char    *ft_strdup(const char *s)
{
	int     i;
	char    *s_cpy;

	i = 0;
	while (s[i] != 0)
		i++;
	s_cpy = (char *)malloc(i + 1);
	if (!s_cpy)
		return (0);
	s_cpy[i] = '\0';
	while (i > 0)
	{
		s_cpy[i - 1] = s[i - 1];
		i--;
	}
	return (s_cpy);
}

char    *ft_read_line(char **tmp, int *count, int fd)
{
    char    *index;
    char    *tmp_2;
    char    *buffer;
 
    index = ft_strchr(*tmp, '\n');
    if (index)
    {
        *count = index - *tmp;
        return (ft_substr(*tmp, 0, *count + 1));
    }
    if (*count == 0)
    {
        *count = -1;
        return (*tmp);
    }
    buffer = (char *)malloc((sizeof(char)*BUFFER_SIZE + 1));
    *count = read(fd, buffer, BUFFER_SIZE);
    buffer[*count] = '\0';
    tmp_2 = ft_strdup((const char *)*tmp);
    *tmp = ft_append(tmp_2, buffer);
    return (ft_read_line(tmp, count, fd));
}

char	*get_next_line(int fd)
{
    int         count;
    char        *str_read;
    char        *tmp;
    static char *str_kept;
    char        *line;

    if (!str_kept)
        str_kept = "";
    str_read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    count = read(fd, str_read, BUFFER_SIZE);
    if (count < 0 || (count == 0 && str_kept[0] == 0))
    {
        free(str_read);
        return (NULL);
    }
    str_read[count] = '\0';
    tmp = ft_append(str_kept, str_read);
    line = ft_read_line(&tmp, &count, fd);
    str_kept = ft_strdup(tmp + count + 1);
    if (count == -1)
        str_kept = 0;
    return (line);
}	

int main(void)
{
	int fd;
	char *test;
	int i;
	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 8)
	{
		test = get_next_line(fd);
		printf("%s", test);
        free(test);
		i++;
	}
	return (0);
}
