/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pass_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:09:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/06 14:35:26 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static void		search_salt(uint64_t *salt, int fd)
{
	read(fd, salt, 8);
	read(fd, salt, 8);
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

void			option_pass_dec(t_parser *ps, int fd)
{
	char		*rd_passwd;
	uint8_t		*passwd;
	uint64_t	salt;
	t_option	*opt;

	salt = 0;
	passwd = malloc(sizeof(uint8_t) * 1024);
	if ((opt = search_option(ps->opt_cipher, "-p")))
		ft_strcpy((char*)passwd, opt->content);
	else
	{
		rd_passwd = getpass("enter decryption password:");
		passwd = (uint8_t*)ft_strdup(rd_passwd);
	}
	search_salt(&salt, fd);
	hashing(ps, passwd, salt);
}
