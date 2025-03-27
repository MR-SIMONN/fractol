/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:48:31 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/27 13:31:06 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800


typedef	struct s_complex
{
	double		r;
	double		i;
}	t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*win;
	void	*init;
	char	*addr;
	void	*img;
	int		iterations;
	int		line_size;
	int		bpp;
	double	zoom;
	int		endian;
	t_complex		c;
	t_complex		z;
}	t_fractal;

void    parsing(int ac, char **av, t_fractal *fract);
void	put_fract(t_fractal *p);
int		ft_strcmp(char *s1, char *s2);
double	ft_atouble(char *str);
int		ft_isdigit(int c);

# endif