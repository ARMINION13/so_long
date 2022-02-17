/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:43:32 by rgirondo          #+#    #+#             */
/*   Updated: 2021/10/07 19:15:04 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define ENTER_KEY 36

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
	void	*img[5];
	char	**map;
	int		ply_p[2];
	int		col;
	int		ex_p[3];
	int		xy[2];
	int		steps;
	int		errors;
}				t_mlx_vars;

int		ft_initilize(t_mlx_vars *a, char **argv);
char	**ft_split(char const *s, char c);
void	map_items(t_mlx_vars *a, int x, int y);
int		ft_readmap(t_mlx_vars *a);
int		ft_keys(int keycode, t_mlx_vars *mlx);
int		ft_initilize_map(t_mlx_vars *a, char **argv);
void	ft_stepsh(t_mlx_vars *mlx, int keycode);
void	ft_stepsv(t_mlx_vars *mlx, int keycode);
int		exit_game(t_mlx_vars *mlx);
int		print_window(t_mlx_vars *a);
void	over_floor(t_mlx_vars *a, int x, int y);
char	*malloc_map(int fd);
void	ft_errors(int argc, char **argv);
void	ft_map_errors(t_mlx_vars *mlx);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_map_sides(t_mlx_vars *a, int x, int y);
int		ft_not_double(t_mlx_vars *a);

#endif
