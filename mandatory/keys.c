/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:21 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:32:53 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		return (ft_close(mlx));
	if (keycode == XK_z)
		zoom_in(mlx);
	if (keycode == XK_x)
		zoom_out(mlx);
	if (keycode == XK_r)
		reset(mlx);
	return (0);
}
