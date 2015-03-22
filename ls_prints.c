/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 17:01:52 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 18:40:27 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_print(t_data *d, t_tree *head)
{
	int		len[5];
	int		i;

	i = -1;
	while (++i < 5)
		len[i] = 0;
	if (!(ft_strchr(d->opts, 'l')))
	{
		if (ft_strchr(d->opts, 'r'))
			ft_tree_iter_ord(head, %ls_print_param);
		else
			ft_tree_iter_ord(head, %ls_print_param);
		return ;
	}
	if (!head)
		return ;
	ft_print_helper(head, len);
	if (ft_strchr(d->opts, 'r'))
		print_optr(head, len);
	else
		print_ls(head, len);
}

void	print_total(t_tree *head, int len)
{
	get_size(head, &head[4]);
	len_link_max(head, &len[0]);
	len_user_max(head, &len[1]);
	len_group_max(head, &len[2]);
	len_size_max(head, &len[3]);
	len[0] = tt_intlen(len[0]);
	len[3] = tt_intlen(len[3]);
	ft_putstr("total ");
	ft_putnbr(len[4]);
	ft_putchar('\n');
}

void	print_rights(t_param *param)
{
	char	c;

	ft_putchar(tt_file_type(param->st_mode));
	ft_putchar(c = (param->st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWUSR ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXUSR ? 'x' : '-'));
	ft_putchar(c = (param->st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWGRP ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXGRP ? 'x' : '-'));
	ft_putchar(c = (param->st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWOTH ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXOTH ? 'x' : '-'));
	ft_putstr("  ");
}

char	tt_file_type(mode_t mode)
{
	char	c;

	c = '-';
	c = S_ISBLK(mode) ? 'b' : c;
	c = S_ISCHR(mode) ? 'c' : c;
	c = S_ISDIR(mode) ? 'd' : c;
	c = S_ISLNK(mode) ? 'l' : c;
	c = S_ISFIFO(mode) ? 'p' : c;
	c = S_ISSOCK(mode) ? 's' : c;
	return (c);
}
