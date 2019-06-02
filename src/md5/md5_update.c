/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:10:46 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 17:41:35 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void				md5_update(void *ctx, unsigned char *data, size_t len)
{
	t_md5			*m;
	unsigned int	i;

	i = 0;
	m = ctx;
	while (i < len)
	{
		m->data[m->datalen] = data[i];
		m->datalen++;
		if (m->datalen == 64)
		{
			md5_transform(m, m->data);
			MD5_DBL_INT_ADD(&m->bitlen[0], &m->bitlen[1], 512);
			m->datalen = 0;
		}
		i++;
	}
}
