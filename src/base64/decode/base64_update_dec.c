/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_update_dec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:49:17 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 10:36:33 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	base64_update_dec(t_base64 *s)
{
	uint8_t			dst[BUF_SIZE_BASE64 + 4];

	base64_add_remain(s, dst);
	s->tmp_read_data_len = 0;
	s->tmp_trans_data_len = 0;
	base64_transform_dec(s, dst, s->len);
	s->read_data_len += s->len;
	s->trans_data_len += s->tmp_trans_data_len;
}
