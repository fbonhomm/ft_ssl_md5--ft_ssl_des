/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:39:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:50 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include <stdint.h>
# include <strings.h>

# define BUF_SIZE_BASE64	4096
# define NEWLINE			10

typedef struct		s_base64
{
	size_t			nl;
	size_t			size;
	size_t			read_data_len;
	size_t			trans_data_len;
	size_t			tmp_read_data_len;
	size_t			tmp_trans_data_len;
	size_t			len;
	size_t			len_remain;
	uint8_t			buf[BUF_SIZE_BASE64];
	uint8_t			data[BUF_SIZE_BASE64 * 4];
	uint8_t			remain[4];
	short			opt_a;
}					t_base64;

void				base64_init(t_base64 *s);
void				base64_update_enc(t_base64 *s);
void				base64_transform_enc(
						t_base64 *s, unsigned char *data, size_t len);
void				base64_transform_padding(
						t_base64 *s, unsigned char *data, size_t len);
void				base64_final_enc(t_base64 *s);
void				base64_update_dec(t_base64 *s);
void				base64_transform_dec(
						t_base64 *s, unsigned char *data, size_t len);
void				base64_final_dec(t_base64 *s);
void				base64_transform_final_dec(
						t_base64 *s, unsigned char *data, size_t len);

#endif
