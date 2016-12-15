/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:54:50 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 19:11:42 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_management(t_data *data)
{
	mlx_expose_hook(data->mlx_win, ft_display, data);
	mlx_key_hook(data->mlx_win, key_func_management, data);
	mlx_mouse_hook(data->mlx_win, mouse_func_management, data);
	mlx_hook(data->mlx_win, MOTIONNOTIFY, POINTERMOTIONMASK,
		mouse_motion_manager, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}

int	mouse_motion_manager(int x, int y, t_data *data)
{
	if (x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_LENGTH &&
		data->event->motion == 1)
	{
		data->fract->constante_r = -2.1 + (x * 3.7) / WIN_WIDTH;
		data->fract->constante_i = 1.2 - (y * 2.4) / WIN_LENGTH;
		ft_julia(data);
		ft_display(data);
		ft_mlx_management(data);
	}
	return (0);
}

int	mouse_func_management_bis(t_data *data)
{
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

int	mouse_func_management(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->event->y0 -= (y + 300 - WIN_LENGTH / 2) / data->event->zoom
		/ WIN_WIDTH;
		data->event->x0 -= (x + 300 - WIN_WIDTH / 2) / data->event->zoom
		/ WIN_LENGTH;
		data->event->zoom *= 0.8;
		if (data->fract->iter_max >= 2)
			data->fract->iter_max -= 1;
		mouse_func_management_bis(data);
	}
	if (button == 5)
	{
		data->event->y0 += (y + 190 - WIN_LENGTH / 2) / data->event->zoom
		/ WIN_WIDTH;
		data->event->x0 += (x + 200 - WIN_WIDTH / 2) / data->event->zoom
		/ WIN_LENGTH;
		data->event->zoom *= 1.2;
		data->fract->iter_max += 1;
		mouse_func_management_bis(data);
	}
	return (0);
}
