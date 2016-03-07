/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:33:28 by dchristo          #+#    #+#             */
/*   Updated: 2016/02/26 15:46:59 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fps(t_env *e)
{
	static int		timestamp;
	static int		fps;
	static int		fps_2;

	if (time(NULL) != timestamp)
	{
		fps_2 = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	mlx_string_put(e->mlx, e->win, 10, 15, 0xFFFFFF,
			ft_strjoin("FPS : ", ft_itoa(fps_2)));
}
