/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:03:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:12 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include <string.h>
# include <stdint.h>
# include <ft_ssl.h>

# define SHA256_ROT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

# define SHA256_CH(x,y,z)	(((x) & (y)) ^ (~(x) & (z)))
# define SHA256_MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA256_EP0(x)	(SHA256_ROT(x,2) ^ SHA256_ROT(x,13) ^ SHA256_ROT(x,22))
# define SHA256_EP1(x)	(SHA256_ROT(x,6) ^ SHA256_ROT(x,11) ^ SHA256_ROT(x,25))
# define SHA256_SIG0(x)	(SHA256_ROT(x,7) ^ SHA256_ROT(x,18) ^ ((x) >> 3))
# define SHA256_SIG1(x)	(SHA256_ROT(x,17) ^ SHA256_ROT(x,19) ^ ((x) >> 10))

typedef struct		s_sha256
{
	unsigned int	datalen;
	unsigned int	state[8];
	unsigned char	data[64];
	uint64_t		bitlen;
}					t_sha256;

void				sha256_init(void *ctx);
void				sha256_transform(t_sha256 *s, unsigned char *data);
void				sha256_update(void *ctx, unsigned char *data, size_t len);
void				sha256_final(void *ctx, unsigned char *hash);

#endif
