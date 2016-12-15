/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:27 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 17:05:49 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_func_management6(t_data *data)
{
	data->event->x0 = 0;
	data->event->y0 = 0;
	data->event->zoom = 1;
	data->fract->iter_max = 100;
	if (data->fract->type == 0)
		ft_mandelbrot(data);
	else if (data->fract->type == 1)
		ft_julia(data);
	else if (data->fract->type == 2)
		ft_newton(data);
	ft_display(data);
	ft_mlx_management(data);
	return (0);
}

int	key_func_management7(t_data *data)
{
	if (data->fract->iter_max >= 51)
		data->fract->iter_max -= 50;
	if (data->fract->type == 0)
		ft_mandelbrot(data);
	else if (data->fract->type == 1)
		ft_julia(data);
	else if (data->fract->type == 2)
		ft_newton(data);
	ft_display(data);
	ft_mlx_management(data);
	return (0);
}

int	key_func_management8(t_data *data)
{
	data->event->y0 -= 0.5 / data->event->zoom;
	if (data->fract->type == 0)
		ft_mandelbrot(data);
	else if (data->fract->type == 1)
		ft_julia(data);
	else if (data->fract->type == 2)
		ft_newton(data);
	ft_display(data);
	ft_mlx_management(data);
	return (0);
}

int	key_func_management9(t_data *data)
{
	data->event->zoom *= 1.2;
	data->fract->iter_max += 1;
	if (data->fract->type == 0)
		ft_mandelbrot(data);
	else if (data->fract->type == 1)
		ft_julia(data);
	else if (data->fract->type == 2)
		ft_newton(data);
	ft_display(data);
	ft_mlx_management(data);
	return (0);
}

int	key_func_management10(t_data *data)
{
	data->event->zoom *= 0.8;
	if (data->fract->iter_max >= 2)
		data->fract->iter_max -= 1;
	if (data->fract->type == 0)
		ft_mandelbrot(data);
	else if (data->fract->type == 1)
		ft_julia(data);
	else if (data->fract->type == 2)
		ft_newton(data);
	ft_display(data);
	ft_mlx_management(data);
	return (0);
}
