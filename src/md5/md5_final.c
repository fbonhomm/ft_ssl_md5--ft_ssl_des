/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_final.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:51:13 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 17:42:17 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void			md5_final_shift(t_md5 *s)
{
	MD5_DBL_INT_ADD(&s->bitlen[0], &s->bitlen[1], 8 * s->datalen);
	s->data[56] = s->bitlen[0];
	s->data[57] = s->bitlen[0] >> 8;
	s->data[58] = s->bitlen[0] >> 16;
	s->data[59] = s->bitlen[0] >> 24;
	s->data[60] = s->bitlen[1];
	s->data[61] = s->bitlen[1] >> 8;
	s->data[62] = s->bitlen[1] >> 16;
	s->data[63] = s->bitlen[1] >> 24;
	md5_transform(s, s->data);
}

static void			md5_final_rot(t_md5 *s, unsigned char *hash)
{
	size_t			i;
	unsigned int	st;

	i = 0;
	while (i < 4)
	{
		st = s->state[i];
		st = ((st & (0x0000FFFF)) << 16) | ((st & (0xFFFF0000)) >> 16);
		st = ((st & (0x00FF00FF)) << 8) | ((st & (0xFF00FF00)) >> 8);
		ft_dec_to_hex(st, (char*)hash + (i * 8));
		i++;
	}
}

void				md5_final(void *ctx, unsigned char *hash)
{
	t_md5			*s;
	unsigned int	i;

	s = ctx;
	i = s->datalen;
	if (s->datalen < 56)
	{
		s->data[i++] = 0x80;
		while (i < 56)
			s->data[i++] = 0x00;
	}
	else
	{
		s->data[i++] = 0x80;
		while (i < 64)
			s->data[i++] = 0x00;
		md5_transform(s, s->data);
		ft_memset(s->data, 0, 56);
	}
	md5_final_shift(s);
	md5_final_rot(s, hash);
}
