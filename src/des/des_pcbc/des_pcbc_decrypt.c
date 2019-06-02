/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_pcbc_decrypt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:09:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 19:58:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des_pcbc_decrypt(t_des *s)
{
	s->buf_tmp = s->buf;
	decrypt_des(s, s->buf, s->key);
	s->result = s->result ^ s->vector;
	s->vector = s->buf_tmp ^ s->result;
}
