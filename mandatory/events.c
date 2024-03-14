/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:08 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:34:40 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_mlx *mlx)
{
	long double	middle_r;
	long double	middle_i;

	middle_r = mlx->frac->max_r - mlx->frac->min_r;
	middle_i = mlx->frac->max_i - mlx->frac->min_i;
	mlx->frac->min_r += middle_r * 0.115;
	mlx->frac->max_r -= middle_r * 0.115;
	mlx->frac->min_i += middle_i * 0.115;
	mlx->frac->max_i = mlx->frac->min_i + (mlx->frac->max_r - \
	mlx->frac->min_r) * HEIGHT / WIDTH;
}

void	zoom_out(t_mlx *mlx)
{
	long double	middle_r;
	long double	middle_i;

	middle_r = mlx->frac->max_r - mlx->frac->min_r;
	middle_i = mlx->frac->max_i - mlx->frac->min_i;
	mlx->frac->min_r -= middle_r * 0.115;
	mlx->frac->max_r += middle_r * 0.115;
	mlx->frac->min_i -= middle_i * 0.115;
	mlx->frac->max_i = mlx->frac->min_i + (mlx->frac->max_r - \
	mlx->frac->min_r) * HEIGHT / WIDTH;
}

void	reset(t_mlx *mlx)
{
	if (mlx->frac->draw == 1)
	{
		mlx->frac->min_r = -2;
		mlx->frac->max_r = 1;
		mlx->frac->min_i = -1.5;
	}
	else
	{
		mlx->frac->min_r = -2;
		mlx->frac->max_r = 2;
		mlx->frac->min_i = -2;
	}
	mlx->frac->max_i = mlx->frac->min_i + (mlx->frac->max_r - \
	mlx->frac->min_r) * HEIGHT / WIDTH;
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}
