/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:19 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/27 13:31:06 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fail_check(t_fractal *n, char c)
{
	if (!n)
	{
		if (c == 'i')
			mlx_destroy_window(n, n->win);
		else if (c == 'a')
		{
			mlx_destroy_image(n, n->img);
			mlx_destroy_window(n, n->win);	
		}
		exit(1);
	}
}

void    get_fractal(t_fractal *p)
{
	p->init = mlx_init();
	fail_check(p, '1');
	p->win = mlx_new_window(p->init, WIDTH, HEIGHT, p->name);
	fail_check(p, '1');
	p->img = mlx_new_image(p->init, WIDTH, HEIGHT);
	fail_check(p, 'i');
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian);
	fail_check(p, 'a');
	p->zoom = 1;
	put_fract(p);
	mlx_put_image_to_window(p->init, p->win, p->img, 0, 0);
}

int main (int ac, char **av)
{
    t_fractal   fract;

    parsing(ac, av, &fract);
    get_fractal(&fract);
	//mlx_hooks
	mlx_loop(fract.init);	
    return 0;
}