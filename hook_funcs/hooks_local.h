/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_local.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:02 by abenkaro          #+#    #+#             */
/*   Updated: 2025/02/16 00:39:59 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_LOCAL_H
# define HOOKS_LOCAL_H

void	default_colors(t_vars *vars);
void	aurora(t_vars *vars);
void	deep_galaxy(t_vars *vars);
void	cyberpunk(t_vars *vars);
int		handle_keys(int keycode, t_vars *vars);
void	elden_ring(t_vars *vars);

#endif
