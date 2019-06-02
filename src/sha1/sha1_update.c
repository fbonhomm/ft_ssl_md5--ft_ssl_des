/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:42:10 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:38:45 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			sha1_update(void *ctx, unsigned char *data, size_t len)
{
	t_sha1		*s;
	uint32_t	i;

	s = ctx;
	i = 0;
	while (i < len)
	{
		s->data[s->datalen++] = data[i];
		if (s->datalen == 64)
		{
			sha1_transform(s, s->data);
			s->bitlen += 512;
			s->datalen = 0;
		}
		i++;
	}
}
