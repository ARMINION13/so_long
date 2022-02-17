/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:50:23 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/10 19:10:57 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_keys(int keycode, t_mlx_vars *mlx)
{
	if (keycode == W_KEY)
		ft_stepsv(mlx, -1);
	if (keycode == A_KEY)
		ft_stepsh(mlx, -1);
	if (keycode == S_KEY)
		ft_stepsv(mlx, 1);
	if (keycode == D_KEY)
		ft_stepsh(mlx, 1);
	if (keycode == ESC_KEY || mlx->ex_p[2] == 2)
		exit_game(mlx);
	if (mlx->col == 0)
		mlx->ex_p[2] = 0;
	print_window(mlx);
	return (0);
}

void	ft_stepsv(t_mlx_vars *a, int keycode)
{
	if (!ft_strchr("1", a->map[a->ply_p[1] + keycode][a->ply_p[0]]))
	{
		if (ft_strchr("C", a->map[a->ply_p[1] + keycode][a->ply_p[0]]))
			a->col -= 1;
		if (ft_strchr("E", a->map[a->ply_p[1] + keycode][a->ply_p[0]]))
		{
			if (a->ex_p[2] == 0)
				a->ex_p[2] = 2;
			return ;
		}
		a->map[a->ply_p[1] + keycode][a->ply_p[0]] = 'P';
		a->map[a->ply_p[1]][a->ply_p[0]] = '0';
		a->ply_p[1] += keycode;
		a->steps++;
		ft_printf("%i\n", a->steps);
	}
}

void	ft_stepsh(t_mlx_vars *a, int keycode)
{
	if (!ft_strchr("1", a->map[a->ply_p[1]][a->ply_p[0] + keycode]))
	{
		if (ft_strchr("C", a->map[a->ply_p[1]][a->ply_p[0] + keycode]))
			a->col -= 1;
		if (ft_strchr("E", a->map[a->ply_p[1]][a->ply_p[0] + keycode]))
		{
			if (a->ex_p[2] == 0)
				a->ex_p[2] = 2;
			return ;
		}
		a->map[a->ply_p[1]][a->ply_p[0] + keycode] = 'P';
		a->map[a->ply_p[1]][a->ply_p[0]] = '0';
		a->ply_p[0] += keycode;
		a->steps++;
		ft_printf("%i\n", a->steps);
	}
}
