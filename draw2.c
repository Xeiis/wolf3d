/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:22:53 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:39:18 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				draw_floor_next(t_env *e)
{
	e->distwall = e->ray.perpwalldist;
	if (e->draw.end < 0)
		e->draw.end = HEIGHT;
	draw_line_floor(e, e->draw.end);
}

void				draw_floor(t_env *e)
{
	if (e->side == 0 && e->cam.raydirx > 0)
	{
		e->floorxwall = e->mapx;
		e->floorywall = e->mapy + e->wallx;
	}
	else if (e->side == 0 && e->cam.raydirx < 0)
	{
		e->floorxwall = e->mapx + 1.0;
		e->floorywall = e->mapy + e->wallx;
	}
	else if (e->side == 1 && e->cam.raydiry > 0)
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy;
	}
	else
	{
		e->floorxwall = e->mapx + e->wallx;
		e->floorywall = e->mapy + 1.0;
	}
	draw_floor_next(e);
}
