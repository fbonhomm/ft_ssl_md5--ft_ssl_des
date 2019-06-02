/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_transform_enc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:05:48 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 13:48:12 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint8_t g_chars_enc[65] = \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static void		set_withespace(t_base64 *s)
{
	if (((s->trans_data_len + s->tmp_trans_data_len) != 0)
		&& ((s->trans_data_len + (s->tmp_trans_data_len - s->nl)) % 64) == 0)
	{
		s->data[s->tmp_trans_data_len++] = '\n';
		s->nl++;
	}
}

static void		set_in_data(t_base64 *s, uint32_t combined, int min)
{
	int			j;
	int			i;

	i = 3;
	while (i >= min)
	{
		j = 6 * i;
		set_withespace(s);
		s->data[s->tmp_trans_data_len++] = g_chars_enc[(combined >> j) & 0x3F];
		i--;
	}
}

void			base64_transform_padding(
	t_base64 *s, unsigned char *data, size_t len)
{
	uint32_t	combined;

	combined = 0;
	if (len == 1)
	{
		combined = (data[s->tmp_read_data_len++] << 16);
		set_in_data(s, combined, 2);
	}
	else if (len == 2)
	{
		combined = (data[s->tmp_read_data_len++] << 16)
				+ (data[s->tmp_read_data_len++] << 8);
		set_in_data(s, combined, 1);
	}
}

static uint32_t	set_combined(t_base64 *s, unsigned char *data)
{
	uint32_t	combined;

	combined = 0;
	combined = (data[s->tmp_read_data_len++] << (8 * 2))
				+ (data[s->tmp_read_data_len++] << (8 * 1))
				+ (data[s->tmp_read_data_len++] << (8 * 0));
	return (combined);
}

void			base64_transform_enc(
	t_base64 *s, unsigned char *data, size_t len)
{
	uint32_t	combined;

	while ((s->tmp_read_data_len + 3) <= len)
	{
		combined = set_combined(s, data);
		set_in_data(s, combined, 0);
	}
	s->len_remain = len - s->tmp_read_data_len;
	s->data[s->tmp_trans_data_len] = 0;
	ft_memcpy(s->remain, data + s->tmp_read_data_len, s->len_remain);
}
