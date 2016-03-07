/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 20:24:21 by dchristo          #+#    #+#             */
/*   Updated: 2016/03/07 14:49:34 by dchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define WIDTH 1400
# define HEIGHT 800
# define EXIT 53
# define TOP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define DIRX_EST 0
# define DIRY_EST 1
# define PLANEX_EST 0.66
# define PLANEY_EST 0
# define DIRX_SUD 1
# define DIRY_SUD 0
# define PLANEX_SUD 0
# define PLANEY_SUD 0.66
# define DIRX_OUEST 0
# define DIRY_OUEST -1
# define PLANEX_OUEST 0.66
# define PLANEY_OUEST 0
# define DIRX_NORD -1
# define DIRY_NORD 0
# define PLANEX_NORD 0
# define PLANEY_NORD 0.66
# define MSPEED 0.4
# define RSPEED 0.2

typedef struct		s_point
{
	int				x;
	int				y;
	int				val;
	struct s_point	*next;
}					t_point;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				width_xpm;
	int				width;
	int				height_xpm;
	int				height;
	char			name;
}					t_img;

typedef struct		s_player
{
	double			move_speed;
	double			rot_speed;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
}					t_player;

typedef struct		s_cam
{
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
}					t_cam;

typedef struct		s_ray
{
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
}					t_ray;

typedef struct		s_draw
{
	int				lineheight;
	int				start;
	int				end;
}					t_draw;

typedef struct		s_env
{
	int				i;
	int				y;
	void			*mlx;
	void			*win;
	void			*xpm;
	char			**map;
	int				nbcol;
	int				nbcol_save;
	int				nbline;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				x;
	int				mapx;
	int				mapy;
	int				pistol;
	int				shoot;
	int				tex_num;
	int				texx;
	int				texy;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			wallx;
	struct s_point	*first;
	t_img			img;
	t_img			text[13];
	t_cam			cam;
	t_player		player;
	t_ray			ray;
	t_draw			draw;
}					t_env;

void				arg_error(void);
void				map_error(void);
void				malloc_error(void);
void				open_error(void);
void				read_error(void);
int					key_hook(int keycode, t_env *e);
void				draw_line(t_env *e, int y_start, int y_end, int color);
void				raycast_it(t_env *e);
void				reload(t_env *e);
int					expose_hook(t_env *e);
void				key_hook_rot2(int keycode, t_env *e);
void				key_hook_rot(int keycode, t_env *e);
void				draw_line_text(t_env *e, int y_start, int y_end,
					t_img *text);
void				init_text(t_env *e);
void				put_pixel_text(t_env *e, int x, int y, t_img t);
int					mouse(int button, int x, int y, t_env *e);
void				init_text2(t_env *e);
void				put_pixel(t_img *img, int x, int y, int color);
void				load_new_map(t_env *e);
void				fps(t_env *e);
void				draw_line_floor(t_env *e, int y_start);
void				draw_floor_next(t_env *e);
void				draw_floor(t_env *e);
void				load_new_map(t_env *e);
void				free_map(t_env *e);
t_env				init_new_map(t_env ptr);
t_env				init_map(t_env ptr, char *name);
void				key_hook_tools(int keycode, t_env *e);
void				something_to_put(t_env *e);
int					read_map(char *str, t_point **point, t_env *env);
t_env				create_2d_map(t_env e, int i, int y);

#endif
