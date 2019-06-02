/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregate_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:30:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:31:02 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	aggregate_data(uint32_t left, uint32_t right, uint64_t *ptr)
{
	*ptr = 0;
	*ptr = ((uint64_t)right << 32) | (left & 0xFFFFFFFFFFFFFFFF);
}
