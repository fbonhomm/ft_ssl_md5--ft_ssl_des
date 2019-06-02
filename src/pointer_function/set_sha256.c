/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sha256.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:37:45 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:08:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			set_sha256(t_parser *ps)
{
	t_sha256	*s;

	if ((s = (t_sha256*)malloc(sizeof(t_sha256))) == NULL)
		exit(-1);
	ps->pf->init = sha256_init;
	ps->pf->update = sha256_update;
	ps->pf->final = sha256_final;
	ps->pf->ctx = s;
}
