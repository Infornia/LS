/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:37:56 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 18:04:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			ft_dir_isvalid(t_tree *tmp, char *name)
{
	if (tt_file_type(((t_param *)(tmp->content))->st_mode) == 'd')
	{
		if (ft_strcmp("..", name) != 0 && ft_strcmp(".", name))
			return (1);
	}
	return (0);
}

void		add_file(t_data *d, char *path, char *name, t_tree **file)
{
	t_tree	*tmp;

	if ((ft_strchr(d->opts, 'a') && *name == '.') || *name != '.')
	{
		tmp = ft_tree_new(tt_param_new(d, path, name), sizeof(t_param));
		if (ft_strchr(d->opts, 't'))
			*file = ft_tree_add(*file, tmp, &(cmp_date));
		else
			*file = ft_tree_add(*file, tmp, &(cmp_name));
	}
}

void		add_dir(t_data *d, char *path, char *name, t_tree **dir)
{
	t_tree	*tmp;

	tmp = ft_tree_new(tt_param_new(d, path, name), sizeof(t_param));
	if (ft_strchr(d->opts, 'R'))
	{
		if (ft_dir_isvalid(tmp, name))
		{
			if (ft_strchr(d->opts, 't'))
				*dir = ft_tree_add(*dir, tmp, &cmp_date);
			else
				*dir = ft_tree_add(*dir, tmp, &cmp_name);
		}
	}
}

void		sort_dir(t_data *d, char *p)
{
	t_dirent	*ep;
	DIR				*dp;
	t_tree		*dir;
	t_tree		*file;

	dir = NULL;
	file = NULL;
	if ((dp = opendir(p)))
	{
		while ((ep = readdir(dp)))
		{
			add_file(d, p, ep->d_name, &file);
			add_dir(d, p, ep->d_name, &dir);
		}
		closedir(dp);
	}
	else
		perror(p);
	ls_print(d, file);
	if (file)
		ft_tree_del(&file, &tt_param_del);
	if (ft_strchr(d->opts, 'R'))
		tt_recursive(d, dir);
	if (dir)
		ft_tree_del(&dir, &tt_param_del);
}

void		ft_ls(t_data *d)
{
	int		i;

	i = 0;
	if (d->nb_p == 0)
		sort_dir(d, ".");
	else
	{
		while (i < d->nb_p)
			sort_dir(d, ft_strjoin(d->params[i++], "/"));
	}
}
