/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bit_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:19:14 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/18 00:20:36 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint32_t g_br[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

void		rotate_left_28(uint32_t *ptr)
{
	*ptr <<= 1;
	if (((*ptr << 3) & FIRST_BIT_32) != 0)
		*ptr += (FIRST_BIT_32 >> 31);
}

void		key_bit_rotate(
	uint32_t left, uint32_t right, uint32_t *arr_left, uint32_t *arr_right)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < g_br[i])
		{
			rotate_left_28(&left);
			rotate_left_28(&right);
			j++;
		}
		arr_left[i] = left;
		arr_right[i] = right;
		i++;
	}
}
