/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:28:30 by vst-pier          #+#    #+#             */
/*   Updated: 2023/07/22 11:08:34 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
//for the open function
# include <unistd.h>
// for the close, read, write
# include <stdlib.h>
//for the malloc, free, exit functions
# include <stdio.h>
//for the perror function
# include <string.h>
//for the strerror function
# include <math.h>
// for all functions in math library
//ft_printf
# include "../MLX42/include/MLX42/MLX42.h"
//for the mlx library
# include "../libft/libft.h"
//for the libft library

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

typedef struct fractol_set
{
	mlx_t		*mlx;			
	mlx_image_t	*img;
	char		name;			
	double		zn_x;
	double		zn_y;
	double		var_x;
	double		var_y;
	int			nb_iteration;
	int			pixel_y;
	int			pixel_x;
	double		max_x;
	double		max_y;
	double		jump;
	double		middle_x;
	double		middle_y;
	char		color_name;
}	t_set;

//atod.c
int			decimal(char *str);
double		atod(char *str);

// burningship.c
void		initialize_b(t_set *fract);
void		b_equation(t_set *fract);
void		my_scroll_hook_b(double xdelta, double ydelta, void	*param);
void		all_hooks_b(t_set *fract, char *str);
int			burning_ship(void);

//color.c
int			get_rgba(int r, int g, int b, int a);
int			orange(t_set *fract);
int			blue_pink(t_set *fract);
int			pink(t_set *fract);

//fractol.c
int			good_param(void);

//hook.c
void		change_color_ff(t_set *fract, int color(t_set *fract));
void		change_color(t_set *fract);
void		mlx_move(t_set *fract);
void		esc_quit(void *param);

//image.c
mlx_t		*init_window(void);
mlx_image_t	*create_image(mlx_t *mlx);
void		pixel_to_image(t_set *fract, int f(t_set*),
				void fract_eq(t_set *frac));

//julia.c
void		initialize_julia(t_set *fract, char *nb1, char *nb2);
void		julia_equation(t_set *fract);
void		my_scroll_hook_julia(double xdelta, double ydelta, void	*param);
void		all_hooks_julia(t_set *fract, char *str);
int			julia(char *nb1, char *nb2);

//mandelbrot.c
void		initialize_mandelbrot(t_set *fract);
void		mandelbrot_equation(t_set *fract);
void		my_scroll_hook_mandelbrot(double xdelta,
				double ydelta, void *param);
void		all_hooks_mandelbrot(t_set *fract, char *str);
int			mandelbrot(void);

#endif