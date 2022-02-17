/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:46:55 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/07 17:35:49 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
