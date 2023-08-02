/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:50:00 by valerie           #+#    #+#             */
/*   Updated: 2023/07/24 15:34:56 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fractol.h>

void	change_color_ff(t_set *fract, int color(t_set *fract))
{
	if (fract->name == 'M')
		pixel_to_image(fract, color, mandelbrot_equation);
	else if (fract->name == 'J')
		pixel_to_image(fract, color, julia_equation);
	else if (fract->name == 'B')
		pixel_to_image(fract, color, b_equation);
}

void	change_color(t_set *fract)
{
	fract->var_x = fract->middle_x - (fract->jump * 500);
	fract->var_y = fract->middle_y + (fract->jump * 500);
	fract->nb_iteration = 0;
	fract->pixel_x = 0;
	fract->pixel_y = 0;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_B))
	{
		fract->color_name = 'b';
		change_color_ff(fract, blue_pink);
	}
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_O))
	{
		fract->color_name = 'o';
		change_color_ff(fract, orange);
	}
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_P))
	{
		fract->color_name = 'p';
		change_color_ff(fract, pink);
	}
}

void	mlx_move(t_set *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_UP))
		fract->middle_y += (fract->jump * 10);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_DOWN))
		fract->middle_y -= (fract->jump * 10);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
		fract->middle_x += (fract->jump * 10);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
		fract->middle_x -= (fract->jump * 10);
	fract->max_x = fract->middle_x + (fract->jump * 500);
	fract->max_y = fract->middle_y - (fract->jump * 500);
	fract->var_x = fract->middle_x - (fract->jump * 500);
	fract->var_y = fract->middle_y + (fract->jump * 500);
	fract->nb_iteration = 0;
	fract->pixel_x = 0;
	fract->pixel_y = 0;
	if (fract->color_name == 'b')
		change_color_ff(fract, blue_pink);
	else if (fract->color_name == 'p')
		change_color_ff(fract, pink);
	else if (fract->color_name == 'o')
		change_color_ff(fract, orange);
}

void	esc_quit(void *param)
{
	t_set	*fract;

	fract = (t_set *) param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_B)
		|| mlx_is_key_down(fract->mlx, MLX_KEY_O)
		|| mlx_is_key_down(fract->mlx, MLX_KEY_P))
		change_color(fract);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fract->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fract->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fract->mlx, MLX_KEY_UP))
		mlx_move(fract);
}
