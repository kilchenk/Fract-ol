/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:56:56 by kilchenk          #+#    #+#             */
/*   Updated: 2023/08/17 15:59:42 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	green(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, r, g, r));
}

static int	blue(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, g, r, g));
}

static int	red(long double t)
{
	int	r;
	int	g;
	int	b;

	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	return (create_trgb(0, r, g, b));
}

int	get_color(long double t, int c)
{
	if (c == 0)
		return (green(t));
	else if (c == 1)
		return (blue(t));
	else if (c == 2)
		return (red(t));
	else
		return (0x03E52525 * red(t));
}
