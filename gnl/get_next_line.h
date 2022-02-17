/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:20:51 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/07 21:20:54 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *str, int c);
int				ft_strlengnl(const char *str);
int				get_next_line(int fd, char **line);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
