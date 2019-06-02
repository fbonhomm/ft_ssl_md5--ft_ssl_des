/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 23:28:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 23:28:05 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharlen(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x10FFFF)
		return (4);
	return (0);
}
