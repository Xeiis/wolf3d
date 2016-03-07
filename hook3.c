/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:29:59 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:38:28 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			make_pistol_bigger(t_env *e, int width, int height,
					t_img text)
{
	int x;
	int y;
	int color;

	text.height = 0;
	text.width = 0;
	x = -1;
	while (++x < 68 * 6)
	{
		y = -1;
		while (++y < 68 * 6)
		{
			color = text.data[text.height * text.sizeline + (text.bpp / 8) *
				text.width] + text.data[text.height * text.sizeline +
				(text.bpp / 8) * text.width + 1] * 256 +
				text.data[text.height * text.sizeline + (text.bpp / 8) *
				text.width + 2] * 65536;
			if (color != -65793)
				put_pixel_text(e, width + x, height + y, text);
			text.height += y % 3 == 0 ? 1 : 0;
		}
		text.height = 0;
		text.width += x % 3 == 0 ? 1 : 0;
	}
}

int					mouse(int button, int x, int y, t_env *e)
{
	x = y;
	y = x;
	if (button == 1 && e->shoot == 0)
		e->shoot = 1;
	return (1);
}

void				display_weapon(t_env *e)
{
	if (e->shoot == 1)
		e->pistol++;
	if (e->pistol > 10)
	{
		e->pistol = 6;
		e->shoot = 0;
	}
	make_pistol_bigger(e, WIDTH - e->text[e->pistol].width_xpm * 4.5,
			HEIGHT - e->text[e->pistol].height_xpm * 3 + 5, e->text[e->pistol]);
}

int					expose_hook(t_env *e)
{
	init_text2(e);
	raycast_it(e);
	display_weapon(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	something_to_put(e);
	fps(e);
	return (1);
}

void				reload(t_env *e)
{
	init_text2(e);
	mlx_destroy_image(e->mlx, e->img.img);
	e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.data = mlx_get_data_addr(e->img.img, &e->img.bpp,
			&e->img.sizeline, &e->img.endian);
	raycast_it(e);
	mlx_clear_window(e->mlx, e->win);
	make_pistol_bigger(e, WIDTH - e->text[e->pistol].width_xpm * 4.5,
			HEIGHT - e->text[e->pistol].height_xpm * 3 + 5, e->text[e->pistol]);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	something_to_put(e);
}
