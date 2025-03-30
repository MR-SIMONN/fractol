/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:33 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/30 16:37:27 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_iterations_mandelbrot(double x, double y, t_fractal *p)
{
	int			iteration;
	int			line; 
	t_complex	result;

	iteration = 0;
	p->z.i = 0;
	p->z.r = 0;
	x = (-2.0 + (x / WIDTH) * (2.0 - (-2.0))) * p->zoom;
	y = (-2.0 + (y / HEIGHT) * (2.0 - (-2.0))) * p->zoom;
	line = pow(p->z.r, 2) + pow(p->z.i, 2) < 4;
	while (iteration < MAX_ITERATION && line)
	{
		result.r = (p->z.r * p->z.r) - (p->z.i * p->z.i) + x;
		result.i = 2 * (p->z.r * p->z.i) + y;
		p->z.r = result.r;
		p->z.i = result.i;
		line = pow(p->z.r, 2.0) + pow(p->z.i, 2.0) < 4;
		iteration++;
	}
	return (iteration);
}

int	count_iterations_julia(double x, double y, t_fractal *p)
{
	int			iteration;
	t_complex	result;
	int			line;

	iteration = 0;
	p->z.r = (-2.0 + (x / WIDTH) * (2.0 - (-2.0))) * p->zoom;
	p->z.i = (2.0 - (y / HEIGHT) * (2.0 - (-2.0))) * p->zoom;
	line = (p->z.r * p->z.r) + (p->z.i * p->z.i) < 4;
	while (line && iteration < MAX_ITERATION)
	{
		result.r = (p->z.r * p->z.r) - (p->z.i * p->z.i) + p->c.r;
		result.i = 2 * (p->z.r * p->z.i) + p->c.i;
		p->z.r = result.r;
		p->z.i = result.i;
		line = pow(p->z.r, 2.0) + pow(p->z.i, 2.0) < 4;
		iteration++;
	}
	return (iteration);
}