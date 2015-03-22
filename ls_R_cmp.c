/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_R_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 16:37:56 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 17:55:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	tt_recursive(t_data *d, t_tree *head)
{
	t_param		*tmp;

	if (!head)
		return ;
	tmp = (t_param *)head->content;
	if (ft_strchr(d->opts, 'r'))
		tt_recursive(d, head->right);
	else
		tt_recursive(d, head->left);
	ft_putchar('\n');
	ft_putstr(tmp->name);
	ft_putendl(":");
	sort_dir(d, tmp->name);
	if (ft_strchr(d->opts, 'r'))
		tt_recursive(d, head->left);
	else
		tt_recursive(d, head->right);
}

int		cmp_date(void *p1, void *p2)
{
	t_param		*n1;
	t_param		*n2;

	n1 = (t_param *)p1;
	n2 = (t_param *)p2;
	if (n2->tv_sec - n1->tv_sec == 0)
		return (ft_strcmp(n1->name, n2->name));
	return (n2->tv_sec - n1->tv_sec);
}

int		cmp_name(void *p1, void *p2)
{
	t_param		*n1;
	t_param		*n2;

	n1 = (t_param *)p1;
	n2 = (t_param *)p2;
	return (ft_strcmp(n1->name, n2->name));
}
