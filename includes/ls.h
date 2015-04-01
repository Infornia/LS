/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:38:14 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/01 17:17:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include "libft.h"
#include "ls_error.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

# define MINORBITS		20
# define MINORMASK		((1U << MINORBITS) - 1)
# define MAJOR(dev)			((unsigned int) ((dev) >> (MINORBITS + 4)))
# define MINOR(dev)			((unsigned int) ((dev) & MINORMASK))

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
	char	opts[6];
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

void	ls_prints(t_data *d, t_tree *file);
void		ls_print_param(t_tree *node);
char	tt_file_type(mode_t mode);
void	tt_print_ls(t_tree *head, int len[4]);
void	tt_print_ls_rev(t_tree *head, int len[4]);
void		tt_print_params(t_tree *head, int len[4]);
void			print_link(t_param *param, int len_link);
void			print_size(t_param *param, int len_size);
void			print_name(t_param *param, int len_name);
void			print_group(t_param *param, int len_group);
void			print_time(time_t timestamp);
void			print_space(int len, int len_max);
void	print_rights(t_param *param);
void	print_total(t_tree *head, int len[5]);
void		get_size(t_tree *head, int *size);
void		len_link_max(t_tree *head, int *len);
void		len_user_max(t_tree *head, int *len);
void		len_group_max(t_tree *head, int *len);
void		len_size_max(t_tree *head, int *len);
void	print_optr(t_tree *head, int len[5]);


void	tt_recursive(t_data *d, t_tree *head);
int		cmp_name(void *p1, void *p2);
int		cmp_date(void *p1, void *p2);
#endif
