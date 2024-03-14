/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:50:05 by wremelli          #+#    #+#             */
/*   Updated: 2024/03/14 20:56:24 by wremelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	write(1, MESSAGE_1, ft_strlen(MESSAGE_1));
	write(1, MESSAGE_2, ft_strlen(MESSAGE_2));
}
