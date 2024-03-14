/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:11 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/08 00:54:41 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_mlx *mlx, int coord, long double cr, long double ci)
{
	int			n;
	long double	zr;
	long double	zi;
	long double	tmp;

	zr = 0;
	zi = 0;
	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (n == MAX_ITERATIONS)
		pixel_put(mlx, coord >> 16, (coord << 16) >> 16, mlx->color);
	else
		pixel_put(mlx, coord >> 16, (coord << 16) >> 16, mlx->color * 0xFFFFFF \
		* n);
}

void	julia(t_mlx *mlx, int coord, long double cr, long double ci)
{
	int			n;
	long double	tmp;

	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		if ((cr * cr + ci * ci) > 4.0)
			break ;
		tmp = 2 * cr * ci - mlx->frac->k_i;
		cr = cr * cr - ci * ci + mlx->frac->k_r;
		ci = tmp;
	}
	if (n == MAX_ITERATIONS)
		pixel_put(mlx, coord >> 16, (coord << 16) >> 16, mlx->color);
	else if (n > 0)
		pixel_put(mlx, coord >> 16, (coord << 16) >> 16, mlx->color * 0xFFFFFF \
		* n);
	else
		pixel_put(mlx, coord >> 16, (coord << 16) >> 16, mlx->color * 0xFFFFFF);
}
