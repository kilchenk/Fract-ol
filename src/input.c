/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:03:19 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:23 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	maps(void)
{
	ft_printf(R"Error-->Usage: ./fractol [fractal]\n"E);
	ft_printf(R"Fractals :\n1.Mandelbrot\n2.Julia\n3.Burning ship\n"E);
}

void	start(t_data *mlx, int flag)
{
	if (mlx->fractol == 1)
	{
		if (flag)
			mandelbrot(mlx);
		else
			run_mandelbort();
	}
	// if (mlx->fractol == 2)
	// {
	// 	if (flag)
	// 		julia();
	// 	else
	// 		run_julia();
	// }
	// if (mlx->fractol == 3)
	// {
	// 	if (flag)	
}
