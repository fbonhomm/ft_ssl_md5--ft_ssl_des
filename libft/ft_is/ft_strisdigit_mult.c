/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:46:44 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:55:45 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strisdigit_mult(size_t nb, ...)
{
	size_t			i;
	size_t			ret;
	va_list			ap;

	if (nb <= 0)
		return (0);
	i = 0;
	ret = 1;
	va_start(ap, nb);
	while (i < nb)
	{
		if (!ft_strisdigit(va_arg(ap, char*)))
		{
			ret = 0;
			break ;
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
