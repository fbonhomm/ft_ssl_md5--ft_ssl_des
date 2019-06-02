/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:16:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/18 00:17:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			gen_keys(uint64_t key, uint64_t *new_key)
{
	uint32_t	left;
	uint32_t	right;
	uint32_t	arr_left[16];
	uint32_t	arr_right[16];

	key_64_to_56(key, &left, &right);
	key_bit_rotate(left, right, arr_left, arr_right);
	aggregate_key(new_key, arr_left, arr_right);
	permutation_pc2(new_key);
}
