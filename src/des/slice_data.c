/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:56:53 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/17 22:57:36 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	slice_data(uint64_t ptr, uint32_t *left, uint32_t *right)
{
	*left = 0;
	*right = 0;
	*left = ptr >> 32;
	*right = ptr & 0xFFFFFFFF;
}
