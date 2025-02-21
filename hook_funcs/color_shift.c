/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:23:06 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 15:03:26 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	default_colors(t_vars *vars)
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

void	aurora(t_vars *vars)
{
	vars->color_scheme[0] = 0x000B19;
	vars->color_scheme[1] = 0x004242;
	vars->color_scheme[2] = 0x006B6B;
	vars->color_scheme[3] = 0x009494;
	vars->color_scheme[4] = 0x00BD8F;
	vars->color_scheme[5] = 0x2EE6A8;
	vars->color_scheme[6] = 0x89FFD6;
	vars->color_scheme[7] = 0xBFFFF1;
	vars->color_scheme[8] = 0x7CD8FF;
	vars->color_scheme[9] = 0xE8FFFF;
}

void	deep_galaxy(t_vars *vars)
{
	vars->color_scheme[0] = 0x000B2B;
	vars->color_scheme[1] = 0x002A54;
	vars->color_scheme[2] = 0x005B94;
	vars->color_scheme[3] = 0x0089BA;
	vars->color_scheme[4] = 0x00B6BC;
	vars->color_scheme[5] = 0x00D4B2;
	vars->color_scheme[6] = 0x20E5BE;
	vars->color_scheme[7] = 0x57E1DC;
	vars->color_scheme[8] = 0xB4F1F1;
	vars->color_scheme[9] = 0xE2FFFF;
}

void	cyberpunk(t_vars *vars)
{
	vars->color_scheme[0] = 0x000B19;
	vars->color_scheme[1] = 0x2D00FF;
	vars->color_scheme[2] = 0x00FFE1;
	vars->color_scheme[3] = 0xFF00D4;
	vars->color_scheme[4] = 0x00FF8F;
	vars->color_scheme[5] = 0x9300FF;
	vars->color_scheme[6] = 0xFF0059;
	vars->color_scheme[7] = 0x00FFBB;
	vars->color_scheme[8] = 0xFF00F7;
	vars->color_scheme[9] = 0x7BFFF9;
}

void	elden_ring(t_vars *vars)
{
	vars->color_scheme[0] = 0x000814;
	vars->color_scheme[1] = 0x8B4513;
	vars->color_scheme[2] = 0xCD853F;
	vars->color_scheme[3] = 0xDAA520;
	vars->color_scheme[4] = 0xFFD700;
	vars->color_scheme[5] = 0xFFC125;
	vars->color_scheme[6] = 0x5599DD;
	vars->color_scheme[7] = 0x206BCB;
	vars->color_scheme[8] = 0x0025A0;
	vars->color_scheme[9] = 0x000764;
}
