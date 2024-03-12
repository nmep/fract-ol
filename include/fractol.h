/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:09:11 by lgarfi            #+#    #+#             */
/*   Updated: 2023/12/27 00:55:29 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define MSG_ERR_1 "\nEntrez\n\t\"./fractol mandelbrot\"\n\tor\n"
# define MSG_ERR_2 "\t\"./fractol julia <value_1> <value_2>\"\n\tor\n\t"
# define MSG_ERR_3 "\t\"./fractol burning_ship <value_1> <value_2>\"\n"
# define WIDTH 900
# define HEIGHT 900

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_comp
{
	double	im;
	double	re;
	double	im2;
	double	re2;
}	t_comp;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_f
{
	t_img	img_p;
	t_mlx	mlx_p;
	t_color	color_a;
	t_color	color_b;
	char	*set;
	int		max_iteration;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	ratio;
	double	re_factor;
	double	im_factor;
}	t_fractal;

void	init(t_fractal *f);
void	my_mlx_pixel_put(t_img *img_ptr, int x, int y, int color);
void	clear_init(t_fractal *f);
int		render(t_fractal *f);
int		key_handler(int keysym, t_fractal *f);
void	events_init(t_fractal *f);
void	init_complex_plan(t_fractal *f);
int		mix_color(int color_a, int color_b, double ratio);
double	ft_atod(char *str);
int		mandelbrot(t_fractal *f, double c_re, double c_im);
int		julia(t_fractal *f, double c_re, double c_im);
void	print_err_mess(void);
void	parsing_julia(char **av);
void	init_color(t_fractal *f);
int		create_trgb(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
void	space_key_colors(t_fractal *f);
int		burning_ship(t_fractal*f, double c_re, double c_im);
double	interpolate(double start, double end, double interpolation);

#endif
