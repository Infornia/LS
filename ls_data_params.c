/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dat_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:18:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 17:44:06 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_data		*data_new(int nb)
{
	t_data	*d;

	if(!(d = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if(!(d->params = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	d->params[nb] = NULL;
	d->nb_p = nb;
	return (d);
}

void		data_del(t_data *d)
{
	int		i;

	i = -1;
	if (d->params)
	{
		while (++i < d->nb_p)
			free(d->params[i]);
		free(d->params);
	}
	free(d);
	d = NULL;
}

void	tt_param_fill(t_param **param, t_stat file_stat, t_data *d)
{
	(*param)->st_mode = file_stat.st_mode;
	//(*param)->tv_sec = file_stat.st_mtimespec.tv_sec;
	(*param)->st_nlink = file_stat.st_nlink;
	if (ft_strchr(d->opts, 'l'))
	{
		(*param)->user = getpwuid(file_stat.st_uid)->pw_name;
		(*param)->group = getgrgid(file_stat.st_gid)->gr_name;
		(*param)->st_size = file_stat.st_size;
		(*param)->st_blocks = file_stat.st_blocks;
		(*param)->st_rdev = file_stat.st_rdev;
	}
}

t_param		*tt_param_new(t_data *d, char *path, char *name)
{
	t_param		*param;
	t_stat		file_stat;
	char		*tmp;
	char		*tmp2;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->name = ft_strdup(name);
	tmp2 = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp2, name);
	free(tmp2);
	if (stat(tmp, &file_stat) < 0)
		perror(tmp);
	else
		tt_param_fill(&param, file_stat, d);
	free(tmp);
	return (param);
}

void	tt_param_del(void *content, size_t content_size)
{
	t_param		*tmp;

	(void)content_size;
	tmp = (t_param *) content;
	if (tmp)
	{
		ft_strdel(&tmp->name);
		ft_memdel(&content);
	}
}
