/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:16:27 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/27 13:31:06 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	put_fract(t_fractal *p)
{
	int		pixel;
	char	*dest;
	int		x;
	int		y;

	pixel = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strcmp(p->name, "julia") == 0)
				p->iterations = julia_iterations(x, y, p);
			if (ft_strcmp(p->name, "mandelbrot") == 0)
				p->iterations = mandelbrot_iterations(x, y, p);
			pixel = (y * p->line_size) + (x * (p->bpp / 8));
			dest = p->addr + pixel;
			*(unsigned int *)dest = color_ft(p->iterations);
			x++;
		}
		y++;
	}
}