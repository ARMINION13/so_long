/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:21:05 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/07 21:21:12 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlengnl(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != 0)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	if (str != 0)
	{
		while (s[i] != 0)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = 0;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		str = malloc(sizeof(char) * (ft_strlengnl(s1) + ft_strlengnl(s2) + 1));
		if (!str)
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*(ptr++) = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_bzero(str, len);
		if (start <= (unsigned int)ft_strlengnl(s))
		{
			while (i < len && s[i])
			{
				str[i] = s[i + start];
				i++;
			}
		}
		if (i < len + 1)
			str[i] = '\0';
		return (str);
	}
	return (0);
}
