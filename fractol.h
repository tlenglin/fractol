/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:53:36 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 19:26:20 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1000
# define WIN_LENGTH 600
# define TXT 0xFFFFFF
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_calc
{
	float	cte1;
	float	cte2;
	float	cte3;
	float	cte4;
	float	tmp;
}				t_calc;

typedef struct	s_fract
{
	float	zn_r;
	float	zn_i;
	float	constante_r;
	float	constante_i;
	int		iter_max;
	int		type;
}				t_fract;

typedef struct	s_event
{
	float	zoom;
	float	x0;
	float	y0;
	int		motion;
}				t_event;

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_adr;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*img;
	t_fract	*fract;
	t_event	*event;
}				t_data;

int				ft_free(t_data *data);
int				ft_error(int error, t_data **data);
int				ft_set_fract(char *str, t_data *data);
int				key_func_management2(int keycode, t_data *data);
int				key_func_management3(int keycode, t_data *data);
int				key_func_management4(int keycode, t_data *data);
int				key_func_management5(int keycode, t_data *data);
int				key_func_management6(t_data *data);
int				key_func_management7(t_data *data);
int				key_func_management8(t_data *data);
int				key_func_management9(t_data *data);
int				key_func_management10(t_data *data);
int				mouse_func_management_bis(t_data *data);
int				ft_set_calc_n(t_data *data, t_calc *calc);
int				ft_parsing_color_n(t_data *data, int x, int y, int i);
int				ft_color_img_yellow_to_orange(t_data *data,
	int i, int x, int y);
int				ft_color_img_blue_to_yellow(t_data *data, int i, int x, int y);
int				ft_color_img_bis(t_data *data, int i, int x, int y);
int				ft_informations(t_data *data);
int				ft_mlx_init(t_data *data);
int				ft_alloc(t_data **data);
int				ft_color_img_n(t_data *data, int i, int c, t_coord coord);
int				ft_n_sequence(t_data *data, int x, int y);
int				ft_newton(t_data *data);
int				ft_mlx_management(t_data *data);
int				mouse_func_management(int button, int x, int y, t_data *data);
int				key_func_management(int keycode, t_data *data);
int				mouse_motion_manager(int x, int y, t_data *data);
int				ft_mj_sequence(t_data *data, int x, int y);
int				ft_mandelbrot(t_data *data);
int				ft_julia(t_data *data);
int				verif_circle(t_data *data);
int				ft_color_img(t_data *data, int i, int x, int y);
int				ft_display(t_data *data);
int				ft_instructions(t_data *data);

#endif
