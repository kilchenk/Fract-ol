/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:06:53 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/23 12:51:04 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	zoom(int num, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
	if (num == 4)
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.2));
		mlx->xmax = (mlx->xmax + ((dx *(SIZEX - x)) * 0.2));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.2));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y)) * 0.2));
		mlx->iter -= 1;
	}
	else if (num == 5)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.2));
		mlx->xmax = (mlx->xmax - ((dx *(SIZEX - x)) * 0.2));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.2));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y)) * 0.2));
		mlx->iter += 1;
	}
	start(mlx, 1);
	return (0);
}

void	moves(int num, t_data *mlx)
{
	float	dx;
	float	dy;

	if (num == 53)
		ft_exit(mlx);
	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (num == 123 || num == 124)
	{
		if (num == 123)
			dx *= -1;
		mlx->xmin += dx / 7.5;
		mlx->xmax += dx / 7.5;
	}
	if (num == 125 || num == 126)
	{
		if (num == 125)
			dy *= -1;
		mlx->ymin += dy / 7.5;
		mlx->ymax += dy / 7.5;
	}
}

int	key(int num, t_data *mlx)
{
	if (num == 123 || num == 124 || num == 125 || num == 126
		|| num == 53)
		moves(num, mlx);
	if (num == 49)
	{
		if (mlx->color == 3)
			mlx->color = 0;
		else
			mlx->color += 1;
	}
	if (num == 0)
		mlx->juliax -= 0.2;
	if (num == 1)
		mlx->juliay += 0.2;
	if (num == 2)
		mlx->juliax += 0.2;
	if (num == 13)
		mlx->juliay -= 0.2;
	start(mlx, 1);
	return (0);
}
