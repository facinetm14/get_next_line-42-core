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

int	ft_size_s(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_jonction(char const *s1, char const *s2,
char *str_joined, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < length)
	{
		if (s1[i] != 0)
		{
			str_joined[i + j] = s1[i];
			i++;
		}
		else if (s2[j] != 0)
		{
			str_joined[i + j] = s2[j];
			j++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	length = i + j;
	str_joined = (char *)malloc(sizeof(char) * length + 1);
	if (!str_joined)
		return (NULL);
	ft_jonction(s1, s2, str_joined, length);
	str_joined[length] = '\0';
	return (str_joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	s_len = ft_size_s((char *)s);
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
	sub_str[i] = '\0';
	return (sub_str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		size;

	i = 0;
	size = ft_size_s((char *)s);
	while (i <= size)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
