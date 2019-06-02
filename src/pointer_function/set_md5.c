/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:36:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:08:08 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		set_md5(t_parser *ps)
{
	t_md5	*s;

	if ((s = (t_md5*)malloc(sizeof(t_md5))) == NULL)
		exit(-1);
	ps->pf->init = md5_init;
	ps->pf->update = md5_update;
	ps->pf->final = md5_final;
	ps->pf->ctx = s;
}
