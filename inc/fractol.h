/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:05:10 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/24 17:50:00 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define SIZEX 1080
# define SIZEY 760

// ================================= LIBRARIES ============================== //

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"
# include "../Libft/ft_printf.h"
# include <math.h>

// ================================= COLORS ================================= //

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue

// ================================= STRUCTURES ============================= //

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*img_addr;
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	juliax;
	double	juliay;
	double	color;
	int		iter; 
	int		fractol;
	int		loopx;
	int		loopy;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// ================================= FUNCTIONS ============================== //

void	maps(void);
void	start(t_data *mlx, int flag);
void	run_mandelbort(void);
void	run_julia(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	run_burningship(void);
int		mandelbrot(t_data *mlx);
int		julia(t_data *mlx);
int		burningship(t_data *mlx);
int		get_color(long double t, int c);
int		key(int num, t_data *mlx);
int		ft_exit(t_data *mlx);
int		zoom(int num, int x, int y, t_data *mlx);
#endif
