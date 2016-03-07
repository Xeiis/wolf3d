/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:57:10 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:38:39 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				key_hook_rot2(int keycode, t_env *e)
{
	double olddirx;
	double oldplanex;

	if (keycode == LEFT || keycode == 123)
	{
		olddirx = e->player.dirx;
		e->player.dirx = e->player.dirx * cos(e->player.rot_speed) -
			e->player.diry * sin(e->player.rot_speed);
		e->player.diry = olddirx * sin(e->player.rot_speed) +
			e->player.diry * cos(e->player.rot_speed);
		oldplanex = e->player.planex;
		e->player.planex = e->player.planex * cos(e->player.rot_speed) -
			e->player.planey * sin(e->player.rot_speed);
		e->player.planey = oldplanex * sin(e->player.rot_speed) +
			e->player.planey * cos(e->player.rot_speed);
	}
}

void				key_hook_rot(int keycode, t_env *e)
{
	double olddirx;
	double oldplanex;

	if (keycode == RIGHT || keycode == 124)
	{
		olddirx = e->player.dirx;
		e->player.dirx = e->player.dirx * cos(-e->player.rot_speed) -
			e->player.diry * sin(-e->player.rot_speed);
		e->player.diry = olddirx * sin(-e->player.rot_speed) +
			e->player.diry * cos(-e->player.rot_speed);
		oldplanex = e->player.planex;
		e->player.planex = e->player.planex * cos(-e->player.rot_speed) -
			e->player.planey * sin(-e->player.rot_speed);
		e->player.planey = oldplanex * sin(-e->player.rot_speed) +
			e->player.planey * cos(-e->player.rot_speed);
	}
	key_hook_rot2(keycode, e);
}

void				keycode_14(t_env *e)
{
	double posy;
	double posx;

	posx = e->player.posx - 1;
	posy = e->player.posy - 1;
	if (e->map[(int)posx][(int)e->player.posy] == 6)
		e->map[(int)posx][(int)e->player.posy] = 0;
	if (e->map[(int)e->player.posx][(int)posy] == 6)
		e->map[(int)e->player.posx][(int)posy] = 0;
	posx = e->player.posx + 1;
	posy = e->player.posy + 1;
	if (e->map[(int)posx][(int)e->player.posy] == 6)
		e->map[(int)posx][(int)e->player.posy] = 0;
	if (e->map[(int)e->player.posx][(int)posy] == 6)
		e->map[(int)e->player.posx][(int)posy] = 0;
}

void				keycode_14_2(t_env *e)
{
	double posy;
	double posx;

	posx = e->player.posx - 1;
	posy = e->player.posy - 1;
	if (e->map[(int)posx][(int)e->player.posy] == 7)
		load_new_map(e);
	if (e->map[(int)e->player.posx][(int)posy] == 7)
		load_new_map(e);
	posx = e->player.posx + 1;
	posy = e->player.posy + 1;
	if (e->map[(int)posx][(int)e->player.posy] == 7)
		load_new_map(e);
	if (e->map[(int)e->player.posx][(int)posy] == 7)
		load_new_map(e);
}

void				key_hook_tools(int keycode, t_env *e)
{
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	if (keycode == 14)
	{
		keycode_14(e);
		keycode_14_2(e);
	}
}
