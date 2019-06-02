/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_base64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:00:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 13:51:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void			print_base64(
	t_parser *ps, uint8_t *data, size_t len, int eof)
{
	t_output		*output;

	output = ps->output;
	while (output)
	{
		if (output->fd)
		{
			write(output->fd, data, len);
			if (eof)
				write(output->fd, "\n", 1);
		}
		output = output->next;
	}
}

static void			final(t_parser *ps, t_base64 *s, int mode)
{
	if (mode == 2)
	{
		base64_final_dec(s);
		print_base64(ps, s->data, s->tmp_trans_data_len, 0);
	}
	else if (mode == 1)
	{
		base64_final_enc(s);
		print_base64(ps, s->data, s->tmp_trans_data_len, 1);
	}
}

void				readfile_base64(t_parser *ps, int mode)
{
	t_base64		s;
	t_input			*input;

	input = ps->input;
	while (input)
	{
		if (input->fd != -1)
		{
			base64_init(&s);
			while ((s.len = read(input->fd, s.buf, BUF_SIZE_BASE64)) > 0)
			{
				if (mode == 2)
				{
					remove_newline(s.buf, &s.len);
					base64_update_dec(&s);
				}
				else if (mode == 1)
					base64_update_enc(&s);
				print_base64(ps, s.data, s.tmp_trans_data_len, 0);
			}
			final(ps, &s, mode);
		}
		input = input->next;
	}
}
