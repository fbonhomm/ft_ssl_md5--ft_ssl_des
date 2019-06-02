/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:24:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/30 12:07:20 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int		is_hex(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if ((ft_toupper(str[i]) < 48)
			|| (ft_toupper(str[i]) > 57 && ft_toupper(str[i]) < 65)
				|| (ft_toupper(str[i]) > 70))
			return (0);
		i++;
	}
	return (1);
}
