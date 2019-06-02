/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_cbc_decrypt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:09:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 20:19:50 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des3_cbc_decrypt(t_des *s)
{
	s->buf_tmp = s->buf;
	decrypt_des(s, s->buf, s->subkey[2]);
	encrypt_des(s, s->result, s->subkey[1]);
	decrypt_des(s, s->result, s->subkey[0]);
	s->result = s->result ^ s->vector;
	s->vector = s->buf_tmp;
}
