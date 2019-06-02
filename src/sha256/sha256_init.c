/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:21:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:22:33 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			sha256_init(void *ctx)
{
	t_sha256	*s;

	s = ctx;
	s->bitlen = 0;
	s->datalen = 0;
	s->state[0] = 0x6a09e667;
	s->state[1] = 0xbb67ae85;
	s->state[2] = 0x3c6ef372;
	s->state[3] = 0xa54ff53a;
	s->state[4] = 0x510e527f;
	s->state[5] = 0x9b05688c;
	s->state[6] = 0x1f83d9ab;
	s->state[7] = 0x5be0cd19;
}
