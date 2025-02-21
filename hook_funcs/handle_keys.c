/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:31:05 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 18:58:21 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hooks_local.h"

static void	reset_zoom(t_vars *vars)
{
	vars->view = (t_view){0, 0, 1.0};
	vars->zoom = (t_zoom){1.0, 1.0, 0.1, 0, 0, 0, 0};
}

static int	keymove(int button, t_vars *vars)
{
	if (button == 65361)
		vars->zoom.target_x -= 1 / vars->view.zoom;
	else if (button == 65362)
		vars->zoom.target_y += 1 / vars->view.zoom;
	else if (button == 65363)
		vars->zoom.target_x += 1 / vars->view.zoom;
	else if (button == 65364)
		vars->zoom.target_y -= 1 / vars->view.zoom;
	return (0);
}

int	handle_keys(int keycode, t_vars *vars)
{
	if (keycode == 49)
		default_colors(vars);
	else if (keycode == 50)
		deep_galaxy(vars);
	else if (keycode == 51)
		aurora(vars);
	else if (keycode == 52)
		cyberpunk(vars);
	else if (keycode == 53)
		elden_ring(vars);
	else if (keycode == 65307)
		close_win(vars);
	else if (keycode == 32)
		reset_zoom(vars);
	else if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
		keymove(keycode, vars);
	return (0);
}
