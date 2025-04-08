/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:24:44 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/08 18:39:22 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *p)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		p->zoom *= 1.10;
	else if (button == SCROLL_DOWN)
		p->zoom *= 0.90;
	mlx_clear_window(p->init, p->win);
	put_fract(p);
	return (0);
}

int	key_hook(int keycode, t_fractal *p)
{
	if (keycode == ESC)
		cross_window(p);
	mlx_clear_window(p->init, p->win);
	put_fract(p);
	return (0);
}

int	cross_window(t_fractal *p)
{
	mlx_destroy_image(p->init, p->img);
	mlx_destroy_window(p->init, p->win);
	exit(0);
}
