/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:56:35 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 18:10:43 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include "init_md5.h"

#define T_A 0
#define T_B 1
#define T_C 2
#define T_D 3
#define T_F 4
#define T_T 5

static void			md5_transform_sub(unsigned int *w, unsigned char *data)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		w[i] = (data[j])
			+ (data[j + 1] << 8)
			+ (data[j + 2] << 16)
			+ (data[j + 3] << 24);
		i++;
		j += 4;
	}
}

static void			md5_transform_init(unsigned int *arr, t_md5 *m)
{
	arr[T_A] = m->state[0];
	arr[T_B] = m->state[1];
	arr[T_C] = m->state[2];
	arr[T_D] = m->state[3];
}

static void			md5_transform_append(unsigned int *arr, t_md5 *m)
{
	m->state[0] += arr[T_A];
	m->state[1] += arr[T_B];
	m->state[2] += arr[T_C];
	m->state[3] += arr[T_D];
}

void				md5_transform(t_md5 *m, unsigned char *data)
{
	int				i;
	unsigned int	w[16];
	unsigned int	arr[6];

	md5_transform_sub(w, data);
	md5_transform_init(arr, m);
	i = -1;
	while (++i < 64)
	{
		if (i < 16)
			arr[T_F] = F_MD5(arr[T_B], arr[T_C], arr[T_D]);
		else if (i < 32)
			arr[T_F] = G_MD5(arr[T_B], arr[T_C], arr[T_D]);
		else if (i < 48)
			arr[T_F] = H_MD5(arr[T_B], arr[T_C], arr[T_D]);
		else
			arr[T_F] = I_MD5(arr[T_B], arr[T_C], arr[T_D]);
		arr[T_T] = arr[T_D];
		arr[T_D] = arr[T_C];
		arr[T_C] = arr[T_B];
		arr[T_B] = MD5_ROTLEFT((arr[T_A] + arr[T_F] + g_k_md5[i]
			+ w[g_d_md5[i]]), g_r_md5[i]) + arr[T_B];
		arr[T_A] = arr[T_T];
	}
	md5_transform_append(arr, m);
}
