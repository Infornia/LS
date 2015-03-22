/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:38:14 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 18:43:10 by mwilk            ###   ########.fr       */
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

t_param	*tt_param_new(t_data *d, char *path, char *name);
void	tt_param_fill(t_param **param, t_stat file_stat, t_data *d);
void	tt_param_del(void *content, size_t content_size);

void	data_del(t_data *d);

void	ls_print(t_data *d, t_tree *file);
char	tt_file_type(mode_t mode);
void	print_ls(t_tree *head, int len);
void	print_rights(t_param *param);
void	print_total(t_tree *head, int len);
void		get_size(t_tree *head, int *size);
void		len_linx_max(t_tree *head, int *len);
void		len_user_max(t_tree *head, int *len);
void		len_group_max(t_tree *head, int *len);
void		len_size_max(t_tree *head, int *len);
void	print_optr(t_tree *head, int len);


void	tt_recursive(t_data *d, t_tree *head);
int		cmp_name(void *p1, void *p2);
int		cmp_date(void *p1, void *p2);
#endif
