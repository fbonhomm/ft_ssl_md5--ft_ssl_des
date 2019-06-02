/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_add_remain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:29:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 10:00:07 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			base64_add_remain(t_base64 *s, uint8_t *dst)
{
	ft_memcpy(dst, s->remain, s->len_remain);
	ft_memcpy(dst + s->len_remain, s->buf, s->len);
	s->len += s->len_remain;
	s->len_remain = 0;
}
