/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:53:23 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/14 19:28:12 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_alloc(t_data **data)
{
	if (!(*data = ft_memalloc(sizeof(t_data))))
		return (0);
	if (!((*data)->img = ft_memalloc(sizeof(t_img))))
		return (0);
	if (!((*data)->fract = ft_memalloc(sizeof(t_img))))
		return (0);
	if (!((*data)->event = ft_memalloc(sizeof(t_img))))
		return (0);
	return (1);
}

int	ft_mlx_init(t_data *data)
{
	if (!(data->mlx_ptr = mlx_init()))
		return (0);
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
		WIN_LENGTH, "Fractol")))
		return (0);
	if (!(data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH,
		WIN_LENGTH)))
		return (0);
	if (!(data->img->img_adr = mlx_get_data_addr(data->img->img_ptr,
		&data->img->bpp, &data->img->sizeline, &data->img->endian)))
		return (0);
	data->event->zoom = 1;
	data->fract->iter_max = 75;
	return (1);
}

int	ft_set_fract(char *str, t_data *data)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		if (!(ft_mandelbrot(data)))
			return (0);
		if (!(ft_mlx_management(data)))
			return (0);
	}
	if (ft_strcmp(str, "julia") == 0)
	{
		data->fract->type = 1;
		if (!(ft_julia(data)))
			return (0);
		if (!(ft_mlx_management(data)))
			return (0);
	}
	if (ft_strcmp(str, "newton") == 0)
	{
		data->fract->type = 2;
		if (!(ft_newton(data)))
			return (0);
		if (!(ft_mlx_management(data)))
			return (0);
	}
	return (0);
}

int	ft_free(t_data *data)
{
	free(data->fract);
	free(data->event);
	free(data->img);
	free(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 &&
	ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "newton") != 0))
		return (ft_error(0, &data));
	if (ft_alloc(&data) == 0)
		return (ft_error(1, &data));
	if (ft_mlx_init(data) == 0)
		return (ft_error(2, &data));
	ft_set_fract(argv[1], data);
	return (0);
}
