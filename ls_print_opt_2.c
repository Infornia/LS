/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_opt_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 21:12:39 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 21:54:51 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_link(t_param *param, int len_link)
{
	print_space(tt_intlen(param->st_nlink), len_link);
	ft_putnbr(param->st_nlink);
	ft_putchar(' ');
}

void	print_size(t_param *param, int len_size)
{
	char	c;

	c =  tt_file_type(param->st_mode);
	if (c == 'b' || c == 'c')
	{
		print_space(tt_intlen(MAJOR(param->st_rdev)), 3);
		ft_putnbr(MAJOR(param->st_rdev));
		ft_putstr(", ");
		print_space(tt_intlen(MINOR(param->st_rdev)), 3);
		ft_putnbr(MINOR(param->st_rdev));
	}
	else
	{
		print_space(tt_intlen(param->st_size), len_size);
		ft_putnbr(param->st_size);
	}
	ft_putchar(' ');
}

void	print_name(t_param *param, int len_name)
{
	ft_putstr(param->user);
	print_space(ft_strlen(param->user), len_name);
	ft_putstr("  ");
}

void	print_group(t_param *param, int len_group)
{
	ft_putstr(param->group);
	print_space(ft_strlen(param->group), len_group);
	ft_putstr("  ");
}

void	print_time(time_t timestamp)
{
	char	*time;
	char	**split;
	int		i;

	time = ctime(&timestamp);
	split = ft_strsplit(time, ' ');
	ft_putstr(split[1]);
	ft_putchar(' ');
	if (ft_strlen(split[2]) == 1)
		ft_putchar(' ');
	ft_putstr(split[2]);
	ft_putchar(' ');
	time = ft_strsub(split[3], 0, 5);
	ft_putstr(time);
	ft_putchar(' ');
	i = 0;
	free(time);
	while (i <= 4)
		ft_strdel(&split[i++]);
	free(split);
}
