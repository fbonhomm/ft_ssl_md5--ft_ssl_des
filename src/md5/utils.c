/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:59:58 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 17:42:31 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ssl.h>

unsigned int    F_MD5(unsigned int x, unsigned int y, unsigned int z)
{
    return (((x) & (y)) | (~(x) & (z)));
}

unsigned int    G_MD5(unsigned int x, unsigned int y, unsigned int z)
{
    return (((x) & (z)) | ((y) & ~(z)));
}

unsigned int    H_MD5(unsigned int x, unsigned int y, unsigned int z)
{
    return ((x) ^ (y) ^ (z));
}

unsigned int    I_MD5(unsigned int x, unsigned int y, unsigned int z)
{
    return ((y) ^ ((x) | ~(z)));
}
