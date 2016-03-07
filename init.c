/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:46:03 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:36:38 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_text2(t_env *e)
{
	int i;

	i = -1;
	e->text[12].img = mlx_xpm_file_to_image(e->mlx, "img/ceil4.xpm",
		&e->text[12].width_xpm, &e->text[12].height_xpm);
	while (++i < 13)
	{
		e->text[i].data = mlx_get_data_addr(e->text[i].img, &e->text[i].bpp,
			&e->text[i].sizeline, &e->text[i].endian);
		e->text[i].width = 0;
		e->text[i].height = 0;
	}
	i = -1;
	while (++i < 6)
		e->text[i].name = 't';
	i--;
	while (++i < 11)
		e->text[i].name = 'p';
	i--;
	while (++i < 13)
		e->text[i].name = 't';
}

void			init_text(t_env *e)
{
	e->text[0].img = mlx_xpm_file_to_image(e->mlx, "img/wall1v.xpm",
		&e->text[0].width_xpm, &e->text[0].height_xpm);
	e->text[1].img = mlx_xpm_file_to_image(e->mlx, "img/wall2v.xpm",
		&e->text[1].width_xpm, &e->text[1].height_xpm);
	e->text[2].img = mlx_xpm_file_to_image(e->mlx, "img/wall3v.xpm",
		&e->text[2].width_xpm, &e->text[2].height_xpm);
	e->text[3].img = mlx_xpm_file_to_image(e->mlx, "pics/wood.xpm",
		&e->text[3].width_xpm, &e->text[3].height_xpm);
	e->text[4].img = mlx_xpm_file_to_image(e->mlx, "pics/cloud.xpm",
		&e->text[4].width_xpm, &e->text[4].height_xpm);
	e->text[5].img = mlx_xpm_file_to_image(e->mlx, "img/ceil1.xpm",
		&e->text[5].width_xpm, &e->text[5].height_xpm);
	e->text[6].img = mlx_xpm_file_to_image(e->mlx, "img/pistol1.xpm",
		&e->text[6].width_xpm, &e->text[6].height_xpm);
	e->text[7].img = mlx_xpm_file_to_image(e->mlx, "img/pistol2.xpm",
		&e->text[7].width_xpm, &e->text[7].height_xpm);
	e->text[8].img = mlx_xpm_file_to_image(e->mlx, "img/pistol3.xpm",
		&e->text[8].width_xpm, &e->text[8].height_xpm);
	e->text[9].img = mlx_xpm_file_to_image(e->mlx, "img/pistol4.xpm",
		&e->text[9].width_xpm, &e->text[9].height_xpm);
	e->text[10].img = mlx_xpm_file_to_image(e->mlx, "img/pistol5.xpm",
		&e->text[10].width_xpm, &e->text[10].height_xpm);
	e->text[11].img = mlx_xpm_file_to_image(e->mlx, "img/ceil1.xpm",
		&e->text[11].width_xpm, &e->text[11].height_xpm);
	init_text2(e);
}
