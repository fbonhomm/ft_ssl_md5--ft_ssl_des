/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:36:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:44:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		sha224_final_shift(t_sha224 *s)
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

static void		sha224_final_convert(t_sha224 *s, unsigned char *hash)
{
	size_t		i;

	i = 0;
	while (i < 7)
	{
		ft_dec_to_hex(s->state[i], (char*)hash + (i * 8));
		i++;
	}
}

void			sha224_final(void *ctx, unsigned char *hash)
{
	uint32_t	i;
	t_sha224	*s;

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
		sha224_transform(s, s->data);
		ft_memset(s->data, 0, 56);
	}
	sha224_final_shift(s);
	sha224_transform(s, s->data);
	sha224_final_convert(s, hash);
}
