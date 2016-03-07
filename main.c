/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:55:32 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:42:20 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_point		*save_point(t_point **point, char *line, t_env *env)
{
	t_point			*p;

	env->nbcol = -1;
	p = *point;
	while (line[++env->nbcol] != '\0')
	{
		p->val = line[env->nbcol] - 48;
		if ((p->next = (t_point*)malloc(sizeof(t_point))) == NULL)
			malloc_error();
		p = p->next;
	}
	if ((env->nbcol == 0 || env->nbcol_save != env->nbcol) && env->nbline != 0)
		map_error();
	else
		env->nbcol_save = env->nbcol;
	p->next = NULL;
	return (p);
}

int					read_map(char *str, t_point **point, t_env *env)
{
	int				fd;
	int				ret;
	char			*line;
	t_point			*p;

	p = *point;
	env->nbline = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		open_error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		p = save_point(&p, line, env);
		env->nbline++;
	}
	if (ret == -1)
		read_error();
	return (1);
}

t_env				create_2d_map(t_env e, int i, int y)
{
	t_point			*p;

	p = e.first;
	if ((e.map = (char **)malloc(e.nbline * sizeof(char *))) == NULL)
		malloc_error();
	while (++i < e.nbline)
		if ((e.map[i] = ft_strnew(e.nbcol)) == NULL)
			malloc_error();
	i = -1;
	while (++i < e.nbline)
	{
		y = -1;
		while (++y < e.nbcol)
		{
			e.map[i][y] = p->val;
			p = p->next;
		}
	}
	return (e);
}

int					main(void)
{
	t_env			env;

	if ((env.first = (t_point *)malloc(sizeof(t_point))) == NULL)
		malloc_error();
	read_map("test", &env.first, &env);
	env = create_2d_map(env, -1, -1);
	env = init_map(env, "Wolf3D Level 1 !");
	init_text(&env);
	mlx_mouse_hook(env.win, mouse, &env);
	mlx_hook(env.win, 2, 1, key_hook, &env);
	mlx_loop_hook(env.mlx, &expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
