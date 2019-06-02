/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:00:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 14:01:06 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			remove_newline(uint8_t *buf, size_t *len)
{
	size_t		i;
	size_t		len_tmp;
	uint8_t		tmp[BUF_SIZE_BASE64];

	i = 0;
	len_tmp = 0;
	while (i < *len)
	{
		if (buf[i] != NEWLINE)
			tmp[len_tmp++] = buf[i];
		i++;
	}
	*len = len_tmp;
	ft_memcpy(buf, tmp, len_tmp);
}
