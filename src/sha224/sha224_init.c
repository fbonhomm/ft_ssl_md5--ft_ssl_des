/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:39:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:39:36 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			sha224_init(void *ctx)
{
	t_sha224	*s;

	s = ctx;
	s->bitlen = 0;
	s->datalen = 0;
	s->state[0] = 0xc1059ed8;
	s->state[1] = 0x367cd507;
	s->state[2] = 0x3070dd17;
	s->state[3] = 0xf70e5939;
	s->state[4] = 0xffc00b31;
	s->state[5] = 0x68581511;
	s->state[6] = 0x64f98fa7;
	s->state[7] = 0xbefa4fa4;
}
