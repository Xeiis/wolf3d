/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:21:21 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:24:00 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_img			*text(t_env *e)
{
	if (e->side == 0 && e->stepx == -1 && e->map[e->mapx][e->mapy] != 0)
		return (&(e->text[0]));
	if (e->side == 0 && e->stepx == 1 && e->map[e->mapx][e->mapy] != 0)
		return (&(e->text[1]));
	if (e->side == 1 && e->stepy == -1 && e->map[e->mapx][e->mapy] != 0)
		return (&(e->text[2]));
	if (e->side == 1 && e->stepy == 1 && e->map[e->mapx][e->mapy] != 0)
		return (&(e->text[3]));
	return (NULL);
}

static void				init_raycast(t_env *e)
{
	e->hit = 0;
	e->cam.camerax = 2 * e->x / (double)WIDTH - 1;
	e->cam.rayposx = e->player.posx;
	e->cam.rayposy = e->player.posy;
	e->cam.raydirx = e->player.dirx + e->player.planex * e->cam.camerax;
	e->cam.raydiry = e->player.diry + e->player.planey * e->cam.camerax;
	e->mapx = (int)e->cam.rayposx;
	e->mapy = (int)e->cam.rayposy;
	e->ray.deltadistx = sqrt(1 + (e->cam.raydiry * e->cam.raydiry) /
		(e->cam.raydirx * e->cam.raydirx));
	e->ray.deltadisty = sqrt(1 + (e->cam.raydirx * e->cam.raydirx) /
		(e->cam.raydiry * e->cam.raydiry));
	if (e->cam.raydirx < 0)
	{
		e->stepx = -1;
		e->ray.sidedistx = (e->cam.rayposx - e->mapx) * e->ray.deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->ray.sidedistx = (e->mapx + 1.0 - e->cam.rayposx) * e->ray.deltadistx;
	}
}

static void				calc_text(t_env *e)
{
	if (e->side == 0)
		e->wallx = e->cam.rayposy + e->ray.perpwalldist * e->cam.raydiry;
	else
		e->wallx = e->cam.rayposx + e->ray.perpwalldist * e->cam.raydirx;
	e->wallx -= floor((e->wallx));
	e->texx = (int)(e->wallx * (double)64);
	if ((e->side == 0 && e->cam.raydirx > 0) ||
			(e->side == 1 && e->cam.raydiry < 0))
		e->texx = 64 - e->texx - 1;
}

static void				calc_and_draw_line(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->ray.sidedistx < e->ray.sidedisty)
		{
			e->ray.sidedistx += e->ray.deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->ray.sidedisty += e->ray.deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		e->hit = e->map[e->mapx][e->mapy] > 0 ? 1 : 0;
	}
	e->ray.perpwalldist = e->side == 0 ?
		(e->mapx - e->cam.rayposx + (1 - e->stepx) / 2) / e->cam.raydirx :
		(e->mapy - e->cam.rayposy + (1 - e->stepy) / 2) / e->cam.raydiry;
	e->draw.lineheight = e->ray.perpwalldist == 0 ?
		(int)HEIGHT : (int)(HEIGHT / e->ray.perpwalldist);
	e->draw.start = -e->draw.lineheight / 2 + HEIGHT / 2;
	e->draw.start = e->draw.start < 0 ? 0 : e->draw.start;
	e->draw.end = e->draw.lineheight / 2 + HEIGHT / 2;
	e->draw.end = e->draw.end >= HEIGHT ? HEIGHT - 1 : e->draw.end;
}

void					raycast_it(t_env *e)
{
	e->x = -1;
	while (++e->x < WIDTH)
	{
		init_raycast(e);
		if (e->cam.raydiry < 0)
		{
			e->stepy = -1;
			e->ray.sidedisty = (e->cam.rayposy - e->mapy) * e->ray.deltadisty;
		}
		else
		{
			e->stepy = 1;
			e->ray.sidedisty = (e->mapy + 1.0 - e->cam.rayposy) *
				e->ray.deltadisty;
		}
		calc_and_draw_line(e);
		calc_text(e);
		draw_line_text(e, e->draw.start, e->draw.end, text(e));
		draw_floor(e);
	}
}
