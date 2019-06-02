/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:27:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 17:29:11 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	error(t_parser *ps, char *obj, char *str)
{
	ps->errors = ft_arrpush(ps->errors,\
		ft_strjoin_mult(6, "ft_ssl: ", ps->cmd, ": ", obj, ": ", str));
}
