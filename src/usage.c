/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:40:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:42:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

const uint8_t g_msg[1000] = "\
Digest Usage: ft_ssl command [options] [file]\n\
Cipher Usage: ft_ssl command [options]\n\n\
Digest Command:\n\
\tmd5\n\
\tsha256\n\
\tsha224\n\n\
Cipher Command:\n\
\tdes (des-cbc)\n\
\tdes-ecb\n\
\tdes-cbc\n\
\tdes-pcbc\n\
\tdes3-ecb\n\
\tdes3-cbc\n\
\tdes3-pcbc\n\n\
Digest Options:\n\
\t-p, echo STDIN to STDOUT and append the checksum to STDOUT.\n\
\t-q, quiet mode.\n\
\t-r, reverse the format of the output.\n\
\t-s, print the sum of the given string.\n\n\
Cipher Options:\n\
\t-d, decrypt mode\n\
\t-e, encrypt mode (default)\n\
\t-i, input file for message\n\
\t-o, output file for message\n\
\t-k, key in hex is the next arguement.\n\
\t-v, initialization vector in hex is the next argument.\n";

void	usage(void)
{
	ft_putstr((const char*)g_msg);
}
