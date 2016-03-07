/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:32:52 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:41:29 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env				init_map(t_env ptr, char *name)
{
	ptr.i = -1;
	ptr.y = -1;
	ptr.pistol = 6;
	ptr.shoot = 0;
	ptr.img.width = WIDTH;
	ptr.img.height = HEIGHT;
	ptr.mlx = mlx_init();
	ptr.player.posx = 2;
	ptr.player.posy = 2;
	ptr.player.dirx = DIRX_EST;
	ptr.player.diry = DIRY_EST;
	ptr.player.planex = PLANEX_EST;
	ptr.player.planey = PLANEY_EST;
	ptr.player.move_speed = MSPEED;
	ptr.player.rot_speed = RSPEED;
	ptr.img.img = mlx_new_image(ptr.mlx, ptr.img.width, ptr.img.height);
	ptr.img.data = mlx_get_data_addr(ptr.img.img, &ptr.img.bpp,
			&ptr.img.sizeline, &ptr.img.endian);
	ptr.win = mlx_new_window(ptr.mlx, ptr.img.width, ptr.img.height, name);
	return (ptr);
}

t_env				init_new_map(t_env ptr)
{
	ptr.i = -1;
	ptr.y = -1;
	ptr.pistol = 6;
	ptr.shoot = 0;
	ptr.img.width = WIDTH;
	ptr.img.height = HEIGHT;
	ptr.mlx = mlx_init();
	ptr.player.posx = 2;
	ptr.player.posy = 2;
	ptr.player.dirx = DIRX_EST;
	ptr.player.diry = DIRY_EST;
	ptr.player.planex = PLANEX_EST;
	ptr.player.planey = PLANEY_EST;
	ptr.player.move_speed = MSPEED;
	ptr.player.rot_speed = RSPEED;
	return (ptr);
}

void				free_map(t_env *e)
{
	free(e->map);
	free(e->first);
}

void				load_new_map(t_env *e)
{
	free_map(e);
	read_map("test2", &(e->first), e);
	*e = create_2d_map(*e, -1, -1);
	*e = init_new_map(*e);
	mlx_string_put(e->mlx, e->win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF,
		"GOOD JOB LEVEL 2");
}
