/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:55:47 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/07 21:01:42 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	print_window(t_mlx_vars *a)
{
	int		x;
	int		y;
	int		wid;
	int		hei;

	x = 0;
	y = 0;
	a->img[0] = mlx_xpm_file_to_image(a->mlx, "./xpm/0.xpm", &wid, &hei);
	mlx_clear_window(a->mlx, a->win);
	while ((y / 80) < a->xy[1])
	{
		x = 0;
		while ((x / 80) < a->xy[0])
		{	
			if (a->img[0])
				mlx_put_image_to_window(a->mlx, a->win, a->img[0], x, y);
			over_floor(a, x, y);
			x += 80;
		}
		y += 80;
	}
	mlx_destroy_image(a->mlx, a->img[0]);
	return (0);
}

void	over_floor(t_mlx_vars *a, int x, int y)
{
	int		wid;
	int		hei;

	a->img[1] = mlx_xpm_file_to_image(a->mlx, "./xpm/1.xpm", &wid, &hei);
	a->img[2] = mlx_xpm_file_to_image(a->mlx, "./xpm/C.xpm", &wid, &hei);
	a->img[3] = mlx_xpm_file_to_image(a->mlx, "./xpm/P.xpm", &wid, &hei);
	a->img[4] = mlx_xpm_file_to_image(a->mlx, "./xpm/E.xpm", &wid, &hei);
	if (!a->img[0] || !a->img[1] || !a->img[2] || !a->img[3] || !a->img[4])
	{
		perror(".xpm files not found");
		exit(EXIT_FAILURE);
	}
	if (a->map[y / 80][x / 80] == '1')
		mlx_put_image_to_window(a->mlx, a->win, a->img[1], x, y);
	if (a->map[y / 80][x / 80] == 'C')
		mlx_put_image_to_window(a->mlx, a->win, a->img[2], x, y);
	if (a->map[y / 80][x / 80] == 'P')
		mlx_put_image_to_window(a->mlx, a->win, a->img[3], x, y);
	if (a->map[y / 80][x / 80] == 'E')
		mlx_put_image_to_window(a->mlx, a->win, a->img[4], x, y);
	mlx_destroy_image(a->mlx, a->img[1]);
	mlx_destroy_image(a->mlx, a->img[2]);
	mlx_destroy_image(a->mlx, a->img[3]);
	mlx_destroy_image(a->mlx, a->img[4]);
}
