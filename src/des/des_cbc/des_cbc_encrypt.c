/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_cbc_encrypt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:45:45 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 19:51:22 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des_cbc_encrypt(t_des *s)
{
	s->buf = s->buf ^ s->vector;
	encrypt_des(s, s->buf, s->key);
	s->vector = s->result;
}
