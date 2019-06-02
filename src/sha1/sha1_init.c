/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:39:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/30 15:11:25 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			sha1_init(void *ctx)
{
	t_sha1		*s;

	s = ctx;
	s->bitlen = 0;
	s->datalen = 0;
	s->print = 1;
	s->state[0] = 0x67452301;
	s->state[1] = 0xEFCDAB89;
	s->state[2] = 0x98BADCFE;
	s->state[3] = 0x10325476;
	s->state[4] = 0xC3D2E1F0;
}
