/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:13:08 by valerie           #+#    #+#             */
/*   Updated: 2023/07/24 15:45:25 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fractol.h>

void	initialize_julia(t_set *fract, char *nb1, char *nb2)
{
	fract->nb_iteration = 0;
	fract->zn_x = atod(nb1);
	fract->zn_y = atod(nb2);
	fract->max_y = -2;
	fract->max_x = 2;
	fract->pixel_x = 0;
	fract->pixel_y = 0;
	fract->var_x = -2;
	fract->var_y = 2;
	fract->middle_x = 0;
	fract->middle_y = 0;
	fract->jump = (fract->max_x - fract->var_x) / 1000;
	fract->name = 'J';
	fract->color_name = 'o';
}

void	julia_equation(t_set *fract)
{
	double	var_x;
	double	var_y;
	double	result_x;
	double	result_y;

	var_x = fract->var_x;
	var_y = fract->var_y;
	result_x = 0;
	result_y = 0;
	while (((result_x * result_x + result_y * result_y) < 4.0)
		&& fract->nb_iteration <= MAX_ITER)
	{
		result_x = (var_x * var_x) - (var_y * var_y) + fract->zn_x;
		result_y = 2 * (var_x * var_y) + fract->zn_y;
		fract->nb_iteration++;
		var_x = result_x;
		var_y = result_y;
	}
}

void	my_scroll_hook_julia(double xdelta, double ydelta, void	*param)
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
		pixel_to_image(fract, blue_pink, julia_equation);
	else if (fract->color_name == 'p')
		pixel_to_image(fract, pink, julia_equation);
	else if (fract->color_name == 'o')
		pixel_to_image(fract, orange, julia_equation);
}

void	all_hooks_julia(t_set *fract, char *str)
{
	mlx_put_string(fract->mlx, str, 5, 5);
	mlx_put_string(fract->mlx, "ESC : Quit", 5, 25);
	mlx_put_string(fract->mlx, "Mouse wheel : Zoom", 5, 45);
	mlx_put_string(fract->mlx, "Arrows : Move", 5, 65);
	mlx_put_string(fract->mlx, "P, O or B : Change color", 5, 85);
	mlx_loop_hook(fract->mlx, &esc_quit, fract);
	mlx_scroll_hook(fract->mlx, my_scroll_hook_julia, fract);
}

int	julia(char *nb1, char *nb2)
{
	t_set		*fract;

	fract = malloc(sizeof(t_set));
	if (fract == NULL)
		return (1);
	initialize_julia(fract, nb1, nb2);
	fract->mlx = init_window();
	fract->img = create_image(fract->mlx);
	pixel_to_image(fract, orange, julia_equation);
	all_hooks_julia(fract, "Julia set");
	mlx_loop(fract->mlx);
	mlx_terminate(fract->mlx);
	free(fract);
	return (0);
}
