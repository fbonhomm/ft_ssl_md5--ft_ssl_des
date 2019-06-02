/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:09:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:37:16 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			option_a_update_enc(t_base64 *s, uint64_t nb, size_t len)
{
	size_t		i;
	uint8_t		*p;
	uint8_t		result[8];

	i = 0;
	p = (uint8_t *)&nb;
	while (i < 8)
	{
		result[i] = p[i];
		i++;
	}
	s->len = len;
	ft_memcpy(s->buf, result, len);
	base64_update_enc(s);
}

void			option_a_final_enc(t_base64 *s)
{
	base64_final_enc(s);
}

void			option_a_update_dec(
					t_des *d, t_base64 *s, uint8_t *buf, size_t len)
{
	s->len = len;
	ft_memcpy(s->buf, buf, len);
	remove_newline(s->buf, &s->len);
	base64_update_dec(s);
	d->len = s->tmp_trans_data_len;
	ft_memcpy(d->bufs, s->data, s->tmp_trans_data_len);
}

void			option_a_final_dec(t_des *d, t_base64 *s)
{
	s->opt_a = 1;
	base64_final_dec(s);
	d->len = s->tmp_trans_data_len;
	ft_memcpy(d->bufs, s->data, s->tmp_trans_data_len);
}
