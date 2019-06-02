/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_transform_dec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:41:14 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 10:39:40 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint32_t	g_chars_dec[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 63, 52,
	53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 65, 0, 0, 0, 0, 1, 2, 3, 4, 5,
	6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static uint32_t	base64_transform_dec_set_ch(
	t_base64 *s, unsigned char *data, size_t len)
{
	if (s->tmp_read_data_len >= len)
		return (0);
	if (data[s->tmp_read_data_len] == '=')
	{
		s->tmp_read_data_len++;
		return (0);
	}
	return (g_chars_dec[data[s->tmp_read_data_len++]]);
}

void			base64_transform_dec(
	t_base64 *s, unsigned char *data, size_t len)
{
	uint32_t	octet[4];
	uint32_t	combined;

	while ((s->tmp_read_data_len + 4) < len)
	{
		octet[0] = base64_transform_dec_set_ch(s, data, len);
		octet[1] = base64_transform_dec_set_ch(s, data, len);
		octet[2] = base64_transform_dec_set_ch(s, data, len);
		octet[3] = base64_transform_dec_set_ch(s, data, len);
		combined = (octet[0] << (3 * 6))
			+ (octet[1] << (2 * 6))
			+ (octet[2] << (1 * 6))
			+ (octet[3] << (0 * 6));
		s->data[s->tmp_trans_data_len++] = (combined >> (2 * 8)) & 0xFF;
		s->data[s->tmp_trans_data_len++] = (combined >> (1 * 8)) & 0xFF;
		s->data[s->tmp_trans_data_len++] = (combined >> (0 * 8)) & 0xFF;
	}
	s->data[s->tmp_trans_data_len] = 0;
	s->len_remain = len - s->tmp_read_data_len;
	ft_memcpy(s->remain, data + s->tmp_read_data_len, s->len_remain);
}

void			base64_transform_final_dec(
	t_base64 *s, unsigned char *data, size_t len)
{
	uint32_t	octet[4];
	uint32_t	combined;

	while (s->tmp_read_data_len < len)
	{
		octet[0] = base64_transform_dec_set_ch(s, data, len);
		octet[1] = base64_transform_dec_set_ch(s, data, len);
		octet[2] = base64_transform_dec_set_ch(s, data, len);
		octet[3] = base64_transform_dec_set_ch(s, data, len);
		combined = (octet[0] << (3 * 6))
			+ (octet[1] << (2 * 6))
			+ (octet[2] << (1 * 6))
			+ (octet[3] << (0 * 6));
		if ((s->tmp_trans_data_len < len && octet[0] && octet[1]) || s->opt_a)
			s->data[s->tmp_trans_data_len++] = (combined >> (2 * 8)) & 0xFF;
		if ((s->tmp_trans_data_len < len && octet[1] && octet[2]) || s->opt_a)
			s->data[s->tmp_trans_data_len++] = (combined >> (1 * 8)) & 0xFF;
		if ((s->tmp_trans_data_len < len && octet[2] && octet[3]) || s->opt_a)
			s->data[s->tmp_trans_data_len++] = (combined >> (0 * 8)) & 0xFF;
	}
}
