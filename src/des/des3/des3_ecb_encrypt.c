/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3_ecb_encrypt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:45:45 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 20:19:46 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			des3_ecb_encrypt(t_des *s)
{
	encrypt_des(s, s->buf, s->subkey[0]);
	decrypt_des(s, s->result, s->subkey[1]);
	encrypt_des(s, s->result, s->subkey[2]);
}
