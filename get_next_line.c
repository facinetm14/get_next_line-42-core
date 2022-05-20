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
    static int  already_read;
    int         current_index;
    char        *str_current;
    char        *line_read;
    int         buff_size;

    current_index = ft_read_line(fd, str_current, buff_size, &already_read);
    line_read = ft_substring(str_current, already_read, current_index + 1);
    free(str_current);
    return (line_read);
}
