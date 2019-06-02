/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_final_enc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:51:18 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 11:03:47 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	base64_final_enc(t_base64 *s)
{
	int	pad;

	s->nl = 0;
	s->tmp_read_data_len = 0;
	s->tmp_trans_data_len = 0;
	base64_transform_padding(s, s->remain, s->len_remain);
	pad = s->tmp_read_data_len % 3;
	if (pad > 0)
	{
		while (pad < 3)
		{
			s->data[s->tmp_trans_data_len++] = '=';
			pad++;
		}
	}
	s->data[s->tmp_trans_data_len] = 0;
}
