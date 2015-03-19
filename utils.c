/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 16:18:19 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/19 18:09:19 by mwilk            ###   ########.fr       */
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
