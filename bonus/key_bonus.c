/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:53:07 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/12 16:53:29 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		return (ft_close(mlx));
	if (keycode == XK_z)
		zoom_in(mlx);
	if (keycode == XK_x)
		zoom_out(mlx);
	if (keycode == XK_Left || keycode == XK_Right || keycode == XK_Up \
		|| keycode == XK_Down)
		move(keycode, mlx);
	if (keycode == XK_r)
		reset(mlx);
	if (keycode == XK_c)
		mlx->color += 0x0f00f110;
	if (keycode == XK_v)
		mlx->color -= 0x0f00f110;
	return (0);
}
