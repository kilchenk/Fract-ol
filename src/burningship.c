/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:52:08 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/24 17:50:12 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	set_burningship(double x, double y, t_data *mlx)
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
		xo = ((xo * xo) - (yo * yo)) - x;
		yo = fabs(2 * tmp * yo) - y;
		if ((xo * xo) + (yo * xo) > 4)
		{
			my_mlx_pixel_put(mlx, mlx->loopx, mlx->loopy, get_color((double) \
			((i + 1 - log(log2(xo * xo + yo * yo))) / 2) / mi, mlx->color));
			return (0);
		}
		i++;
	}
	return (0);
}

int	burningship(t_data *mlx)
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
			set_burningship(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	run_burningship(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.color = 0;
	mlx.fractol = 3;
	mlx.iter = 60;
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Burning ship");
	mlx.xmax = 1.5;
	mlx.xmin = -2.0;
	mlx.ymax = 2.0;
	mlx.ymin = -1.5;
	burningship(&mlx);
	mlx_key_hook(mlx.win, key, &mlx);
	mlx_mouse_hook(mlx.win, zoom, &mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, &mlx);
	mlx_loop(mlx.mlx);
}
