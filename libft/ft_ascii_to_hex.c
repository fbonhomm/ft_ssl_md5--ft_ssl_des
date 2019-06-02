/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:08:28 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:08:31 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "inc_ascii_to_hex.h"

char				*ft_ascii_to_hex(int ascii)
{
	return (char*)g_hexlst[ascii];
}
