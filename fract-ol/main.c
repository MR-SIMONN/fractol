/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:19 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/04 14:31:26 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fail_check(t_fractal *n)
{
	if (!n)
	{
		// if (c == 'i')
		// 	mlx_destroy_window(n, n->win);
		// else if (c == 'a')
		// {
		// 	mlx_destroy_image(n, n->img);
		// 	mlx_destroy_window(n, n->win);	
		// }
		write(2, "hhh", 3);
		exit(1);
	}
}

void    get_fractal(t_fractal *p)
{
	p->init = mlx_init();
	fail_check((t_fractal *)p->init);
	p->win = mlx_new_window(p->init, WIDTH, HEIGHT, p->name);
	fail_check((t_fractal *)p->win);
	p->img = mlx_new_image(p->init, WIDTH, HEIGHT);
	fail_check((t_fractal *)p->img);
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian);
	fail_check((t_fractal *)p->addr);
	p->zoom = 1;
	p->z.r = 0;
	p->z.i = 0;
	mlx_key_hook(p->win, key_hook, p);
	mlx_mouse_hook(p->win, mouse_hook, p);
	mlx_hook(p->win, CROSS_BUTTON, 0, cross_window, p);
	put_fract(p);
}

int main (int ac, char **av)
{
    t_fractal   fract;

    parsing(ac, av, &fract);
    get_fractal(&fract);
	mlx_loop(fract.init);
    return 0;
}