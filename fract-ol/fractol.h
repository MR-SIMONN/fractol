/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:48:31 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/04 20:06:51 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define MAX_ITERATIONS 100
# define WIDTH 800
# define HEIGHT 800
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define CROSS_BUTTON 17

typedef struct s_complex
{
	double		r;
	double		i;
}	t_complex;

typedef struct s_fractal
{
	char			*name;
	void			*win;
	void			*init;
	char			*addr;
	void			*img;
	int				iterations;
	int				line_size;
	int				bpp;
	double			zoom;
	int				endian;
	t_complex		c;
	t_complex		z;
}	t_fractal;

void		parsing(int ac, char **av, t_fractal *fract);
void		put_fract(t_fractal *p);
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(char *str);
int			ft_isdigit(int c);
int			cross_window(t_fractal *p);
int			key_hook(int keycode, t_fractal *p);
int			mouse_hook(int button, int x, int y, t_fractal *p);

#endif
