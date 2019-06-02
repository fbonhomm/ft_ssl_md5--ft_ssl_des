/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:29:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 13:47:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		display_error(t_parser *ps)
{
	size_t	i;

	i = 0;
	if (ps->errors)
	{
		write(2, "\n", 1);
		while (ps->errors[i])
			ft_putendl_fd(ps->errors[i++], 2);
	}
}
