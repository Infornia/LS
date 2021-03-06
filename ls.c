/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:37:56 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/01 17:19:58 by mwilk            ###   ########.fr       */
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
		tmp = tt_tree_new(tt_param_new(d, path, name), sizeof(t_param));
		if (ft_strchr(d->opts, 't') != NULL)
			*file = tt_tree_add(*file, tmp, &cmp_date);
		else
			*file = tt_tree_add(*file, tmp, &cmp_name);
	}
}

void		add_dir(t_data *d, char *path, char *name, t_tree **dir)
{
	t_tree	*tmp;

	tmp = tt_tree_new(tt_param_new(d, path, name), sizeof(t_param));
	if (ft_strchr(d->opts, 'R'))
	{
		if (ft_dir_isvalid(tmp, name))
		{
			if (ft_strchr(d->opts, 't') != NULL)
				*dir = tt_tree_add(*dir, tmp, &cmp_date);
			else
				*dir = tt_tree_add(*dir, tmp, &cmp_name);
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
	ls_prints(d, file);
	if (file)
		tt_tree_del(&file, &tt_param_del);
	if (ft_strchr(d->opts, 'R'))
		tt_recursive(d, dir);
	if (dir)
		tt_tree_del(&dir, &tt_param_del);
}

void		ft_ls(t_data *d)
{
	int		i;
	t_stat	sts;

	i = 0;
	if (d->nb_p == 0)
		sort_dir(d, ".");
	else
	{
		while (i < d->nb_p)
		{
			stat(d->params[i], &sts);
			if (S_ISREG(sts.st_mode))
			{
				ft_putstr(d->params[i]);
				ft_putstr("\n");
			}
			if (S_ISDIR(sts.st_mode))
				sort_dir(d, ft_strjoin(d->params[i++], "/"));	
			i++;
		}
	}
}
