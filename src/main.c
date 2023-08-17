/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:16:10 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/17 16:05:37 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char *argv[])
{
	t_data	mlx;

	mlx.fractol = 0;
	if (argc != 2)
		maps();
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 10))
			mlx.fractol = 1;
		else if (!ft_strncmp(argv[1], "Julia", 5))
			mlx.fractol = 2;
		else if (!ft_strncmp(argv[1], "Burningship", 11))
			mlx.fractol = 3;
		else
			maps();
		start(&mlx, 0);
	}
}

