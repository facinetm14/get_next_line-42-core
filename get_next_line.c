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

char    *get_next_line(int fd)
{
    static char	*str_kept;
	char		*line;
	char		*str_read;

	str_read = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
	line = ft_read_line(fd, str_read, str_kept, BUFFER_SIZE);
	return (line);
}
