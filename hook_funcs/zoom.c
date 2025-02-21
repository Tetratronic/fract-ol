/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:38:33 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 21:22:13 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_out(int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = vars->view.center_x
		- (x - 320) * 0.00625 / vars->view.zoom;
	mouse_y = vars->view.center_y
		+ (y - 240) * 0.00625 / vars->view.zoom;
	vars->zoom.target_zoom /= 1.1;
	vars->zoom.target_x = mouse_x
		+ (x - 320) * 0.00625 / vars->zoom.target_zoom;
	vars->zoom.target_y = mouse_y
		- (y - 240) * 0.00625 / vars->zoom.target_zoom;
}

static void	zoom_in(int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = vars->view.center_x
		+ (x - 320) * 0.00625 / vars->view.zoom;
	mouse_y = vars->view.center_y
		- (y - 240) * 0.00625 / vars->view.zoom;
	vars->zoom.target_zoom *= 1.1;
	vars->zoom.target_x = mouse_x
		- (x - 320) * 0.00625 / vars->zoom.target_zoom;
	vars->zoom.target_y = mouse_y
		+ (y - 240) * 0.00625 / vars->zoom.target_zoom;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		zoom_in(x, y, vars);
	if (button == 5)
		zoom_out(x, y, vars);
	return (0);
}
