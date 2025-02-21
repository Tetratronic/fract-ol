/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:41:55 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 15:45:10 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate_color(int c1, int c2, double local_t)
{
	t_rgb	v1;
	t_rgb	v2;
	t_rgb	result;

	v1.r = (c1 >> 16) & 0xFF;
	v1.g = (c1 >> 8) & 0xFF;
	v1.b = c1 & 0xFF;
	v2.r = (c2 >> 16) & 0xFF;
	v2.g = (c2 >> 8) & 0xFF;
	v2.b = c2 & 0xFF;
	result.r = v1.r + (v2.r - v1.r) * local_t;
	result.g = v1.g + (v2.g - v1.g) * local_t;
	result.b = v1.b + (v2.b - v1.b) * local_t;
	return ((result.r << 16) | (result.g << 8) | result.b);
}

int	get_color(double iteration, t_vars *vars)
{
	double	t;
	int		index;
	int		c1;
	int		c2;
	double	local_t;

	t = iteration / (double)MAX_ITER;
	index = (int)(t * 9);
	local_t = fmod(t * 9, 1.0);
	c1 = vars->color_scheme[index];
	c2 = vars->color_scheme[index + 1];
	return (interpolate_color(c1, c2, local_t));
}
