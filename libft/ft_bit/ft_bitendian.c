/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitendian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:29:44 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:31:04 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bitendian(void)
{
	return (BYTE_ORDER == LITTLE_ENDIAN) ? LITTLE_ENDIAN : BIG_ENDIAN;
}
