/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:53:14 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/30 21:23:26 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_error(int num, int type_error, char *p, int ls_exit)
{
	if (type_error == ESTR)
	{
		ft_putstr("ls: ");
		ft_putstr(p);
		ft_putstr(": ");
		ft_putendl(strerror(num));
	}
	else if (type_error == EOPT)
		error_illegalopt(p);
	if (ls_exit)
		exit(EXIT_FAILURE);
}

void	error_illegalopt(char *p)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*p);
	ft_putchar('\n');
	ft_putstr("usage: ls [-Ralrt] [file ...]\n");
}
