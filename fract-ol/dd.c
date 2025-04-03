void    parsing(int ac, char **av, t_fractal *fract)
{
    if (ac == 1 || !((!ft_strcmp(av[1], "mandelbrot") && ac == 2) || (!ft_strcmp(av[1], "julia") && ac == 4 && valid_nbr(av[2]) && valid_nbr(av[3]))))
        get_some_help();
    if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
    {
        fract->name = "mandelbrot";
    }
    else if (!ft_strcmp(av[1], "julia") && ac == 4)
    {
        fract->name = "julia";
		fract->c.r = ft_atod(av[2]);
		fract->c.i = -ft_atod(av[3]);
    }
}