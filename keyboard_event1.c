/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:03:56 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/15 12:05:20 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func_management(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 82 || keycode == 46)
		key_func_management2(keycode, data);
	if (keycode == 83 || keycode == 84)
		key_func_management3(keycode, data);
	if (keycode == 123 || keycode == 124)
		key_func_management4(keycode, data);
	if (keycode == 125 || keycode == 12)
		key_func_management5(keycode, data);
	if (keycode == 15)
		key_func_management6(data);
	if (keycode == 13)
		key_func_management7(data);
	if (keycode == 126)
		key_func_management8(data);
	if (keycode == 69)
		key_func_management9(data);
	if (keycode == 78)
		key_func_management10(data);
	return (0);
}

int	key_func_management2(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free(data->img->img_adr);
		ft_free(data);
		exit(0);
	}
	if (keycode == 82 && data->fract->type != 0)
	{
		data->fract->type = 0;
		data->fract->iter_max = 100;
		data->event->x0 = 0;
		data->event->y0 = 0;
		data->event->zoom = 1;
		ft_mandelbrot(data);
		ft_display(data);
	}
	if (keycode == 46 && data->fract->type == 1)
	{
		if (data->event->motion == 0)
			data->event->motion = 1;
		else if (data->event->motion == 1)
			data->event->motion = 0;
	}
	ft_mlx_management(data);
	return (0);
}

int	key_func_management3(int keycode, t_data *data)
{
	if (keycode == 83 && data->fract->type != 1)
	{
		data->fract->type = 1;
		data->fract->iter_max = 100;
		data->event->x0 = 0;
		data->event->y0 = 0;
		data->event->zoom = 1;
		data->fract->constante_r = 0;
		data->fract->constante_i = 0;
		ft_julia(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	if (keycode == 84 && data->fract->type != 2)
	{
		data->fract->type = 2;
		data->fract->iter_max = 100;
		data->event->x0 = 0;
		data->event->y0 = 0;
		data->event->zoom = 1;
		ft_newton(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	return (0);
}

int	key_func_management4(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->event->x0 -= 0.2 / data->event->zoom;
		if (data->fract->type == 0)
			ft_mandelbrot(data);
		else if (data->fract->type == 1)
			ft_julia(data);
		else if (data->fract->type == 2)
			ft_newton(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	if (keycode == 124)
	{
		data->event->x0 += 0.2 / data->event->zoom;
		if (data->fract->type == 0)
			ft_mandelbrot(data);
		else if (data->fract->type == 1)
			ft_julia(data);
		else if (data->fract->type == 2)
			ft_newton(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	return (0);
}

int	key_func_management5(int keycode, t_data *data)
{
	if (keycode == 125)
	{
		data->event->y0 += 0.5 / data->event->zoom;
		if (data->fract->type == 0)
			ft_mandelbrot(data);
		else if (data->fract->type == 1)
			ft_julia(data);
		else if (data->fract->type == 2)
			ft_newton(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	if (keycode == 12)
	{
		data->fract->iter_max += 50;
		if (data->fract->type == 0)
			ft_mandelbrot(data);
		else if (data->fract->type == 1)
			ft_julia(data);
		else if (data->fract->type == 2)
			ft_newton(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	return (0);
}
