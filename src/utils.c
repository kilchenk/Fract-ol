/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:31 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/14 16:56:29 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_exit(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}
