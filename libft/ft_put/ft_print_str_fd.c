/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 10:16:34 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/14 10:17:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_str_fd(int nb, int fd, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, fd);
	while (i++ < nb)
		ft_putstr_fd(va_arg(ap, char*), fd);
	va_end(ap);
}
