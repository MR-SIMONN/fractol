/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:44:11 by moel-hai          #+#    #+#             */
/*   Updated: 2025/03/30 14:18:50 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
double	ft_atod(char *str)
{
	int		i;
	double	r;
	int		s;
	double	power;

	i = 0;
	r = 0;
	s = 1;
	power = 1;
	if ((str[i] == '+' || str[i] == '-' ))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		r = r * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		power = power / 10;
		r = r + (str[i++] - '0') * power;
	}
	return (r * s);
}
