/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:21:04 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 19:28:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_img_n(t_data *data, int i, int c, t_coord coord)
{
	i = (i > 15) ? 15 : i;
	data->img->img_adr[(coord.y * WIN_WIDTH * 4 + 4 * coord.x)] =
	(c == 0 || c == 2) ? 255 - i * 10 : 0;
	data->img->img_adr[(coord.y * WIN_WIDTH * 4 + 4 * coord.x) + 1] =
	(c == 0 || c == 1) ? 255 - i * 10 : 0;
	data->img->img_adr[(coord.y * WIN_WIDTH * 4 + 4 * coord.x) + 2] =
	(c == 1 || c == 2) ? 255 - i * 10 : 0;
	data->img->img_adr[(coord.y * WIN_WIDTH * 4 + 4 * coord.x) + 3] = 0;
	return (1);
}

int	ft_display(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	ft_instructions(data);
	return (0);
}

int	ft_informations(t_data *data)
{
	int		zoom;
	int		x;

	zoom = (int)(data->event->zoom * 10);
	x = 0;
	if (data->event->zoom >= 10)
		x = 10;
	if (data->event->zoom >= 100)
		x += 10;
	if (data->event->zoom >= 1000)
		x += 10;
	if (data->event->zoom >= 10000)
		x += 10;
	mlx_string_put(data->mlx_ptr, data->mlx_win, 745, 35, TXT,
		"actual zoom = ");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 883, 35, TXT,
		ft_itoa(zoom / 10));
	mlx_string_put(data->mlx_ptr, data->mlx_win, 883 + x + 10, 35, TXT, ",");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 883 + x + 20, 35,
		TXT, ft_itoa(zoom % 10));
	mlx_string_put(data->mlx_ptr, data->mlx_win, 745, 55, TXT,
		"actual max_iteration = ");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 968, 55, TXT,
		ft_itoa(data->fract->iter_max));
	return (1);
}

int	ft_instructions(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 35, TXT,
		"0 / 1 / 2 = Mandelbrot / Julia / Newton");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 55, TXT,
		"ESC = exit");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 75, TXT,
		"up, down, left, right arrows = mouvement");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 95, TXT,
		"q / w = + / - precis (+ / - iteration_max)");
	if (data->fract->type == 1)
		mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 175, TXT,
			"m = toggle on / off motion for Julia");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 135, TXT,
		"+ / - = zoom in / out");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 155, TXT, "scroll = zoom");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 35, 115, TXT,
		"r = reset zoom / x0 / y0 / max_iteration");
	ft_informations(data);
	return (0);
}

int	ft_error(int error, t_data **data)
{
	if (error == 0)
		write(2, "usage: fractol [mandelbrot, julia, newton]\n", 43);
	if (error == 1)
		write(2, "malloc failed\n", 14);
	if (error == 2)
	{
		ft_free(*data);
		write(2, "mlx_init failed\n", 15);
	}
	return (0);
}
