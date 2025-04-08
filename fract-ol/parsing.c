/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:48:04 by moel-hai          #+#    #+#             */
/*   Updated: 2025/04/08 20:08:45 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_some_help(void)
{
	char	*usage;

	usage = "Usage: ./fractol [fractal_type] [parameters]\n"
		"Available fractals:\n"
		"- mandelbrot\n"
		"- julia [c_real] [c_imag]\n"
		"\nExample: ./fractol julia 0.285 0.01\n"
		"         ./fractol mandelbrot\n";
	write(2, usage, 171);
	exit(1);
}

int	valid_nbr(char *str)
{
	int		i;
	double	nbr;

	if (!str[0] || !str)
		get_some_help();
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atod(str);
	if (nbr < -2 || nbr > 2)
		return (0);
	return (1);
}

void	parsing(int ac, char **av, t_fractal *fract)
{
	if (ac == 1 || !((!ft_strcmp(av[1], "mandelbrot") && ac == 2)
			|| (!ft_strcmp(av[1], "julia") && ac == 4
				&& valid_nbr(av[2]) && valid_nbr(av[3]))))
		get_some_help();
	if (!ft_strcmp(av[1], "mandelbrot"))
		fract->name = "mandelbrot";
	else if (!ft_strcmp(av[1], "julia"))
	{
		fract->name = "julia";
		fract->c.r = ft_atod(av[2]);
		fract->c.i = -ft_atod(av[3]);
	}
}
