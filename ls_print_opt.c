/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 21:03:03 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/30 17:23:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	tt_print_ls(t_tree *head, int len[4])
{
	if (!head)
		return ;
	tt_print_ls(head->left, len);
	tt_print_params(head, len);
	tt_print_ls(head->right, len);
}

void	tt_print_ls_rev(t_tree *head, int len[4])
{
	if (!head)
		return ;
	tt_print_ls_rev(head->right, len);
	tt_print_params(head, len);
	tt_print_ls_rev(head->left, len);
}

void	tt_print_params(t_tree *head, int len[4])
{
	t_param		*param;
	
	param = (t_param *)head->content;
	print_rights(param);
	print_link(param, len[0]);
	print_name(param, len[1]);
	print_group(param, len[2]);
	print_size(param, len[3]);
	print_time(param->tv_sec);
	ft_putendl(param->name);
}

void	print_space(int len, int len_max)
{
	while (len < len_max)
	{
		ft_putchar(' ');
		++len;
	}
}
