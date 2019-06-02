/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_get_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:27:03 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:27:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bit_get_idx(uint8_t *ptr, unsigned int idx, unsigned int *result)
{
	uint8_t	ch;

	ch = *ptr;
	*result = (ch & (1 << idx)) ? 1 : 0;
}
