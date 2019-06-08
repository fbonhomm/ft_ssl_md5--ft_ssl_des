/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:17:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:25:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_dec_to_hex(unsigned int n, char *result)
{
    int i;
    int j;
    size_t temp;
    char hexdec[1024];

    j = 0;
    i = 0;
    while (n != 0)
    {
        temp = 0;
        temp = n % 16;
        if (temp < 10)
            hexdec[j++] = temp + 48;
        else
            hexdec[j++] = temp + 55;
        n = n / 16;
    }
    j -= 1;
    if (j < 7)
    {
        while ((j + i) < 7)
            result[i++] = '0';
    }
    while (j >= 0)
    {
        if (hexdec[j] >= 65 && hexdec[j] <= 90)
            hexdec[j] = hexdec[j] + 32;
        result[i++] = hexdec[j--];
    }
    return;
}
