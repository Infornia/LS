/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:38:14 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/19 20:11:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include "libft.h"
#include <stdlib.h>
#include <dirent.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct timespec	t_timespec;

typedef struct	s_avl
{
	void	*content;
	size_t	content_size;
	struct s_avl	right;
	struct s_avl	left;
}				t_avl;

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
void	add_dir(t_data *d, char *path, char *name, t_avl **dir);
void	add_file(t_data *d, char *path, char *name, t_avl **file);
int		ft_dir_isvalid(t_avl *tmp, char *name);

void	data_del(t_data *d);
void	print(t_data *d);

#endif
