/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchisto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:37:17 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:49:06 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				key_hook_move(int keycode, t_env *e)
{
	double posy;
	double posx;

	if (keycode == TOP || keycode == 126)
	{
		posx = e->player.posx + e->player.dirx * e->player.move_speed;
		posy = e->player.posy + e->player.diry * e->player.move_speed;
		e->player.posx += e->map[(int)posx][(int)e->player.posy] == 0 ?
			e->player.dirx * e->player.move_speed : 0;
		e->player.posy += e->map[(int)e->player.posx][(int)posy] == 0 ?
			e->player.diry * e->player.move_speed : 0;
	}
	if (keycode == DOWN || keycode == 125)
	{
		posx = e->player.posx - e->player.dirx * e->player.move_speed;
		posy = e->player.posy - e->player.diry * e->player.move_speed;
		e->player.posx -= e->map[(int)posx][(int)e->player.posy] == 0 ?
			e->player.dirx * e->player.move_speed : 0;
		e->player.posy -= e->map[(int)e->player.posx][(int)posy] == 0 ?
			e->player.diry * e->player.move_speed : 0;
	}
}

int					key_hook(int keycode, t_env *e)
{
	key_hook_tools(keycode, e);
	key_hook_rot(keycode, e);
	key_hook_move(keycode, e);
	return (0);
}

void				something_to_put2(t_env *e)
{
	double posy;
	double posx;

	posx = e->player.posx + 1;
	posy = e->player.posy + 1;
	if (e->map[(int)posx][(int)e->player.posy] == 6)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Break the wall");
	if (e->map[(int)posx][(int)e->player.posy] == 7)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Next level !");
	if (e->map[(int)e->player.posx][(int)posy] == 6)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Break the wall");
	if (e->map[(int)e->player.posx][(int)posy] == 7)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Next level !");
}

void				something_to_put(t_env *e)
{
	double posy;
	double posx;

	posx = e->player.posx - 1;
	posy = e->player.posy - 1;
	if (e->map[(int)posx][(int)e->player.posy] == 6)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Break the wall");
	if (e->map[(int)posx][(int)e->player.posy] == 7)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Next level !");
	if (e->map[(int)e->player.posx][(int)posy] == 6)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Break the wall");
	if (e->map[(int)e->player.posx][(int)posy] == 7)
		mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
			"[E] Next level !");
	something_to_put2(e);
}
