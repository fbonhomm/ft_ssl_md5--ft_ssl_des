/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_digest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:02:07 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/24 12:18:48 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void			print_digest(unsigned char *buf, size_t len)
{
	buf[len] = '\n';
	buf[len + 1] = '0';
	write(STDOUT_FILENO, buf, len + 1);
}

void				readfile_digest(t_parser *ps)
{
	size_t			len;
	unsigned char	buf[1025];
	t_pointer_funct	*pf;
	t_input			*input;

	pf = ps->pf;
	input = ps->input;
	while (input)
	{
		if (input->fd != -1)
		{
			pf->init(pf->ctx);
			while ((len = read(input->fd, buf, 1024)) > 0)
			{
				pf->update(pf->ctx, buf, len);
				if (input->stdin && search_option(ps->opt_digest, "-p"))
				{
					print_digest(buf, len);
					break ;
				}
			}
			pf->final(pf->ctx, input->output);
		}
		input = input->next;
	}
}
