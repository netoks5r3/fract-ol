/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:53:09 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/12 16:54:02 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move(int key, t_mlx *mlx)
{
	long double	middle_r;
	long double	middle_i;

	middle_r = mlx->frac->max_r - mlx->frac->min_r;
	middle_i = mlx->frac->max_i - mlx->frac->min_i;
	if (key == XK_Up)
	{
		mlx->frac->min_i -= middle_i * 0.115;
		mlx->frac->max_i -= middle_i * 0.115;
	}
	if (key == XK_Down)
	{
		mlx->frac->min_i += middle_i * 0.115;
		mlx->frac->max_i += middle_i * 0.115;
	}
	if (key == XK_Left)
	{
		mlx->frac->min_r -= middle_r * 0.115;
		mlx->frac->max_r -= middle_r * 0.115;
	}
	if (key == XK_Right)
	{
		mlx->frac->min_r += middle_r * 0.115;
		mlx->frac->max_r += middle_r * 0.115;
	}
}
