/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:26:29 by kannie            #+#    #+#             */
/*   Updated: 2022/01/05 19:48:14 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		a;

	i = -1;
	a = 0;
	if (!(s1 && s2))
		return (NULL);
	newstr = (char *)malloc (sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		newstr[i] = (char)s1[i];
	while (s2[a] != '\0')
	{
		newstr[i] = (char)s2[a];
		a++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	if (c >= 0)
	{
		while (str[i] != '\0' && (unsigned char)c != str[i])
		{
			i++;
		}
		if ((unsigned char)c != str[i])
			return (NULL);
		else
			return (&str[i]);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > i && s[i] != '\0')
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
