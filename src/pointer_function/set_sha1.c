/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sha1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:37:22 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:08:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			set_sha1(t_parser *ps)
{
	t_sha1	*s;

	if ((s = (t_sha1*)malloc(sizeof(t_sha1))) == NULL)
		exit(-1);
	ps->pf->init = sha1_init;
	ps->pf->update = sha1_update;
	ps->pf->final = sha1_final;
	ps->pf->ctx = s;
}
