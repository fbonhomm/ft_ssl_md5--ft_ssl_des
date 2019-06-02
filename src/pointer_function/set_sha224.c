/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sha224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:37:22 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:08:11 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			set_sha224(t_parser *ps)
{
	t_sha224	*s;

	if ((s = (t_sha224*)malloc(sizeof(t_sha224))) == NULL)
		exit(-1);
	ps->pf->init = sha224_init;
	ps->pf->update = sha224_update;
	ps->pf->final = sha224_final;
	ps->pf->ctx = s;
}
