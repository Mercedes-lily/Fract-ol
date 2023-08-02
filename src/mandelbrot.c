/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:11:46 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/24 15:51:18 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fractol.h>

void	initialize_mandelbrot(t_set *fract)
{
	fract->nb_iteration = 0;
	fract->var_x = -2;
	fract->var_y = 2;
	fract->max_y = -2;
	fract->max_x = 2;
	fract->pixel_x = 0;
	fract->pixel_y = 0;
	fract->middle_x = 0;
	fract->middle_y = 0;
	fract->jump = (fract->max_x - fract->var_x) / 1000;
	fract->name = 'M';
	fract->color_name = 'o';
}

void	mandelbrot_equation(t_set *fract)
{
	double	zn_x;
	double	zn_y;
	double	result_x;
	double	result_y;

	zn_y = 0;
	zn_x = 0;
	result_x = 0;
	result_y = 0;
	while (((result_x * result_x + result_y * result_y) < 4.0)
		&& fract->nb_iteration <= MAX_ITER)
	{
		result_x = (zn_x * zn_x) - (zn_y * zn_y) + fract->var_x;
		result_y = 2 * (zn_x * zn_y) + fract->var_y;
		fract->nb_iteration++;
		zn_x = result_x;
		zn_y = result_y;
	}
}

void	my_scroll_hook_mandelbrot(double xdelta, double ydelta, void	*param)
{
	t_set	*fract;

	(void) xdelta;
	fract = (t_set *)param;
	if (ydelta > 0)
		fract->jump *= 1.1111111111;
	else if (ydelta < 0)
		fract->jump *= 0.9;
	fract->max_x = fract->middle_x + (fract->jump * 500);
	fract->max_y = fract->middle_y - (fract->jump * 500);
	fract->var_x = fract->middle_x - (fract->jump * 500);
	fract->var_y = fract->middle_y + (fract->jump * 500);
	fract->nb_iteration = 0;
	fract->pixel_x = 0;
	fract->pixel_y = 0;
	if (fract->color_name == 'b')
		pixel_to_image(fract, blue_pink, mandelbrot_equation);
	else if (fract->color_name == 'p')
		pixel_to_image(fract, pink, mandelbrot_equation);
	else if (fract->color_name == 'o')
		pixel_to_image(fract, orange, mandelbrot_equation);
}

void	all_hooks_mandelbrot(t_set *fract, char *str)
{
	mlx_put_string(fract->mlx, str, 5, 5);
	mlx_put_string(fract->mlx, "ESC : Quit", 5, 25);
	mlx_put_string(fract->mlx, "Mouse wheel : Zoom", 5, 45);
	mlx_put_string(fract->mlx, "Arrows : Move", 5, 65);
	mlx_put_string(fract->mlx, "P, O or B : Change color", 5, 85);
	mlx_loop_hook(fract->mlx, &esc_quit, fract);
	mlx_scroll_hook(fract->mlx, my_scroll_hook_mandelbrot, fract);
}

int	mandelbrot(void)
{
	t_set		*fract;

	fract = malloc(sizeof(t_set));
	if (fract == NULL)
		return (1);
	initialize_mandelbrot(fract);
	fract->mlx = init_window();
	fract->img = create_image(fract->mlx);
	pixel_to_image(fract, orange, mandelbrot_equation);
	all_hooks_mandelbrot(fract, "Mandelbrot Set");
	mlx_loop(fract->mlx);
	mlx_terminate(fract->mlx);
	free(fract);
	return (1);
}
