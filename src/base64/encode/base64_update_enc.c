/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_update_enc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:14:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 10:51:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	base64_update_enc(t_base64 *s)
{
	uint8_t			dst[BUF_SIZE_BASE64 + 3];

	base64_add_remain(s, dst);
	s->nl = 0;
	s->tmp_read_data_len = 0;
	s->tmp_trans_data_len = 0;
	base64_transform_enc(s, dst, s->len);
	s->read_data_len += s->len;
	s->trans_data_len += (s->tmp_trans_data_len - s->nl);
}
