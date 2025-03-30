/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:16:27 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/30 15:24:05 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	color_grade(int i)
{
	if (i == MAX_ITERATION)
		return (0);
	return (i * 0x00060E);
}

int	iterations_needed(int x, int y, t_fractal *p)
{
	if (!ft_strcmp(p->name, "julia"))
		return (julia_iterations(x, y, p));
	if (!ft_strcmp(p->name, "mandelbrot"))
		return (mandelbrot_iterations(x, y, p));
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
			p->iterations = iterations_needed(x, y, p);
			color = color_grade(p->iterations);
			location = (y * p->line_size) + (x * (p->bpp / 8));
			pixel = p->addr + location;
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}
