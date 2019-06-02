/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:54:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
# define SHA1_H

# include <string.h>
# include <stdint.h>
# include <ft_ssl.h>

# define SHA1_ROT(a,b)		(((a) << (b)) | ((a) >> (32 - (b))))

# define SHA1_CH(x,y,z)		((x & y) | (~(x) & z))
# define SHA1_MAJ(x,y,z)	((x & y) | (x & z) | (y & z))
# define SHA1_PAR(x,y,z)	(x ^ y ^ z)

typedef struct		s_sha1
{
	int				print;
	uint32_t		datalen;
	uint32_t		state[5];
	uint64_t		bitlen;
	unsigned char	data[64];
}					t_sha1;

void				sha1_init(void *ctx);
void				sha1_update(void *ctx, unsigned char *data, size_t len);
void				sha1_final(void *ctx, unsigned char *hash);
void				sha1_transform(t_sha1 *s, unsigned char *data);

#endif
