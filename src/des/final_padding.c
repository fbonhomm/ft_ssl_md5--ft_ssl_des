/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:45:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:46:04 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			final_padding(uint64_t *final)
{
	int			i;
	int			j;
	uint64_t	tmp;

	i = 0;
	tmp = 0;
	while (i < 8)
	{
		j = 7;
		while (j >= 0)
		{
			if (((0x8 << j) & FIRST_BIT_8) != 0)
				tmp += (FIRST_BIT_64 >> ((i * 8) + j));
			j--;
		}
		i++;
	}
	*final = tmp;
}
