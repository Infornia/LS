/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:38:14 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/20 17:59:56 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include "libft.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct timespec	t_timespec;

typedef struct	s_param
{
	char		*name;
	char		*user;
	char		*group;
	mode_t		st_mode;
	nlink_t		st_nlink;
	off_t		st_size;
	time_t		tv_sec;
	blkcnt_t	st_blocks;
	dev_t		st_rdev;
}				t_param;

typedef struct	s_data
{
	char	**params;
	int			nb_p;
	char	opts[5];
}				t_data;


t_data	*eval_option(char *s, t_data *d, int *opt);
t_data	*load_options(int ac, char **av);
t_data		*data_new(int nb);

void	ft_ls(t_data *d);
void	sort_dir(t_data *d, char *p);
void	add_dir(t_data *d, char *path, char *name, t_tree **dir);
void	add_file(t_data *d, char *path, char *name, t_tree **file);
int		ft_dir_isvalid(t_tree *tmp, char *name);

t_param	*ft_param_new(t_data *d, char *path, char *name);
t_param	*ft_param_fill(t_param **param, t_stat *file_stat, t_data *d);
void	data_del(t_data *d);
void	print(t_data *d);

#endif
