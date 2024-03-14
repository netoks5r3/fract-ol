/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:41:59 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:47:23 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MAX_ITERATIONS 300
# define WIDTH 600
# define HEIGHT 600
# define SUCESS 0
# define ERROR 1

# define MESSAGE_1 "\n\nTo execute correctly the program, you should correctly \
use the name of the fractal:\nLike: ./fractal Mandelbrot\n"
# define MESSAGE_2 "\nSome fractals needs of numbers to determine the initial \
image to shown. For these fractals, please, inform the numbers using a real \
number, separate them using spaces and let the numbers between -2.0 and 2.0. \
The program doesn't work with bigger or lower numbers!\nLike: Julia number_1 \
number_2\n"
# define MESSAGE_3 "Incorrect number(s). You have only 1 function... T.T\n"

typedef struct s_fractol
{
	long double	min_r;
	long double	max_r;
	long double	min_i;
	long double	max_i;
	long double	k_r;
	long double	k_i;
	int			draw;
}				t_fractol;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			color;
	t_fractol	*frac;
}				t_mlx;

// Init
int			ft_init_mlx(t_mlx *mlx);
int			is_correct(char *s);
int			validate_frac(char **argv, t_fractol *frac);
void		ft_str_tolower(char *str);

// Hooks
int			ft_close(t_mlx *mlx);
int			ft_draw_fractal(t_mlx *f);
int			ft_mouse_events(int event, int x, int y, t_mlx *mlx);

// Events
void		zoom_in(t_mlx *mlx);
void		zoom_out(t_mlx *mlx);
void		reset(t_mlx *mlx);
void		pixel_put(t_mlx *data, int x, int y, int color);

// Fractals
void		mandelbrot(t_mlx *mlx, int coord, long double cr, long double ci);
void		julia(t_mlx *mlx, int coord, long double cr, long double ci);

// Key
int			ft_key_press(int keycode, t_mlx *mlx);

// Utils
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
long double	ft_atof(const char *nptr);

// Error
void		error_message(void);

#endif