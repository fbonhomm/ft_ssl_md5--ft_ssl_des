/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:45 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
# define DES_H

# include <stdint.h>
# include <strings.h>
# include <base64.h>

# define FIRST_BIT_8    0x80
# define FIRST_BIT_28   0x8000000
# define FIRST_BIT_32   0x80000000
# define FIRST_BIT_64   0x8000000000000000

# define BUF_SIZE_DES	4096

typedef struct			s_des
{
	uint64_t			key;
	uint64_t			vector;
	uint64_t			buf;
	uint64_t			buf_tmp;
	uint64_t			result;
	uint64_t			subkey[3];
	uint8_t				remain[8];
	uint8_t				bufs[BUF_SIZE_DES];
	uint64_t			results[BUF_SIZE_DES / 8];
	size_t				len;
	size_t				len_remain;
	size_t				len_results;
	size_t				len_print;
	int					fd;
	short				opt_a;
	t_base64			base64;
}						t_des;

typedef struct			s_des_data
{
	uint64_t			trans;
	uint64_t			new_key[16];
	uint32_t			sbox;
	uint32_t			trans2;
	uint32_t			left;
	uint32_t			right;
}						t_des_data;

void					initial_permutation(uint64_t ptr, uint64_t *trans);
void					slice_data(
		uint64_t ptr, uint32_t *left, uint32_t *right);
void					function_extension(uint32_t right, uint64_t *ext);
void					or_exclusif(uint64_t key, uint64_t *ext);
void					apply_sbox(uint64_t ext, uint32_t *sbox);
void					second_permutation(uint32_t sbox, uint32_t *trans2);
void					or_exclusif_2(uint32_t p1, uint32_t *trans2);
void					aggregate_data(uint32_t p1, uint32_t p2, uint64_t *ptr);
void					final_permutation(uint64_t result, uint64_t *final);
void					reverse_64(uint64_t *final);
void					padding(uint64_t *final, size_t len);
void					reverse(uint64_t *final);
void					final_padding(uint64_t *final);
void					check_padding(uint64_t final, size_t *len);
void					gen_keys(uint64_t key, uint64_t *new_key);
void					key_64_to_56(
		uint64_t key, uint32_t *left, uint32_t *right);
void					key_bit_rotate(
		uint32_t left, uint32_t right, uint32_t *arr_left, uint32_t *arr_right);
void					aggregate_key(
		uint64_t *new, uint32_t *arr_left, uint32_t *arr_right);
void					permutation_pc2(uint64_t *arr);

#endif
