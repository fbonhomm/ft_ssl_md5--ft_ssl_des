/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_ecb_decrypt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:09:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 20:19:47 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des3_ecb_decrypt(t_des *s)
{
	decrypt_des(s, s->buf, s->subkey[2]);
	encrypt_des(s, s->result, s->subkey[1]);
	decrypt_des(s, s->result, s->subkey[0]);
}
