/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:39:00 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/18 20:08:55 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_frame(t_vars *vars, int (*set)(int, int, t_view *, t_vars *))
{	
	int	i;
	int	j;

	i = -1;
	while (++i < 640)
	{
		j = -1;
		while (++j < 480)
			p_put(&vars->img, i, j, set(i, j, &vars->view, vars));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	animation_loop(t_vars *vars)
{
	vars->zoom.current_zoom
		+= (vars->zoom.target_zoom - vars->zoom.current_zoom) * 1;
	vars->zoom.current_x
		+= (vars->zoom.target_x - vars->zoom.current_x) * 1;
	vars->zoom.current_y
		+= (vars->zoom.target_y - vars->zoom.current_y) * 1;
	vars->view.zoom = vars->zoom.current_zoom;
	vars->view.center_x = vars->zoom.current_x;
	vars->view.center_y = vars->zoom.current_y;
	render_frame(vars, vars->set);
	return (0);
}
