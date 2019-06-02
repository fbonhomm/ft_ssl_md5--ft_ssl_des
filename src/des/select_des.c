/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_des.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:02:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:25:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		select_decrypt(t_des *s, int des_mode)
{
	if (des_mode == ECB_MODE)
		des_ecb_decrypt(s);
	else if (des_mode == CBC_MODE)
		des_cbc_decrypt(s);
	else if (des_mode == PCBC_MODE)
		des_pcbc_decrypt(s);
	else if (des_mode == ECB3_MODE)
		des3_ecb_decrypt(s);
	else if (des_mode == CBC3_MODE)
		des3_cbc_decrypt(s);
	else if (des_mode == PCBC3_MODE)
		des3_pcbc_decrypt(s);
}

static void		select_encrypt(t_des *s, int des_mode)
{
	if (des_mode == ECB_MODE)
		des_ecb_encrypt(s);
	else if (des_mode == CBC_MODE)
		des_cbc_encrypt(s);
	else if (des_mode == PCBC_MODE)
		des_pcbc_encrypt(s);
	else if (des_mode == ECB3_MODE)
		des3_ecb_encrypt(s);
	else if (des_mode == CBC3_MODE)
		des3_cbc_encrypt(s);
	else if (des_mode == PCBC3_MODE)
		des3_pcbc_encrypt(s);
}

static void		add_remain(t_des *s, uint8_t *dst)
{
	ft_memcpy(dst, s->remain, s->len_remain);
	ft_memcpy(dst + s->len_remain, s->bufs, s->len);
	s->len += s->len_remain;
	s->len_remain = 0;
}

void			add_padding(t_des *s, int des_mode)
{
	s->len_results = 0;
	s->buf = convert_8_to_64(s->remain);
	if (s->len_remain == 0)
		final_padding(&s->buf);
	else
		padding(&s->buf, s->len_remain);
	select_encrypt(s, des_mode);
	reverse(&s->result);
	s->results[s->len_results++] = s->result;
}

void			select_des(t_des *s, int mode, int des_mode)
{
	size_t		i;
	uint8_t		dst[BUF_SIZE_DES + 8];

	i = 0;
	s->len_results = 0;
	add_remain(s, dst);
	while ((i + 8) <= s->len)
	{
		s->buf = convert_8_to_64(dst + i);
		if (mode == 2)
			select_decrypt(s, des_mode);
		else
			select_encrypt(s, des_mode);
		reverse(&s->result);
		s->results[s->len_results++] = s->result;
		i += 8;
	}
	if (i < s->len)
	{
		s->len_remain = s->len - i;
		ft_bzero(s->remain, 8);
		ft_memcpy(s->remain, dst + i, s->len_remain);
	}
}
