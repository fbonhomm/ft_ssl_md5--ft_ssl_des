/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_des.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:00:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:22:13 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		init_des(t_parser *ps, t_des *s, int mode, int des_mode)
{
	t_option	*opt;

	s->opt_a = FALSE;
	if (!search_option(ps->opt_cipher, "-k") && mode == 1 &&
		(des_mode == ECB_MODE || des_mode == CBC_MODE || des_mode == PCBC_MODE))
	{
		option_pass(ps);
		print_salt(ps);
	}
	opt = search_option(ps->opt_cipher, "-k");
	if (opt)
		convert_key_des(s, opt->content, des_mode);
	opt = search_option(ps->opt_cipher, "-v");
	if (opt)
		convert_des(opt->content, &s->vector);
	if (search_option(ps->opt_cipher, "-a"))
		s->opt_a = TRUE;
}

static void		init_var(t_des *s)
{
	s->len_print = 8;
	s->len_results = 0;
	s->buf_tmp = 0;
	s->len_remain = 0;
	if (s->opt_a)
		base64_init(&s->base64);
}

static void		final_des(t_parser *ps, t_des *s, int mode, int des_mode)
{
	if (mode == 1)
	{
		print_des(ps, s, mode);
		add_padding(s, des_mode);
		print_des(ps, s, mode);
		if (s->opt_a)
		{
			option_a_final_enc(&s->base64);
			print_des_other(ps, s->base64.data, s->base64.tmp_trans_data_len);
		}
	}
	else if (mode == 2)
	{
		if (s->len_results > 0)
			check_padding(s->results[s->len_results - 1], &s->len_print);
		print_des(ps, s, mode);
		if (s->opt_a)
		{
			option_a_final_dec(s, &s->base64);
			select_des(s, mode, des_mode);
			if (s->len_results > 0)
				check_padding(s->results[s->len_results - 1], &s->len_print);
			print_des(ps, s, mode);
		}
	}
}

static void		check_pass(t_parser *ps, t_des *s, int mode, int des_mode)
{
	if (!search_option(ps->opt_cipher, "-k") && mode == 2 &&
		(des_mode == ECB_MODE || des_mode == CBC_MODE
			|| des_mode == PCBC_MODE))
	{
		option_pass_dec(ps, s->fd);
		init_des(ps, s, mode, des_mode);
	}
}

void			readfile_des(t_parser *ps, int mode, int des_mode)
{
	t_des		s;
	t_input		*input;

	input = ps->input;
	init_des(ps, &s, mode, des_mode);
	while (input)
	{
		if (input->fd != -1)
		{
			init_var(&s);
			s.fd = input->fd;
			check_pass(ps, &s, mode, des_mode);
			while ((s.len = read(input->fd, s.bufs, BUF_SIZE_DES)) > 0)
			{
				if (s.opt_a && mode == 2)
					option_a_update_dec(&s, &s.base64, s.bufs, s.len);
				if (s.len_results)
					print_des(ps, &s, mode);
				select_des(&s, mode, des_mode);
			}
			final_des(ps, &s, mode, des_mode);
		}
		input = input->next;
	}
}
