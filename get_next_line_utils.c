/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:07:27 by fakouyat          #+#    #+#             */
/*   Updated: 2022/05/19 19:07:27 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sub_str;
        size_t  i;
        size_t  s_len;

        s_len = ft_strlen(s);
        i = 0;
        if (s_len < len)
                sub_str = (char *)malloc(sizeof(char) * 1);
        else
                sub_str = (char *)malloc(sizeof(char) * (len + 1));
        if (!sub_str)
                return (NULL);
        while (i < len && start < s_len)
        {
                sub_str[i] = s[start];
                i++;
                start++;
        }
        sub_str[i] = 0;
        return (sub_str);
}
char * ft_read_line(int fd, char *str_current, int buff_size, int *already_read)
{
    int count;
    char *str_read;
    count = read(fd, str_current, buff_size);
    if (!count)
        return NULL;
    str_read = ft_substr(str_current, *already_read, count);
    *already_read += count;
    return (str_read);
}
int main()
{
    int fd = open("text.txt", O_RDONLY | O_CREAT);
    char *test;
    char *test2;
    static int already_read = 0;
    int buff_size = 3;
    test = malloc(buff_size * sizeof(char *));
    test2 = malloc(buff_size * sizeof(char *));
    printf("%d\n", (int)read(fd, test, 12));
    printf("%d", (int)read(fd, test2, 10));
    printf("%s\n", test);
    printf("%s", test2);
    return (0);
    
}