
NAME = ft_ssl

CC = gcc

FLAG = -Wextra

LIB = -L libft/ -lft

SRC_PATH = src/
OBJ_PATH = obj/

SRC_SUFF = main \
						initialize \
						free \
						usage \
						parser \
						error \
						file_descriptor \
						readfile_digest \
						readstr_digest \
						display_digest \
						display_error \
						tools \
						verify_argument \
						select_cmd \
						check_file \
						is_hex \
						\
						pointer_function/set_function \
						pointer_function/set_md5 \
						pointer_function/set_sha256 \
						pointer_function/set_sha224 \
						pointer_function/set_sha1 \
						\
						md5/md5_init \
						md5/md5_update \
						md5/md5_transform \
						md5/md5_final \
						md5/utils \
						md5/utils2 \
						\
						sha256/sha256_init \
						sha256/sha256_update \
						sha256/sha256_transform \
						sha256/sha256_final \
						\
						sha224/sha224_init \
						sha224/sha224_update \
						sha224/sha224_transform \
						sha224/sha224_final \
						\
						sha1/sha1_init \
						sha1/sha1_update \
						sha1/sha1_transform \
						sha1/sha1_final \
						\
						base64/readfile_base64 \
						base64/base64_init \
						base64/base64_add_remain \
						base64/remove_newline \
						base64/encode/base64_update_enc \
						base64/encode/base64_transform_enc \
						base64/encode/base64_final_enc \
						base64/decode/base64_update_dec \
						base64/decode/base64_transform_dec \
						base64/decode/base64_final_dec \
						\
						des/decrypt_des \
						des/encrypt_des \
						des/final_padding \
						des/final_permutation \
						des/function_extension \
						des/initiale_permutation \
						des/or_exclusif \
						des/or_exclusif_2 \
						des/padding \
						des/readfile_des \
						des/reverse \
						des/second_permutation \
						des/slice_data \
						des/aggregate_data \
						des/apply_sbox \
						des/check_padding \
						des/select_des \
						des/convert_key_des \
						des/option_a \
						des/option_pass \
						des/option_pass_dec \
						des/print_des \
						\
						des/des_ecb/des_ecb_decrypt \
						des/des_ecb/des_ecb_encrypt \
						\
						des/des_cbc/des_cbc_decrypt \
						des/des_cbc/des_cbc_encrypt \
						des/des_pcbc/des_pcbc_decrypt \
						des/des_pcbc/des_pcbc_encrypt \
						\
						des/des3/des3_ecb_decrypt \
						des/des3/des3_ecb_encrypt \
						des/des3/des3_cbc_decrypt \
						des/des3/des3_cbc_encrypt \
						des/des3/des3_pcbc_decrypt \
						des/des3/des3_pcbc_encrypt \
						\
						des/des_genkey/aggregate_key \
						des/des_genkey/gen_keys \
						des/des_genkey/key_64_to_56 \
						des/des_genkey/key_bit_rotate \
						des/des_genkey/permutation_pc2 \

OBJ_FOLDER = ./obj/ \
			./obj/md5 \
			./obj/sha256 \
			./obj/sha224 \
			./obj/sha1 \
			./obj/base64 \
			./obj/base64/encode \
			./obj/base64/decode \
			./obj/pointer_function \
			./obj/des/des_genkey \
			./obj/des/des_ecb \
			./obj/des/des_cbc \
			./obj/des/des_pcbc \
			./obj/des/des3 \

INC_SUFF = inc/ \
						inc/md5/ \
						inc/sha256/ \
						inc/sha224/ \
						inc/sha1/ \
						inc/base64/ \
						inc/des/ \
						libft/ \

SRC_NAME = $(addsuffix .c, $(SRC_SUFF))
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_SUFF))
INC = $(addprefix -I, $(INC_SUFF))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAG) $(OBJ) $(INC) $(LIB) -o $(NAME) -lm
	@echo "Create: $(NAME)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C ./libft/
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
