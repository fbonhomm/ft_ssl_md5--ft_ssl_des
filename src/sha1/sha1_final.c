/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:36:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:40:24 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		sha1_final_shift(t_sha1 *s)
{
	s->bitlen += s->datalen * 8;
	s->data[63] = s->bitlen;
	s->data[62] = s->bitlen >> 8;
	s->data[61] = s->bitlen >> 16;
	s->data[60] = s->bitlen >> 24;
	s->data[59] = s->bitlen >> 32;
	s->data[58] = s->bitlen >> 40;
	s->data[57] = s->bitlen >> 48;
	s->data[56] = s->bitlen >> 56;
}

static void		sha1_final_convert(t_sha1 *s, unsigned char *hash)
{
	size_t		i;

	i = 0;
	if (s->print)
	{
		while (i < 5)
		{
			ft_dec_to_hex(s->state[i], (char*)hash + (i * 8));
			i++;
		}
		hash[i * 8] = 0;
	}
	else
	{
		while (i < 20)
		{
			hash[i] = ((s->state[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
			i++;
		}
	}
}

void			sha1_final(void *ctx, unsigned char *hash)
{
	t_sha1		*s;
	uint32_t	i;

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
		sha1_transform(s, s->data);
		ft_memset(s->data, 0, 56);
	}
	sha1_final_shift(s);
	sha1_transform(s, s->data);
	sha1_final_convert(s, hash);
}
