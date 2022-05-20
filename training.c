/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:38:49 by fakouyat          #+#    #+#             */
/*   Updated: 2022/05/18 18:38:49 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include<fcntl.h> 
#include <stdlib.h>
int ft_test_static_var(int input)
{
   static int count;
    count++; 
    return count;
}
int main()
{
    int fd;
    char *c;
    c = malloc(sizeof(char *) * 11);
    fd = open("text.txt", O_RDONLY | O_CREAT);
    read(fd, c, 10);
    printf("%s\n", c);
    printf("%d\n", ft_test_static_var(1));
    printf("%d\n", ft_test_static_var(1));
    printf("%d\n", ft_test_static_var(1));
    return (0);
}

