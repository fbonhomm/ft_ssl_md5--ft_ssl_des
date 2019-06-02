/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:09:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 15:59:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		create_salt(uint64_t *salt)
{
	int			fd;
	size_t		i;
	char		buf[2];
	char		result[16];

	i = 0;
	*salt = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, buf, 1))
		{
			buf[1] = 0;
			if (is_hex(buf))
				result[i++] = buf[0];
			if (i >= 16)
				break ;
		}
		result[i] = 0;
		convert_des(result, salt);
	}
}

static void		add_key(t_option *opt, uint8_t *hash)
{
	while (opt->next)
		opt = opt->next;
	opt->next = (t_option*)malloc(sizeof(t_option));
	opt->next->str = ft_strdup("-k");
	opt->next->used = 1;
	opt->next->next = NULL;
	opt->next->content = ft_strndup((const char*)hash, 16);
	opt->next->after = 1;
}

static void		add_vector(t_option *opt, uint8_t *hash)
{
	while (opt->next)
		opt = opt->next;
	opt->next = (t_option*)malloc(sizeof(t_option));
	opt->next->str = ft_strdup("-v");
	opt->next->used = 1;
	opt->next->next = NULL;
	opt->next->content = ft_strndup((const char*)hash, 16);
	opt->next->after = 1;
}

static void		hashing(t_parser *ps, uint8_t *passwd, uint64_t salt)
{
	t_md5		md5;
	size_t		len;
	uint8_t		hash[32];
	uint8_t		*concat;

	len = ft_strlen((const char*)passwd);
	concat = malloc(sizeof(uint8_t) * (len + 9));
	reverse(&salt);
	ft_memcpy(concat, passwd, len);
	ft_memcpy(concat + len, &salt, 8);
	md5_init(&md5);
	md5_update(&md5, concat, len + 8);
	md5_final(&md5, hash);
	add_key(ps->opt_cipher, hash);
	if (!search_option(ps->opt_cipher, "-v"))
		add_vector(ps->opt_cipher, hash + 16);
	ps->salt = salt;
	free(passwd);
	free(concat);
}

void			option_pass(t_parser *ps)
{
	char		*rd_passwd;
	char		*rd_cnf_passwd;
	uint8_t		*passwd;
	uint64_t	salt;
	t_option	*opt;

	passwd = malloc(sizeof(uint8_t) * 1024);
	if ((opt = search_option(ps->opt_cipher, "-p")))
		ft_strncpy((char*)passwd, opt->content, 1024);
	else
	{
		rd_passwd = getpass("enter encryption password:");
		rd_cnf_passwd = getpass("Verifying - enter encryption password:");
		if (ft_strcmp(rd_passwd, rd_cnf_passwd))
		{
			write(2, "Verify failure\n", 15);
			exit(-1);
		}
		ft_strncpy((char*)passwd, rd_passwd, 1024);
	}
	if ((opt = search_option(ps->opt_cipher, "-s")))
		convert_des(opt->content, &salt);
	else
		create_salt(&salt);
	hashing(ps, passwd, salt);
}
