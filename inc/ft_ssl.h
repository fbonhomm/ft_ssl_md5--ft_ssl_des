/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:31:05 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:05 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include <libft.h>
# include <errno.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "md5.h"
# include "sha256.h"
# include "sha224.h"
# include "sha1.h"
# include "base64.h"
# include "des.h"

# define FALSE			0
# define TRUE			1

# define ECB_MODE		1
# define CBC_MODE		2
# define PCBC_MODE		3
# define ECB3_MODE		4
# define CBC3_MODE		5
# define PCBC3_MODE		6

typedef struct			s_pointer_funct
{
	void				(*init)();
	void				(*update)();
	void				(*final)();
	void				*ctx;
}						t_pointer_funct;

typedef struct			s_option
{
	char				*str;
	char				*content;
	size_t				used;
	size_t				after;
	struct s_option		*next;
}						t_option;

typedef struct			s_input
{
	unsigned short		stdin;
	char				*name;
	int					fd;
	char				output[65];
	struct s_input		*next;
}						t_input;

typedef struct			s_output
{
	unsigned short		stdout;
	char				*name;
	int					fd;
	size_t				len_output;
	char				*output_cipher;
	char				output[65];
	struct s_output		*next;
}						t_output;

typedef struct			s_parser
{
	char				*cmd;
	char				*str;
	size_t				read_size;
	size_t				des_mode;
	char				*type;
	char				**errors;
	uint64_t			salt;
	t_input				*input;
	t_output			*output;
	t_option			*opt_digest;
	t_option			*opt_cipher;
	t_pointer_funct		*pf;
}						t_parser;

t_option				*search_option(t_option *o, char *opt);
int						parser(t_parser *ps, char **tab);
int						verify_argument(t_parser *ps);
void					initialize(t_parser *ps);
void					free_ssl(t_parser *ps);
void					error(t_parser *ps, char *obj, char *str);
void					display_error(t_parser *ps);
void					display_digest(t_parser *ps);
void					readfile_digest(t_parser *ps);
void					readstr_digest(t_parser *ps);
void					usage();
void					add_begin_input(t_parser *ps, t_input *elem);
void					add_end_input(t_parser *ps, t_input *elem);
void					add_end_output(t_parser *ps, t_output *elem);
void					file_descriptor(t_parser *ps, char **cli, int i);
void					readfile_base64(t_parser *ps, int mode);
void					readfile_des(t_parser *ps, int mode, int des_mode);
void					select_des(t_des *s, int mode, int des_mode);
void					convert_key_des(t_des *s, char *str, int des_mode);
void					convert_des(char *str, uint64_t *key);
void					decrypt_des(t_des *s, uint64_t buf, uint64_t key);
void					encrypt_des(t_des *s, uint64_t buf, uint64_t key);
void					des_ecb_encrypt(t_des *s);
void					des_ecb_decrypt(t_des *s);
void					des_cbc_encrypt(t_des *s);
void					des_cbc_decrypt(t_des *s);
void					des_pcbc_encrypt(t_des *s);
void					des_pcbc_decrypt(t_des *s);
void					des3_ecb_encrypt(t_des *s);
void					des3_ecb_decrypt(t_des *s);
void					des3_cbc_encrypt(t_des *s);
void					des3_cbc_decrypt(t_des *s);
void					des3_pcbc_encrypt(t_des *s);
void					des3_pcbc_decrypt(t_des *s);
void					set_function(t_parser *ps);
void					set_base64(t_parser *ps);
void					set_md5(t_parser *ps);
void					set_sha224(t_parser *ps);
void					set_sha256(t_parser *ps);
void					set_sha1(t_parser *ps);
char					**select_cmd();
int						check_file(char *file);
void					add_padding(t_des *s, int des_mode);
void					base64_add_remain(t_base64 *s, uint8_t *dst);
void					option_a_update_enc(
							t_base64 *s, uint64_t nb, size_t len);
void					option_a_final_enc(t_base64 *s);
void					option_a_update_dec(
							t_des *d, t_base64 *s, uint8_t *buf, size_t len);
void					option_a_final_dec(t_des *d, t_base64 *s);
void					remove_newline(uint8_t *buf, size_t *len);
int						is_hex(char *str);
void					option_pass(t_parser *ps);
void					option_pass_dec(t_parser *ps, int fd);
void					print_des(t_parser *ps, t_des *s, int mode);
void					print_salt(t_parser *ps);
void					print_des_other(
							t_parser *ps, uint8_t *data, size_t len);

#endif
