/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:50:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 17:42:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <string.h>
# include <stdint.h>
# include <ft_ssl.h>

typedef struct		s_md5
{
	unsigned int	datalen;
	unsigned int	state[4];
	unsigned int	bitlen[2];
	unsigned char	data[64];
}					t_md5;

void				md5_init(void *ctx);
void				md5_update(void *ctx, unsigned char *data, size_t len);
void				md5_final(void *ctx, unsigned char *hash);
void				md5_transform(t_md5 *m, unsigned char *data);
void            	MD5_DBL_INT_ADD(
						unsigned int *a, unsigned int *b, unsigned int c);
unsigned int		MD5_ROTLEFT(unsigned int a, unsigned int b);
unsigned int		F_MD5(unsigned int x, unsigned int y, unsigned int z);
unsigned int		G_MD5(unsigned int x, unsigned int y, unsigned int z);
unsigned int		H_MD5(unsigned int x, unsigned int y, unsigned int z);
unsigned int		I_MD5(unsigned int x, unsigned int y, unsigned int z);

#endif
