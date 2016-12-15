/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:23:41 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 16:14:15 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	ft_mj_sequence(t_data *data, int x, int y)
{
	int		i;
	float	tmp;

	i = 0;
	while (i < data->fract->iter_max)
	{
		tmp = data->fract->zn_r;
		data->fract->zn_r = tmp * tmp - data->fract->zn_i *
		data->fract->zn_i + data->fract->constante_r;
		data->fract->zn_i = data->fract->constante_i + 2 * tmp *
		data->fract->zn_i;
		if (data->fract->zn_r * data->fract->zn_r + data->fract->zn_i *
			data->fract->zn_i >= 4)
		{
			if (!(ft_color_img(data, i, x, y)))
				return (0);
			return (1);
		}
		i++;
	}
	if (!(ft_color_img(data, data->fract->iter_max, x, y)))
		return (0);
	return (1);
}

int	verif_circle(t_data *data)
{
	double	tmp;
	double	tmp2;

	if (((data->fract->constante_r + 1) * (data->fract->constante_r + 1) +
	data->fract->constante_i * data->fract->constante_i) < 0.0625)
		return (1);
	tmp = (data->fract->constante_r - 0.25) * (data->fract->constante_r - 0.25)
	+ data->fract->constante_i * data->fract->constante_i;
	tmp2 = sqrt(tmp);
	if ((data->fract->constante_r - 0.25) < (tmp2 - 2 * tmp + 1 / 4))
		return (1);
	return (0);
}

int	ft_mandelbrot(t_data *data)
{
	float x;
	float y;

	y = 0;
	while (y < (WIN_LENGTH))
	{
		x = 0;
		while (x < (WIN_WIDTH))
		{
			data->fract->zn_r = 0;
			data->fract->zn_i = 0;
			data->fract->constante_r = -2.1 + data->event->x0 + (x +
				data->event->x0) * 3.7 / (WIN_WIDTH * data->event->zoom);
			data->fract->constante_i = 1.2 - data->event->y0 - (y -
				data->event->y0) * 2.4 / (WIN_LENGTH * data->event->zoom);
			verif_circle(data) == 0 ? ft_mj_sequence(data, x, y) :
			ft_color_img(data, data->fract->iter_max, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_julia(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_LENGTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			data->fract->zn_r = -2.1 + data->event->x0 + (x + data->event->x0)
			* 3.7 / (WIN_WIDTH * data->event->zoom);
			data->fract->zn_i = 1.2 - data->event->y0 - (y - data->event->y0)
			* 2.4 / (WIN_LENGTH * data->event->zoom);
			ft_mj_sequence(data, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
