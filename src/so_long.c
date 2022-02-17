/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:42:51 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/15 17:56:57 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_vars	*mlx;

	mlx = (t_mlx_vars *)malloc(sizeof(t_mlx_vars));
	if (!mlx)
		return (-1);
	ft_errors(argc, argv);
	ft_initilize(mlx, argv);
	print_window(mlx);
	mlx_key_hook(mlx->win, ft_keys, mlx);
	mlx_hook(mlx->win, 17, 0, exit_game, mlx);
	mlx_loop(mlx->mlx);
}

int	ft_initilize(t_mlx_vars *a, char **argv)
{
	a->steps = 0;
	ft_initilize_map(a, argv);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->xy[0] * 80, a->xy[1] * 80, "so_long");
	return (0);
}

int	exit_game(t_mlx_vars *mlx)
{
	int	a;

	a = 0;
	mlx_destroy_window(mlx->mlx, mlx->win);
	while (mlx->map[a] != 0)
		free(mlx->map[a++]);
	free(mlx->map);
	free(mlx);
	exit(EXIT_FAILURE);
}
