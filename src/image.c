/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:33:18 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/24 15:44:57 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fractol.h>

mlx_t	*init_window(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	return (mlx);
}

mlx_image_t	*create_image(mlx_t *mlx)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 0, 0);
	return (img);
}

void	pixel_to_image(t_set *fract, int f(t_set*), void fract_eq(t_set *frac))
{
	while (fract->pixel_y < 1000)
	{
		while (fract->pixel_x < 1000)
		{
			fract_eq(fract);
			mlx_put_pixel(fract->img, fract->pixel_x, fract->pixel_y, f(fract));
			fract->pixel_x += 1;
			fract->nb_iteration = 0;
			fract->var_x += fract->jump;
		}
		fract->var_y -= fract->jump;
		fract->var_x = (fract->middle_x - (fract->jump * 500));
		fract->pixel_y += 1;
		fract->pixel_x = 0;
	}
}
