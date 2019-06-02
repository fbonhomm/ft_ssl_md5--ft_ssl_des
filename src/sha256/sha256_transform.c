/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:22:41 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:27:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "init_sha256.h"

static void			sha256_transform_switch(uint32_t *tmp, uint32_t *m)
{
	size_t			i;

	i = 0;
	while (i < 64)
	{
		tmp[8] = tmp[7] + SHA256_EP1(tmp[4])
			+ SHA256_CH(tmp[4], tmp[5], tmp[6]) + g_k_sha256[i] + m[i];
		tmp[9] = SHA256_EP0(tmp[0]) + SHA256_MAJ(tmp[0], tmp[1], tmp[2]);
		tmp[7] = tmp[6];
		tmp[6] = tmp[5];
		tmp[5] = tmp[4];
		tmp[4] = tmp[3] + tmp[8];
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[0];
		tmp[0] = tmp[8] + tmp[9];
		i++;
	}
}

void				sha256_transform(t_sha256 *s, unsigned char *data)
{
	uint32_t		m[64];
	uint32_t		tmp[12];

	tmp[11] = 0;
	tmp[10] = 0;
	while (tmp[10] < 16)
	{
		m[tmp[10]++] = (data[tmp[11]] << 24) | (data[tmp[11] + 1] << 16)
			| (data[tmp[11] + 2] << 8) | (data[tmp[11] + 3]);
		tmp[11] += 4;
	}
	while (tmp[10] < 64)
	{
		m[tmp[10]] = SHA256_SIG1(m[tmp[10] - 2]) + m[tmp[10] - 7]
			+ SHA256_SIG0(m[tmp[10] - 15]) + m[tmp[10] - 16];
		tmp[10]++;
	}
	tmp[10] = -1;
	while (++tmp[10] < 8)
		tmp[tmp[10]] = s->state[tmp[10]];
	sha256_transform_switch(tmp, m);
	tmp[10] = -1;
	while (++tmp[10] < 8)
		s->state[tmp[10]] += tmp[tmp[10]];
}
