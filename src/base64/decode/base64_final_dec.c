/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_final_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:51:18 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/27 10:40:35 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	base64_final_dec(t_base64 *s)
{
	s->tmp_read_data_len = 0;
	s->tmp_trans_data_len = 0;
	base64_transform_final_dec(s, s->remain, s->len_remain);
}
