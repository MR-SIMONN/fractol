/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:16:27 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/03 17:44:37 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

double	in_range(t_complex z)
{
	return ((z.r * z.r) + (z.i * z.i));
}

double	scale(double value, double min, double max, double dimension)
{
	return ((value / dimension) * (max - min) + min);
}

int	color_grade(int i)
{
	if (i == MAX_ITERATION)
		return (0);
	return (i * 0x00060E);
}

int	iterations_needed(int x, int y, t_fractal p)
{
	int			iterations;
	t_complex	point;

	point.r = scale(x, -2, 2, WIDTH) * p.zoom;
	point.i = scale(y, -2, 2, HEIGHT) * p.zoom;
	if (!ft_strcmp(p.name, "mandelbrot"))
		p.c = point;
	else if (!ft_strcmp(p.name, "julia"))
		p.z = point;
	iterations = 0;
	while (iterations < MAX_ITERATION)
	{
		p.z = sum(square(p.z), p.c);
		if (in_range(p.z) > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

void	put_fract(t_fractal *p)
{
	int		location;
	char	*pixel;
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			p->iterations = iterations_needed(x, y, *p);
			color = color_grade(p->iterations);
			location = (y * p->line_size) + (x * (p->bpp / 8));
			pixel = p->addr + location;
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}
