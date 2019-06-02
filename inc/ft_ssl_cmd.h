/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:37:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:43:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_CMD_H
# define FT_SSL_CMD_H

const char **g_cmd_digest = (const char *[]) {
	"md5", "sha256", "sha224", NULL
};
const char **g_cmd_cipher = (const char *[]) {
	"base64", "des", "des-ecb", "des-cbc", "des-pcbc",
	"des3-ecb", "des3-cbc", "des3-pcbc", NULL
};

#endif
