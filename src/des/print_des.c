/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_des.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:52:46 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:08:16 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			print_des(t_parser *ps, t_des *s, int mode)
{
	size_t		i;
	t_output	*output;

	i = 0;
	output = ps->output;
	while (output)
	{
		while (output->fd != -1 && i < s->len_results)
		{
			if (s->opt_a && mode == 1)
			{
				option_a_update_enc(&s->base64, s->results[i++],
					s->len_print);
				write(output->fd, s->base64.data,
					s->base64.tmp_trans_data_len);
			}
			else if ((i + 1) == s->len_results)
				write(output->fd, &s->results[i++], s->len_print);
			else
				write(output->fd, &s->results[i++], 8);
		}
		output = output->next;
	}
}

void			print_salt(t_parser *ps)
{
	t_output	*output;

	output = ps->output;
	while (output)
	{
		if (output->fd != -1)
		{
			write(output->fd, "Salted__", 8);
			write(output->fd, &ps->salt, 8);
		}
		output = output->next;
	}
}

void			print_des_other(
					t_parser *ps, uint8_t *data, size_t len)
{
	t_output	*output;

	output = ps->output;
	while (output)
	{
		if (output->fd != -1)
		{
			write(output->fd, data, len);
			write(output->fd, "\n", 1);
		}
		output = output->next;
	}
}
