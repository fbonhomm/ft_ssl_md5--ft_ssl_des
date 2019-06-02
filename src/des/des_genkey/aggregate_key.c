/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregate_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 00:12:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/18 00:16:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			aggregate_key(
	uint64_t *new, uint32_t *arr_left, uint32_t *arr_right)
{
	int			i;
	int			j;
	uint64_t	tmp;

	i = 0;
	while (i < 16)
	{
		j = 0;
		tmp = 0;
		while (j < 28)
		{
			if (((arr_left[i] << (j + 4)) & FIRST_BIT_32) != 0)
				tmp += (FIRST_BIT_64 >> j);
			if (((arr_right[i] << (j + 4)) & FIRST_BIT_32) != 0)
				tmp += (FIRST_BIT_64 >> (j + 28));
			j++;
		}
		new[i++] = tmp;
	}
}
