/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:20:37 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/10 18:49:38 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		a;

	ptr = (char *)str;
	a = 0;
	while (ptr[a] != c && ptr[a] != 0)
		a++;
	if (ptr[a] == c)
		return (ptr + a);
	return (NULL);
}

void	operation_null(char **s)
{
	if (*s && **s)
	{
		free(*s);
		*s = NULL;
	}
}

int	maniobra_line(char **s, char **line, int fd)
{
	int		a;
	char	*tmp;

	a = 0;
	while (s[fd][a] != '\n' && s[fd][a] != '\0')
		a++;
	*line = ft_substr(s[fd], 0, a);
	tmp = ft_strdup(&s[fd][a + 1]);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int	returns(char **s, char **line, int count, int fd)
{
	if (count < 0)
		return (-1);
	else if (count == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		operation_null(&s[fd]);
		return (0);
	}
	else if (ft_strchr(s[fd], '\n') == NULL)
	{
		*line = ft_strdup(s[fd]);
		operation_null(&s[fd]);
		return (0);
	}
	else
		return (maniobra_line(s, line, fd));
}

int	get_next_line(int fd, char **line)
{
	static char		*s[4096];
	int				count;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;

	count = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count > 0)
			buff[count] = '\0';
		if (s[fd] == NULL && count > 0)
			s[fd] = ft_strdup(buff);
		else if (count > 0)
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (returns(s, line, count, fd));
}
