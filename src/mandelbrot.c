/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:17:56 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/17 19:25:23 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	set_mandelbrot(double x, double y, t_data *mlx)
{
	int		i;
	int		mi;
	double	xo;
	double	yo;
	double	tmp;

	xo = 0;
	yo = 0;
	i = 1;
	mi = mlx->iter;
	while (i < mi)
	{
		tmp = xo;
		xo = (pow(xo, 2) - pow(yo, 2)) + x;
		yo = (2 * tmp * yo) + y;
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

int	mandelbrot(t_data *mlx)
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
			set_mandelbrot(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	run_mandelbort(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Mandelbrot");
	mlx.xmin = -2.0;
	mlx.xmax = 1.5;
	mlx.ymin = -1.5;
	mlx.ymax = 2;
	mlx.color = 0;
	mlx.iter = 60;
	mlx.fractol = 1;
	mandelbrot(&mlx);
	mlx_key_hook(mlx.win, key, &mlx);
	mlx_mouse_hook(mlx.win, zoom, &mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, &mlx);
	mlx_loop(mlx.mlx);
}
