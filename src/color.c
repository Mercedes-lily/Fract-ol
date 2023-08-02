/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:50:30 by valerie           #+#    #+#             */
/*   Updated: 2023/07/22 12:21:22 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fractol.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	orange(t_set *fract)
{
	int	color;

	color = 255 * log((double)fract->nb_iteration / (MAX_ITER + 1));
	return (get_rgba(floor(color), floor(color), 0, 255));
}

int	blue_pink(t_set *fract)
{
	int	color;

	color = 255 * log((double)fract->nb_iteration / (MAX_ITER + 1));
	return (get_rgba(floor(color), 125, 125, 255));
}

int	pink(t_set *fract)
{
	int	color;

	color = 255 * log((double)fract->nb_iteration / (MAX_ITER + 1));
	return (get_rgba(125, floor(color), 125, 255));
}
