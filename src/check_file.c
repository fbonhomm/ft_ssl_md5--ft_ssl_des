/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:17:52 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/26 10:51:51 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int				check_file(char *file)
{
	struct stat	buf;

	if (stat(file, &buf) >= 0)
	{
		if (S_ISREG(buf.st_mode))
			return (1);
	}
	errno = ENOENT;
	return (0);
}
