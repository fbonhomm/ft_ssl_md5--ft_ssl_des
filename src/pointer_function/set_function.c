/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:35:33 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:48:25 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void	set_digest(t_parser *ps, char *cmd)
{
	if (ft_strcmp(cmd, "md5") == 0)
		set_md5(ps);
	else if (ft_strcmp(cmd, "sha256") == 0)
		set_sha256(ps);
	else if (ft_strcmp(cmd, "sha224") == 0)
		set_sha224(ps);
}

void		set_function(t_parser *ps)
{
	if (!ft_strcmp(ps->type, "digest"))
	{
		ps->pf = (t_pointer_funct*)malloc(sizeof(t_pointer_funct));
		set_digest(ps, ps->cmd);
	}
}
