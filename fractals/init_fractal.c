/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:30:37 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/18 20:41:10 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	protected_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 640, 480, "Fractol");
	vars->img.img = mlx_new_image(vars->mlx, 640, 480);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (!vars->mlx || !vars->win || !vars->img.img || !vars->img.addr)
	{
		free (vars->mlx);
		free (vars->win);
		free (vars->img.img);
		free (vars->img.addr);
		close_win(vars);
		exit(0);
	}
}

static void	set_colors(t_vars *vars)
{	
	vars->color_scheme[0] = 0x000764;
	vars->color_scheme[1] = 0x0025A0;
	vars->color_scheme[2] = 0x206BCB;
	vars->color_scheme[3] = 0x5599DD;
	vars->color_scheme[4] = 0xAADDFF;
	vars->color_scheme[5] = 0xEDFFFF;
	vars->color_scheme[6] = 0xFFD980;
	vars->color_scheme[7] = 0xFFAA00;
	vars->color_scheme[8] = 0x804000;
	vars->color_scheme[9] = 0x000200;
}

void	init_fractal(int (*set)(int, int, t_view *, t_vars *), t_vars *vars)
{
	vars->set = set;
	vars->view = (t_view){0, 0, 1.0};
	vars->zoom = (t_zoom){1.0, 1.0, 0.1, 0, 0, 0, 0};
	set_colors(vars);
	protected_init(vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, animation_loop, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_win, vars);
	mlx_key_hook(vars->win, handle_keys, vars);
	mlx_loop(vars->mlx);
}
