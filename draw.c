/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:36:25 by ldubos            #+#    #+#             */
/*   Updated: 2016/03/07 14:37:47 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				put_pixel(t_img *img, int x, int y, int color)
{
	char			*pixel;

	if ((x < img->width && y < img->height) && (x >= 0 && y >= 0))
	{
		pixel = img->data + y * img->sizeline + (img->bpp / 8) * x;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}

void				draw_line(t_env *e, int y_start, int y_end, int color)
{
	y_start -= 1;
	while (++y_start < y_end)
		put_pixel(&e->img, e->x, y_start, color);
}

void				put_pixel_text(t_env *e, int x, int y, t_img t)
{
	char			*pixel;
	char			*text;
	int				i;

	i = -1;
	if ((x < e->img.width && y < e->img.height) && (x >= 0 && y >= 0))
	{
		pixel = e->img.data + y * e->img.sizeline + (e->img.bpp / 8) * x;
		if (t.name != 'p')
			text = t.data + e->texy * t.sizeline + (t.bpp / 8) * e->texx;
		else
			text = t.data + t.height * t.sizeline + (t.bpp / 8) * t.width;
		pixel[2] = text[2];
		pixel[1] = text[1];
		pixel[0] = text[0];
	}
}

void				draw_line_text(t_env *e, int y_start, int y_end,
					t_img *text)
{
	int d;

	if (text == NULL)
		return ;
	y_start -= 1;
	while (++y_start < y_end)
	{
		d = y_start * 256 - HEIGHT * 128 + e->draw.lineheight * 128;
		e->texy = ((d * 64) / e->draw.lineheight) / 256;
		put_pixel_text(e, e->x, y_start, *text);
	}
}

void				draw_line_floor(t_env *e, int y_start)
{
	double weight;
	double currentfloorx;
	double currentfloory;

	y_start -= 1;
	while (++y_start < HEIGHT)
	{
		e->currentdist = HEIGHT / (2.0 * y_start - HEIGHT);
		weight = e->currentdist / e->distwall;
		currentfloorx = weight * e->floorxwall + (1.0 - weight) *
			e->player.posx;
		currentfloory = weight * e->floorywall + (1.0 - weight) *
			e->player.posy;
		e->texx = (int)(currentfloorx * e->text[11].width_xpm) %
			e->text[11].width_xpm;
		e->texy = (int)(currentfloory * e->text[11].height_xpm) %
			e->text[11].height_xpm;
		put_pixel_text(e, e->x, y_start, e->text[11]);
		put_pixel_text(e, e->x, HEIGHT - y_start, e->text[12]);
	}
}
