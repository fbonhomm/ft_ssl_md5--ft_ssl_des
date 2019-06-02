/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:41:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:44:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint8_t g_int_to_hex2[16] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
	0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF
};

void		check_padding(uint64_t final, size_t *len)
{
	int		i;
	int		nb;
	uint8_t	tmp[8];

	i = -1;
	nb = 0;
	*len = 8;
	while (++i < 8)
	{
		tmp[i] = 0;
		tmp[i] = final >> (i * 8);
	}
	if (tmp[7] >= 0x1 && tmp[7] <= 0x8)
	{
		i = 7;
		while (i >= 0)
		{
			if (tmp[7] == tmp[i--])
				nb++;
			else
				break ;
		}
		if (g_int_to_hex2[nb] == tmp[7])
			*len = 8 - g_int_to_hex2[nb];
	}
}
