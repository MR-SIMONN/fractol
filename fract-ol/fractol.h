/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:48:31 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/25 01:50:08 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// typedef	struct s_complex
// {
// 	double		r;
// 	double		i;
// }	t_complex;

// typedef struct s_fractal
// {
// 	char			*name;
// 	unsigned int	color;
// 	void			*mlx;
// 	void			*win;
// 	void			*img;
// 	char			*addr;
// 	int				bits_per_pixel;
// 	int				size_line;
// 	int				endian;
// 	int				iterations;
// 	double			zoom;
// 	double			x_offset;
// 	double			y_offset;
// 	double			mouse_x;
// 	double			mouse_y;
// 	int				lock_mouse;
// 	t_complex		c;
// 	t_complex		z;

// }				t_fractal;

int		ft_strcmp(char *s1, char *s2);
void	parsing(int ac, char **av);
double	ft_atodouble(char *str);
int		ft_isdigit(int c);

# endif