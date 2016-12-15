/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:13:50 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 18:44:52 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_parsing_color_n(t_data *data, int x, int y, int i)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	if (((data->fract->zn_r + 0.5) * (data->fract->zn_r + 0.5) +
	(data->fract->zn_i + 0.866025) * (data->fract->zn_i + 0.866025)) < 0.000001)
		ft_color_img_n(data, i, 0, coord);
	else if (((data->fract->zn_r + 0.5) * (data->fract->zn_r + 0.5) +
	(data->fract->zn_i - 0.866025) * (data->fract->zn_i - 0.866025)) < 0.000001)
		ft_color_img_n(data, i, 1, coord);
	else if (((data->fract->zn_r - 1) * (data->fract->zn_r - 1) +
	data->fract->zn_i * data->fract->zn_i) < 0.000001)
		ft_color_img_n(data, i, 2, coord);
	else
		ft_color_img_n(data, i, 3, coord);
	return (1);
}

int	ft_set_calc_n(t_data *data, t_calc *calc)
{
	calc->tmp = data->fract->zn_r;
	calc->cte1 = calc->tmp * calc->tmp - data->fract->zn_i * data->fract->zn_i;
	calc->cte2 = 36 * calc->tmp * calc->tmp * data->fract->zn_i *
	data->fract->zn_i;
	calc->cte3 = calc->tmp * calc->tmp * calc->tmp - 3 * calc->tmp *
	data->fract->zn_i * data->fract->zn_i - 1;
	calc->cte4 = 3 * calc->tmp * calc->tmp * data->fract->zn_i -
	data->fract->zn_i * data->fract->zn_i * data->fract->zn_i;
	return (1);
}

int	ft_n_sequence(t_data *data, int x, int y)
{
	int		i;
	t_calc	calc;

	i = 0;
	while (i < data->fract->iter_max && ((data->fract->zn_r - 1) *
	(data->fract->zn_r - 1) + data->fract->zn_i * data->fract->zn_i) >=
	0.000001 && ((data->fract->zn_r + 0.5) * (data->fract->zn_r + 0.5) +
	(data->fract->zn_i - 0.866025) * (data->fract->zn_i - 0.866025)) >=
	0.000001 && ((data->fract->zn_r + 0.5) * (data->fract->zn_r + 0.5) +
	(data->fract->zn_i + 0.866025) * (data->fract->zn_i + 0.866025))
	>= 0.000001)
	{
		ft_set_calc_n(data, &calc);
		data->fract->zn_r = (9 * calc.tmp * calc.cte1 * calc.cte1 + calc.cte2 *
			calc.tmp - 3 * calc.cte1 * calc.cte3 - 6 * calc.tmp *
			data->fract->zn_i * calc.cte4) / (9 * calc.cte1 * calc.cte1 +
				calc.cte2);
		data->fract->zn_i = (9 * data->fract->zn_i * calc.cte1 * calc.cte1 +
			calc.cte2 * data->fract->zn_i - 3 * calc.cte1 * calc.cte4 + 6 *
			calc.tmp * data->fract->zn_i * calc.cte3) / (9 * calc.cte1 *
				calc.cte1 + calc.cte2);
		i++;
	}
	ft_parsing_color_n(data, x, y, i);
	return (1);
}

int	ft_newton(t_data *data)
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
			ft_n_sequence(data, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
