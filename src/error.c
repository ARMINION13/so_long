/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:38:50 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/11 20:19:52 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_errors(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		perror("Wrong amount of arguments");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp((argv[1] + (len - 4)), ".ber", 4))
	{
		perror("Wrong map format");
		exit(EXIT_FAILURE);
	}
}

void	ft_map_errors(t_mlx_vars *a)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (a->map[y] != 0)
	{
		x = 0;
		while (a->map[y][x] != 0)
		{
			if (!(ft_strchr("01CPE", a->map[y][x])))
			{
				perror("Invalid map item found");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		if (x != a->xy[0] || a->xy[0] == a->xy[1])
		{
			perror("Not rectangular map");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	ft_map_sides(a, 0, 0);
}

int	ft_map_sides(t_mlx_vars *a, int x, int y)
{
	while (a->map[y])
	{
		if (a->map[y][0] != '1' || a->map[y][a->xy[0] - 1] != '1')
		{
			perror("Missing wall");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	while (a->map[0][x] != 0 && a->map[a->xy[1] - 1][x] != 0)
	{
		if (a->map[0][x] != '1' || a->map[a->xy[1] - 1][x] != '1')
		{
			perror("Missing wall");
			exit(EXIT_FAILURE);
		}
		x++;
	}
	ft_not_double(a);
	return (0);
}

int	ft_not_double(t_mlx_vars *a)
{
	int		it;
	int		x;
	int		y;

	x = 0;
	y = 0;
	it = 0;
	while (a->map[y] != 0)
	{
		x = 0;
		while (a->map[y][x] != 0)
		{
			if (ft_strchr("PE", a->map[y][x]))
				it++;
			x++;
		}
		y++;
	}
	if (it != 2)
	{
		perror("Wrong amount of players or exits");
		exit(EXIT_FAILURE);
	}
	return (0);
}
