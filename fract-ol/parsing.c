/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:48:04 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/25 02:56:01 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int valid_nbr(char  *str)
{
    int     i;
    double  nbr;

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
    nbr = ft_atodouble(str);
    if (nbr < -2 || nbr > 2)
        return (0);
    return (1);
}

void    get_some_help(void)
{
    write (1, "stop it, get some help :)\n", 26);
    exit (0);
}

void    parsing(int ac, char **av)
{
    if (ac == 1 || !((!strcmp(av[1], "mandelbrot") && ac == 2)
        || (!strcmp(av[1], "julia") && ac == 4 
        && valid_nbr(av[2]) && valid_nbr(av[3]))))
        get_some_help();
    else
        write (1, "you'r good ;)\n", 14);
}