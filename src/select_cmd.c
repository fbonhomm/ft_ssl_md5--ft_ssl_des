/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:04:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 10:50:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

char			**select_cmd(void)
{
	size_t		len;
	char		buf[1024];

	write(1, "FT_SSL> ", 8);
	while ((len = read(0, buf, 1024)) == 1)
		write(1, "FT_SSL> ", 8);
	if (len > 0 && buf[len - 1] == '\n')
		buf[len - 1] = 0;
	else
	{
		buf[len] = 0;
		write(1, "\n", 1);
	}
	return (ft_split_mult(4, buf, '\n', '\t', ' '));
}
