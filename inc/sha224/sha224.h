/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:54:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

# include <string.h>
# include <stdint.h>
# include <ft_ssl.h>

# define SHA224_ROT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

# define SHA224_CH(x,y,z)	(((x) & (y)) ^ (~(x) & (z)))
# define SHA224_MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA224_EP0(x)	(SHA224_ROT(x,2) ^ SHA224_ROT(x,13) ^ SHA224_ROT(x,22))
# define SHA224_EP1(x)	(SHA224_ROT(x,6) ^ SHA224_ROT(x,11) ^ SHA224_ROT(x,25))
# define SHA224_SIG0(x)	(SHA224_ROT(x,7) ^ SHA224_ROT(x,18) ^ ((x) >> 3))
# define SHA224_SIG1(x)	(SHA224_ROT(x,17) ^ SHA224_ROT(x,19) ^ ((x) >> 10))

typedef struct		s_sha224
{
	uint32_t		datalen;
	uint32_t		state[8];
	uint64_t		bitlen;
	unsigned char	data[64];
}					t_sha224;

void				sha224_init(void *ctx);
void				sha224_update(void *ctx, unsigned char *data, size_t len);
void				sha224_final(void *ctx, unsigned char *hash);
void				sha224_transform(t_sha224 *s, unsigned char *data);

#endif
