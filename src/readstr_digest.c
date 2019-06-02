/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readstr_digest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:59:05 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 19:57:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void				readstr_digest(t_parser *ps)
{
	t_option		*opt;
	t_pointer_funct	*pf;

	opt = search_option(ps->opt_digest, "-s");
	if (opt)
	{
		pf = ps->pf;
		ps->str = ft_strnew(130);
		pf->init(pf->ctx);
		pf->update(pf->ctx, opt->content, ft_strlen(opt->content));
		pf->final(pf->ctx, ps->str);
	}
}
