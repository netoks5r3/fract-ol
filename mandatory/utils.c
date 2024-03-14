/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:24 by wremelli          #+#    #+#             */
/*   Updated: 2023/06/09 22:33:20 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long double	ft_atof(const char *nptr)
{
	short int		signal;
	long double		num;
	long double		decimal;

	num = 0;
	signal = (*nptr == '+' || ft_isdigit(*nptr)) - (*nptr == '-');
	nptr += (*nptr == '+' || *nptr == '-');
	while (ft_isdigit(*nptr))
		num = (num * 10) + (*nptr++ - '0');
	nptr += (*nptr == '.');
	decimal = 0.1;
	while (ft_isdigit(*nptr))
	{
		num += (*nptr++ - '0') * decimal;
		decimal /= 10;
	}
	return (num * signal);
}
