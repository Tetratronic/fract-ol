/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:48:03 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/17 01:18:31 by abenkaro         ###   ########.fr       */
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
		y = fabs(2 * x * y) + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		iterations--;
	}
	return (iterations);
}

int	ship(int px, int py, t_view *view, t_vars *vars)
{
	double	w_center_x;
	double	w_center_y;
	double	x0;
	double	y0;
	int		iterations;

	w_center_x = 320.0;
	w_center_y = 240.0;
	x0 = (px - w_center_x) * 0.00625 / view->zoom + view->center_x;
	y0 = -(py - w_center_y) * 0.00625 / view->zoom + view->center_y;
	iterations = calculate_iterations(x0, y0);
	if (iterations <= 0)
		return (0);
	return (get_color(MAX_ITER - iterations, vars));
}
