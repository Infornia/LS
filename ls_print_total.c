/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_total.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:37:25 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 20:47:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	len_size_max(t_tree *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ((t_param *)(head->content))->st_size;
	*len = tmp < *len ? *len : tmp;
	len_size_max(head->left, len);
	len_size_max(head->right, len);
}

void	len_group_max(t_tree *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ft_strlen(((t_param *)(head->content))->group);
	*len = tmp < *len ? *len : tmp;
	len_group_max(head->left, len);
	len_group_max(head->right, len);
	
}

void	len_user_max(t_tree *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ft_strlen(((t_param *)(head->content))->user);
	*len = tmp < *len ? *len : tmp;
	len_user_max(head->left, len);
	len_user_max(head->right, len);
	
}

void	len_link_max(t_tree *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ((t_param *)(head->content))->st_nlink;
	*len = tmp < *len ? *len : tmp;
	len_link_max(head->left, len);
	len_link_max(head->right, len);
	
}

void	get_size(t_tree *head, int *size)
{
	if (!head)
		return ;
	*size += ((t_param *)(head->content))->st_blocks;
	get_size(head->left, size);
	get_size(head->right, size);	
}

