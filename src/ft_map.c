/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:46:40 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/11 20:25:13 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_initilize_map(t_mlx_vars *a, char **argv)
{
	int		fd;
	char	*str;

	str = 0;
	a->map = 0;
	fd = open(argv[1], O_RDONLY);
	str = malloc_map(fd);
	close(fd);
	a->map = ft_split(str, '\n');
	free(str);
	ft_readmap(a);
	ft_map_errors(a);
	if (a->col == 0)
	{
		perror("No collectibles");
		exit(EXIT_FAILURE);
	}
	if ((a->xy[0] * 80) > 2560 || (a->xy[1] * 80) > 1280)
	{
		perror("Map too big");
		exit(EXIT_FAILURE);
	}
	return (0);
}

char	*malloc_map(int fd)
{
	char	*str;
	char	*str2;
	char	*str3;

	get_next_line(fd, &str);
	str3 = ft_strdup(str);
	str2 = ft_strjoin(str3, "\n");
	free(str3);
	str3 = str2;
	free(str);
	while (get_next_line(fd, &str) > 0)
	{
		str2 = ft_strjoin(str2, str);
		free(str3);
		str3 = str2;
		str2 = ft_strjoin(str2, "\n");
		free(str3);
		str3 = str2;
		free(str);
	}
	free(str);
	return (str2);
}

int	ft_readmap(t_mlx_vars *a)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	a->col = 0;
	while (a->map[y] != 0)
	{
		x = 0;
		while (a->map[y][x] != 0)
		{
			if (ft_strchr("CEP", a->map[y][x]))
				map_items(a, x, y);
			x++;
		}
		y++;
	}
	a->xy[0] = x;
	a->xy[1] = y;
	return (0);
}

void	map_items(t_mlx_vars *a, int x, int y)
{
	if (a->map[y][x] == 'C')
		a->col += 1;
	if (a->map[y][x] == 'E')
	{
		a->ex_p[0] = x;
		a->ex_p[1] = y;
		a->ex_p[2] = 1;
	}
	if (a->map[y][x] == 'P')
	{
		a->ply_p[0] = x;
		a->ply_p[1] = y;
	}
}
