/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:51:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:54:46 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint8_t g_int_to_hex[16] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
	0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF
};

static void		copy_data(uint64_t *final, uint64_t *tmp, size_t len)
{
	int			j;
	size_t		i;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			if (((*final << ((i * 8) + j)) & FIRST_BIT_64) != 0)
				*tmp += (FIRST_BIT_64 >> ((i * 8) + j));
			j++;
		}
		i++;
	}
}

static void		copy_padding(uint64_t *tmp, uint8_t nb, size_t len)
{
	int			j;

	while (len < 8)
	{
		j = 7;
		while (j >= 0)
		{
			if (((nb << j) & FIRST_BIT_8) != 0)
				*tmp += (FIRST_BIT_64 >> ((len * 8) + j));
			j--;
		}
		len++;
	}
}

void			padding(uint64_t *final, size_t len)
{
	uint8_t		nb;
	uint64_t	tmp;

	tmp = 0;
	nb = g_int_to_hex[(8 - len)];
	if ((8 - len) != 0)
	{
		copy_data(final, &tmp, len);
		copy_padding(&tmp, nb, len);
		*final = tmp;
	}
}
