/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:18 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:33:36 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ERROR);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!mlx->win)
	{
		ft_close(mlx);
		return (ERROR);
	}
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		ft_close(mlx);
		return (ERROR);
	}
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, \
				&mlx->endian);
	mlx->color = 0xf0ff0fef;
	mlx_loop_hook(mlx->mlx, ft_draw_fractal, mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &ft_key_press, mlx);
	mlx_hook(mlx->win, DestroyNotify, 0, &ft_close, mlx);
	mlx_mouse_hook(mlx->win, ft_mouse_events, mlx);
	mlx_loop(mlx->mlx);
	return (SUCESS);
}

int	is_correct(char *s)
{
	int	has_number;

	if (!s)
		return (0);
	has_number = 0;
	if (*s == '+' || *s == '-')
		s++;
	while (*s && ft_isdigit(*s))
	{
		s++;
		has_number++;
	}
	if (*s == '.')
	{
		if (!s[1])
			return (0);
		s++;
		while (ft_isdigit(*s) && *s)
			s++;
	}
	if (*s != 0 || !has_number)
		return (0);
	return (1);
}

int	validate_frac(char **argv, t_fractol *frac)
{
	ft_bzero(frac, sizeof(t_fractol));
	frac->min_r = -2;
	frac->max_r = 1;
	frac->min_i = -1.5;
	if (!ft_strcmp(*argv, "mandelbrot") && !argv[1])
		frac->draw = 1;
	else if (!ft_strcmp(*argv, "julia") && !argv[3])
	{
		frac->draw = 2;
		frac->max_r = 2;
		frac->min_i = -2;
		if (!is_correct(argv[1]) || !is_correct(argv[2])
			|| ft_atof(argv[1]) > (double) 2 || ft_atof(argv[1]) < (double) -2
			|| ft_atof(argv[2]) > (double) 2 || ft_atof(argv[2]) < (double) -2)
		{
			write(1, MESSAGE_3, ft_strlen(MESSAGE_3));
			return (ERROR);
		}
		frac->k_r = ft_atof(argv[1]);
		frac->k_i = ft_atof(argv[2]);
	}
	else
		return (ERROR);
	frac->max_i = frac->min_i + (frac->max_r - frac->min_r) * HEIGHT / WIDTH;
	return (SUCESS);
}

void	ft_str_tolower(char *str)
{
	while (str && *str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fractol	frac;

	if (WIDTH <= 0 || HEIGHT <= 0)
	{
		write(1, "Invalid Window Width or Window Heigth.\n", 39);
		write(1, "They must be greater than zero.\n", 32);
		return (ERROR);
	}
	if (argc < 2)
	{
		error_message();
		return (ERROR);
	}
	ft_str_tolower(argv[1]);
	ft_bzero(&mlx, sizeof(t_mlx));
	if (!validate_frac(++argv, &frac))
	{
		mlx.frac = &frac;
		return (ft_init_mlx(&mlx));
	}
	error_message();
	return (ERROR);
}
