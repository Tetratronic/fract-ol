/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:15:38 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/18 20:04:00 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_iterations_julia(double x0, double y0, t_vars *vars)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		iterations;

	x = x0;
	y = y0;
	x2 = x * x;
	y2 = y * y;
	iterations = MAX_ITER;
	while (iterations > 0 && (x2 + y2 <= 4.0))
	{
		y = 2 * x * y + vars->ci;
		x = x2 - y2 + vars->c;
		x2 = x * x;
		y2 = y * y;
		iterations--;
	}
	return (iterations);
}

int	julia(int px, int py, t_view *view, t_vars *vars)
{
	double	x0;
	double	y0;
	int		iterations;

	x0 = (px - 320) * 0.00625 / view->zoom + view->center_x;
	y0 = -(py - 240) * 0.00625 / view->zoom + view->center_y;
	iterations = calculate_iterations_julia(x0, y0, vars);
	if (iterations <= 0)
		return (0);
	return (get_color(MAX_ITER - iterations, vars));
}
