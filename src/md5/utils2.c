/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:00:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 17:42:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ssl.h>

void            MD5_DBL_INT_ADD(unsigned int *a, unsigned int *b, unsigned int c)
{
    if (*a > 0xffffffff - c)
    {
        *b += 1;
    }
    *a += c;
}

unsigned int    MD5_ROTLEFT(unsigned int a, unsigned int b)
{
    return ((a << b) | (a >> (32 - b)));
}
