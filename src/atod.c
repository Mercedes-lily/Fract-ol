/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:05:29 by valerie           #+#    #+#             */
/*   Updated: 2023/07/21 15:39:52 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Ascii to double

int	decimal(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i + count] && str[i + count] != '.')
		count++;
	return (count);
}

double	atod(char *str)
{
	int		i;
	double	nb;
	int		multiple;

	i = 0;
	nb = 0;
	multiple = 1;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			multiple = -1;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] != '.')
			nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (decimal(str) != 0)
		nb = nb / pow(10, decimal(str));
	return (multiple * nb);
}
