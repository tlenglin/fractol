/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_nj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:43:29 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 15:45:05 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_img_blue(t_data *data, int i, int x, int y)
{
	unsigned int color;
	unsigned int color_tmp;

	color = i * 1000 / data->fract->iter_max;
	if (color > 100 && color <= 400)
	{
		color_tmp = color - 100;
		if (color_tmp < 110)
		{
			data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 150 +
			color_tmp * 9 / 10;
			data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] = 0;
		}
		else
		{
			data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 255;
			data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] =
			(color_tmp - 11) * 9 / 10;
		}
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	}
	return (1);
}

int	ft_color_img_blue_to_yellow(t_data *data, int i, int x, int y)
{
	unsigned int color;
	unsigned int color_tmp;

	color = i * 1000 / data->fract->iter_max;
	if (color > 400 && color <= 600)
	{
		color_tmp = color - 400;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 255;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] =
		171 + color_tmp * (255 - 171) / 20 / 10;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] =
		color_tmp * 255 / 20 / 10;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	}
	else if (color > 600 && color <= 800)
	{
		color_tmp = color - 600;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] =
		255 - color_tmp * 255 / 20 / 10;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] = 255;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] = 255;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	}
	return (1);
}

int	ft_color_img_yellow_to_orange(t_data *data, int i, int x, int y)
{
	unsigned int color;
	unsigned int color_tmp;

	color = i * 1000 / data->fract->iter_max;
	color_tmp = color - 800;
	data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 0;
	data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] =
	255 - color_tmp * (255 - 75) / 20 / 10;
	data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] = 255;
	data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	return (1);
}

int	ft_color_img(t_data *data, int i, int x, int y)
{
	unsigned int color;

	color = i * 1000 / data->fract->iter_max;
	if (color <= 100)
	{
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 150;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	}
	else if (color > 100 && color <= 400)
		ft_color_img_blue(data, i, x, y);
	else if (color > 400 && color <= 800)
		ft_color_img_blue_to_yellow(data, i, x, y);
	else if (color > 800 && color < 1000)
		ft_color_img_yellow_to_orange(data, i, x, y);
	else
	{
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x)] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 1] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 2] = 0;
		data->img->img_adr[(y * WIN_WIDTH * 4 + 4 * x) + 3] = 0;
	}
	return (1);
}
