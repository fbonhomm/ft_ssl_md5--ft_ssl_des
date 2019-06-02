# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 17:46:33 by fbonhomm          #+#    #+#              #
#    Updated: 2016/05/25 16:57:23 by fbonhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -g -Wall -Wextra -Werror

INC_PATH = ./

SRC_PATH = ./

SRC_NAME = ft_atoi \
		ft_bzero \
		ft_itoa \
		ft_numlen \
		ft_numtoa \
		ft_numtoa_unsign \
		ft_parameter \
		ft_perror \
		ft_realloc \
		ft_sleep \
		ft_split \
		ft_split_mult \
		ft_split_mult_other \
		ft_tab_to_str \
		ft_tolower \
		ft_toupper \
		ft_wcharlen  \
		get_next_line \
		ft_realloc_array \
		ft_ascii_to_hex \
		ft_dec_to_hex \
		\
		ft_is/ft_isalnum \
		ft_is/ft_isalpha \
		ft_is/ft_isascii \
		ft_is/ft_isdigit \
		ft_is/ft_isprint \
		ft_is/ft_strisdigit \
		ft_is/ft_strisdigit_mult \
		\
		ft_mem/ft_memalloc \
		ft_mem/ft_memccpy \
		ft_mem/ft_memchr \
		ft_mem/ft_memcmp \
		ft_mem/ft_memcpy \
		ft_mem/ft_memdel \
		ft_mem/ft_memmove \
		ft_mem/ft_memset \
		\
		ft_put/ft_print_nbr \
		ft_put/ft_print_str \
		ft_put/ft_print_str_fd \
		ft_put/ft_put_array \
		ft_put/ft_putchar \
		ft_put/ft_putchar_fd \
		ft_put/ft_putendl \
		ft_put/ft_putendl_fd \
		ft_put/ft_putnbr \
		ft_put/ft_putnbr_fd \
		ft_put/ft_putstr \
		ft_put/ft_putstr_fd \
		ft_put/ft_putwchar \
		\
		ft_str/ft_strcat \
		ft_str/ft_strchr \
		ft_str/ft_strclr \
		ft_str/ft_strcmp \
		ft_str/ft_strcpy \
		ft_str/ft_strdel_array \
		ft_str/ft_strdel \
		ft_str/ft_strdup_array \
		ft_str/ft_strdup \
		ft_str/ft_strepur \
		ft_str/ft_strequ \
		ft_str/ft_striter \
		ft_str/ft_striteri \
		ft_str/ft_strjoin \
		ft_str/ft_strjoin_mult \
		ft_str/ft_strlcat \
		ft_str/ft_strlen_array \
		ft_str/ft_strlen \
		ft_str/ft_strmap \
		ft_str/ft_strmapi \
		ft_str/ft_strncat \
		ft_str/ft_strncmp \
		ft_str/ft_strncpy \
		ft_str/ft_strndup \
		ft_str/ft_strnequ \
		ft_str/ft_strnew \
		ft_str/ft_strnstr \
		ft_str/ft_strrchr \
		ft_str/ft_strsort \
		ft_str/ft_strsort_nocase \
		ft_str/ft_strsplit \
		ft_str/ft_strstr \
		ft_str/ft_strsub \
		ft_str/ft_strtrim \
		ft_str/ft_strrev \
		ft_str/ft_strndup_end \
		ft_str/ft_strnew_array \
		ft_str/ft_strlen_del \
		ft_str/ft_strpush \
		\
		ft_arr/ft_arrfind \
		ft_arr/ft_arrpush \
		\
		ft_nb/ft_nbpush \
		\
		ft_bit/ft_bitempty \
		ft_bit/ft_bit_to_str \
		ft_bit/ft_bitendian \
		ft_bit/ft_bit_get_idx \
		ft_bit/ft_bit_set_one \
		ft_bit/ft_bit_set_zero \
		ft_bit/ft_bitfull \
		ft_bit/ft_bit_change_endian \
		\
		# ft_lst/ft_lstpush

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_EXT:.c=.o)

OBJ_FOLDER = ./obj/ \
			./obj/ft_is \
			./obj/ft_str \
			./obj/ft_mem \
			./obj/ft_put \
			./obj/ft_arr \
			./obj/ft_nb \
			./obj/ft_bit

SRC_EXT = $(addsuffix .c, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_EXT))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Create: $(NAME)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_FOLDER)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
