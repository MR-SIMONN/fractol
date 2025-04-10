/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:19 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/08 19:47:53 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fail_check(void *n)
{
	if (!n)
		exit(1);
}

void	get_fractal(t_fractal *p)
{
	p->init = mlx_init();
	fail_check(p->init);
	p->win = mlx_new_window(p->init, WIDTH, HEIGHT, p->name);
	fail_check(p->win);
	p->img = mlx_new_image(p->init, WIDTH, HEIGHT);
	if (!p->img)
	{
		mlx_destroy_window(p->init, p->win);
		exit(1);
	}
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian);
	if (!p->addr)
	{
		mlx_destroy_image(p->init, p->img);
		mlx_destroy_window(p->init, p->win);
		exit(1);
	}
	p->zoom = 1;
	mlx_mouse_hook(p->win, mouse_hook, p);
	mlx_key_hook(p->win, key_hook, p);
	mlx_hook(p->win, CROSS_BUTTON, 0, cross_window, p);
	put_fract(p);
}

int	main(int ac, char **av)
{
	t_fractal	fract;

	parsing(ac, av, &fract);
	get_fractal(&fract);
	mlx_loop(fract.init);
}
