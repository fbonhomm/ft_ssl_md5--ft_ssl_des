/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:39:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:41:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "init_sha1.h"

static uint32_t		sha1_logic_ft(size_t t, uint32_t b, uint32_t c, uint32_t d)
{
	if (t < 20)
		return (SHA1_CH(b, c, d));
	if (t < 40)
		return (SHA1_PAR(b, c, d));
	if (t < 60)
		return (SHA1_MAJ(b, c, d));
	return (SHA1_PAR(b, c, d));
}

static void			sha1_transform_switch(uint32_t *tmp, uint32_t *m)
{
	size_t		i;
	uint32_t	t;

	i = 0;
	while (i < 80)
	{
		t = SHA1_ROT(tmp[0], 5)
			+ sha1_logic_ft(i, tmp[1], tmp[2], tmp[3])
			+ tmp[4]
			+ g_k_sha1[i / 20] + m[i];
		tmp[4] = tmp[3];
		tmp[3] = tmp[2];
		tmp[2] = SHA1_ROT(tmp[1], 30);
		tmp[1] = tmp[0];
		tmp[0] = t;
		i++;
	}
}

void				sha1_transform(t_sha1 *s, unsigned char *data)
{
	uint32_t		m[80];
	uint32_t		tmp[12];

	tmp[11] = 0;
	tmp[10] = 0;
	while (tmp[10] < 16)
	{
		m[tmp[10]++] = (data[tmp[11]] << 24) | (data[tmp[11] + 1] << 16)
			| (data[tmp[11] + 2] << 8) | (data[tmp[11] + 3]);
		tmp[11] += 4;
	}
	while (tmp[10] < 80)
	{
		m[tmp[10]] = SHA1_ROT(m[tmp[10] - 3]
			^ m[tmp[10] - 8] ^ m[tmp[10] - 14] ^ m[tmp[10] - 16], 1);
		tmp[10]++;
	}
	tmp[10] = -1;
	while (++tmp[10] < 5)
		tmp[tmp[10]] = s->state[tmp[10]];
	sha1_transform_switch(tmp, m);
	tmp[10] = -1;
	while (++tmp[10] < 8)
		s->state[tmp[10]] += tmp[tmp[10]];
}
