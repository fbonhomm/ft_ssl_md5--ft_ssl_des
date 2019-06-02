/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:27:47 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:29:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void				sha256_update(void *ctx, unsigned char *data, size_t len)
{
	t_sha256		*s;
	unsigned int	i;

	s = ctx;
	i = 0;
	while (i < len)
	{
		s->data[s->datalen] = data[i];
		s->datalen++;
		if (s->datalen == 64)
		{
			sha256_transform(s, s->data);
			s->bitlen += 512;
			s->datalen = 0;
		}
		i++;
	}
}
