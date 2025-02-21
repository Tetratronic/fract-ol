/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:32:41 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/18 20:40:41 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_iterations(double x0, double y0)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iterations;

	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iterations = MAX_ITER;
	while (iterations > 0 && (x2 + y2 <= 4.0))
	{
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iterations--;
	}
	return (iterations);
}

int	in_main_shape(double x0, double y0)
{
	double	q;

	q = (x0 - 0.25) * (x0 - 0.25) + y0 * y0;
	if (q * (q + (x0 - 0.25)) <= 0.25 * y0 * y0
		|| (x0 + 1.0) * (x0 + 1.0) + y0 * y0 <= 0.0625)
		return (1);
	return (0);
}

int	mandelbrot(int px, int py, t_view *view, t_vars *vars)
{
	double	x0;
	double	y0;
	int		iterations;

	x0 = (px - 320) * 0.00625 / view->zoom + view->center_x;
	y0 = -(py - 240) * 0.00625 / view->zoom + view->center_y;
	if (in_main_shape(x0, y0))
		return (0);
	iterations = calculate_iterations(x0, y0);
	if (iterations <= 0)
		return (0);
	return (get_color(MAX_ITER - iterations, vars));
}
