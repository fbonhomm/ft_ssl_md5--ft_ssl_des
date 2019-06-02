/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_pcbc_encrypt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:45:45 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 20:08:02 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des_pcbc_encrypt(t_des *s)
{
	s->buf_tmp = s->buf;
	s->buf = s->buf ^ s->vector;
	encrypt_des(s, s->buf, s->key);
	s->vector = s->buf_tmp ^ s->result;
}
