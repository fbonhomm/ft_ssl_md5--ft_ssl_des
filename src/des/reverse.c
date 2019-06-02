/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:55:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:55:33 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			reverse(uint64_t *final)
{
	int			i;
	int			j;
	uint64_t	tmp;

	i = 0;
	tmp = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (((*final << ((i * 8) + j)) & FIRST_BIT_64) != 0)
				tmp += (FIRST_BIT_64 >> (((7 - i) * 8) + j));
			j++;
		}
		i++;
	}
	*final = tmp;
}
