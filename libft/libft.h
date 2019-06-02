/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:46:16 by fbonhomm          #+#    #+#             */
/*   Updated: 2018/11/23 22:06:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <ctype.h>
# include <errno.h>
# include <time.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include <inttypes.h>

# define SIZE		10
# define LINE		0
# define BUFF		1
# define RETURN		2

/*
* return la taille d'un tableau static
*/
# define COUNT_OF(ptr)	(sizeof(ptr) / sizeof((ptr)[0]))	

typedef struct	s_env
{
	int			rd;
	int			j;
	int			i;
	int			ind;
	int			ret;
}				t_env;

/*
** fonction convertion
*/
int				ft_atoi(char *str);
char			*ft_itoa(int n, int base);
void			ft_dec_to_hex(unsigned int n, char *result);
/*
** fonction remplissage
*/
void			ft_bzero(void *s, size_t n);
/*
** fonction verification
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strisdigit(char *str);
int				ft_strisdigit_mult(size_t nb, ...);
/*
** fonction notypee
*/
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
/*
** fonction longueur d'int
*/
int				ft_numlen(int n);
/*
** fonction autre
*/
int				ft_parameter(int nb, char const *str, ...);
void			ft_perror(char *s);
char			**ft_realloc_array(char **tab, size_t size);
void			*ft_realloc(void *str, size_t size);
char			*ft_tab_to_str(char **tabl, char separator);
/*
** fonction put
*/
void			ft_print_nbr(int nb, ...);
void			ft_print_str(int nb, ...);
void			ft_print_str_fd(int nb, int fd, ...);
void			ft_put_array(char **str, char *c);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_color(char *color, char *tb, char *text, char *ts);
void			ft_putstr_fd(char const *s, int fd);
/*
** fonction string
*/
size_t			ft_strlen(const char *s);
size_t			ft_strlen_array(char **str);
size_t			ft_strlen_del(const char *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t size);
char			**ft_strdup_array(char **str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strdel_array(char ***str);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_mult(int nb, ...);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			**ft_split(char const *s, char c, char d);
char			**ft_split_mult(int nb, char const *str, ...);
int				ft_search_true(char const *s, char *c, int i);
int				ft_search_false(char const *s, char *c, int i);
char			*ft_strepur(int nb, char *str, ...);
void			ft_strrev(char **s);
char			*ft_strndup_end(const char *s1, size_t size);
char			**ft_strnew_array(size_t size);
char			*ft_strpush(char *ptr, char *elem);
/*
** fonction trie
*/
int				ft_strsort(char *s1, char *s2);
int				ft_strsort_nocase(char *s1, char *s2);
/*
** fonction temps
*/
int				ft_sleep(long miliseconds);
/*
** fonction caractere
*/
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_ascii_to_hex(int ascii);
/*
** fonction get_next_line
*/
int				get_next_line(int const fd, char **line);
/*
** fonction array
*/
int				ft_arrfind(const char **arr, const char *find);
char			**ft_arrpush(char **ptr, void *elem);
/*
** fonction number
*/
int				*ft_nbpush(int *ptr, int elem);
/*
** fonction chains list
*/
void			ft_lstpush(void *lst, void *elem);
/*
** fonction bitwise
*/
void			ft_bitempty(uint8_t *ptr);
void			ft_bit_to_str(uint8_t *ptr, char *str);
int				ft_bitendian();
void			ft_bit_get_idx(uint8_t *ptr,
						unsigned int idx, unsigned int *result);
void			ft_bit_set_one(uint8_t *ptr, unsigned int idx);
void			ft_bit_set_zero(uint8_t *ptr, unsigned int idx);
void			ft_bitfull(uint8_t *ptr);
void			ft_bit_change_endian(void *ptr);

#endif
