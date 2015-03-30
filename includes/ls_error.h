/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:58:32 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/30 20:03:22 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERROR_H
# define LS_ERROR_H

# include "ls.h"

# define ESTR			1
# define EOPT			2


# define ILLEGALOPT		0
# define NO_SUCH_FILE	2
# define NOt_ENOUGH_MEM	12

void	ls_error(int num, int type_error, char *p, int ls_exit);
void	error_illegalopt(char *p);
#endif
