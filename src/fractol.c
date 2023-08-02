/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:28:25 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/22 10:41:24 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <../inc/fractol.h>

int	good_param(void)
{
	printf("Please enter one of the following parameters :\n");
	printf("-> Mandelbrot\n");
	printf("-> Julia + the two numbers contain in the imaginary"); 
	printf(" number a+bi ex : Julia 0.32 0.553 (Use dots)\n");
	printf("-> Burning ship\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
			mandelbrot();
		else if (ft_strncmp(argv[1], "Burning ship", 12) == 0)
			burning_ship();
		else
			good_param();
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "Julia", 5) == 0)
			julia(argv[2], argv[3]);
		else
			good_param();
	}
	else
		good_param();
}
