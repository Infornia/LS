/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:27:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/19 18:09:17 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_data		*eval_option(char *s, t_data *d, int *opt)
{
	while (*(++s))
	{
		if (ft_strchr("Raltr", *s))
		{
			if (ft_strchr(d->opts, *s) == NULL)
			{
				d->opts[*opt] = *s;
				*opt = *opt + 1;
			}
		}
		else
			ft_putstr("FUCKING ERROR");
	}
	return (d);
}

t_data		*load_options(int ac, char **av)
{
	t_data	*d;
	int		i;
	int		st;
	int		opt;

	i = 1;
	st = 1;
	opt = 0;
	while (st < ac && av[st][0] == '-' && av[st][1] != '\0')
		st++;
	if (!(d = data_new(ac - st)))
		ft_putstr("BEST ERROR EU");
	while (i < ac && av[i][0] == '-' && av[i][1] != '\0')
		d = eval_option(av[i++], d, &opt);
	while (i < ac)
	{
		d->params[i - st] = ft_strdup(av[i]);
		i++;
	}
	return (d);
}

int		main(int ac, char **av)
{
	t_data	*d;

	d = load_options(ac, av);
	print(d);
	ft_ls(d);
	if (d)
		ft_data_del(d);
	return (0);
}
