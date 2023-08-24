/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:47:49 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/24 17:50:14 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	set_julia(double x, double y, t_data *mlx)
{
	double	xo;
	double	yo;
	double	tmp;
	int		i;
	int		mi;

	xo = x;
	yo = y;
	i = 1;
	mi = mlx->iter;
	while (i < mi)
	{
		tmp = xo;
		xo = (pow(xo, 2) - pow(yo, 2)) + 0.133 + mlx->juliax;
		yo = (2 * tmp * yo) + 0.521 + mlx->juliay;
		if (pow(xo, 2) + pow(yo, 2) > 4)
		{
			my_mlx_pixel_put(mlx, mlx->loopx, mlx->loopy, get_color((double) \
			((i + 1 - log(log2(xo * xo + yo * yo))) / 2) / mi, mlx->color));
			return (0);
		}
		i++;
	}
	return (0);
}

int	julia(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx->img = mlx_new_image(mlx->mlx, SIZEX, SIZEY);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, 
			&mlx->line_length, &mlx->endian);
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			set_julia(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	run_julia(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Julia");
	mlx.xmin = -2.0;
	mlx.ymin = -1.5;
	mlx.xmax = 1.5;
	mlx.ymax = 2.0;
	mlx.color = 0;
	mlx.iter = 40;
	mlx.fractol = 2;
	julia(&mlx);
	mlx_key_hook(mlx.win, key, &mlx);
	mlx_mouse_hook(mlx.win, zoom, &mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, &mlx);
	mlx_loop(mlx.mlx);
}
