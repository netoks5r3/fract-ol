/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:14 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:34:01 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx->win = NULL;
	free(mlx->mlx);
	exit(0);
	return (0);
}

int	ft_draw_fractal(t_mlx *f)
{
	int			x;
	int			y;
	long double	pr;
	long double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->frac->min_r + x * (f->frac->max_r - f->frac->min_r) / WIDTH;
			pi = f->frac->min_i + y * (f->frac->max_i - f->frac->min_i) / \
				HEIGHT;
			if (f->frac->draw == 1)
				mandelbrot(f, (x << 16) | y, pr, pi);
			else
				julia(f, (x << 16) | y, pr, pi);
		}
	}
	if (f->win)
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	ft_mouse_events(int event, int x, int y, t_mlx *mlx)
{
	x += 0;
	y += 0;
	if (event == 4)
		zoom_in(mlx);
	if (event == 5)
		zoom_out(mlx);
	return (0);
}
