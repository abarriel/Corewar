#	Output's Name
NAME = libft.a

#	GCC flags
CFLAGS = -Werror
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)

# Includes directories
INC_PATH = includes/
INCLUDES_FILES=  includes/ft_printf.h includes/get_next_line.h includes/libft.h

INCLUDES += $(addprefix -iquote , $(INC_PATH))

# Sources Objects directories
SRCS =  get_next_line.c \
binary/bin_to_dec.c \
binary/ft_count_bits.c\
binary/cmp_4_oct.c \
binary/char_to_int.c \
binary/char_to_ui.c \
binary/swap_bits.c\
\
check/ft_isalnum.c \
check/ft_isalpha.c \
check/ft_isascii.c \
check/ft_isdigit.c \
check/ft_islower.c \
check/ft_isprint.c \
check/ft_isupper.c \
check/str_digit.c \
\
else/ft_exit.c \
else/ft_tolower.c \
else/ft_toupper.c \
\
fprintf/ft_printf.c \
fprintf/setup.c \
\
fprintf/conv/conv_base.c \
fprintf/conv/conv_c.c \
fprintf/conv/conv_d.c \
fprintf/conv/handles_conv.c \
fprintf/conv/mod_conv.c \
\
fprintf/get/get_flags.c \
fprintf/get/get_string_c.c \
fprintf/get/get_string_d.c \
fprintf/get/get_string_s.c \
\
fprintf/print/print_c.c \
fprintf/print/print_d.c \
\
fprintf/tools/color_fun.c \
fprintf/tools/ft_strsetc.c \
fprintf/tools/ft_wlen.c \
fprintf/tools/print_w.c \
fprintf/tools/tools.c \
\
maths/ft_atoi.c \
maths/ft_hsqrt.c \
maths/ft_itoa.c \
maths/ft_itoa_base.c \
maths/ft_max.c \
maths/ft_min.c \
maths/ft_pow.c \
maths/ft_pow_base.c \
maths/ft_recursive_factorial.c \
maths/ft_sqrt.c \
maths/ft_swap.c \
\
string/chr/ft_strcchr.c  \
string/chr/ft_strchr.c \
string/chr/ft_strlenchr.c \
string/chr/ft_strnstr.c \
string/chr/ft_strrchr.c \
string/chr/ft_strstr.c \
\
string/cmp/ft_strcmp.c \
string/cmp/ft_strequ.c \
string/cmp/ft_strncmp.c \
string/cmp/ft_strnequ.c \
string/cmp/ft_strrcmp.c \
string/cmp/ft_strrncmp.c \
\
string/cpy/ft_strccpy.c \
string/cpy/ft_strcpy.c \
string/cpy/ft_strncpy.c \
string/cpy/ft_strrcpy.c \
 \
string/free/free_tab.c \
string/free/ft_memdel.c \
string/free/ft_strclr.c \
string/free/ft_strdel.c \
\
string/len/ft_strclen.c \
string/len/ft_strlen.c \
string/len/ft_strnlen.c \
string/len/ft_wcharlen.c \
string/len/ft_wstrlen.c \
\
string/malloc/ft_memalloc.c \
string/malloc/ft_strdup.c \
string/malloc/ft_strjoin.c \
string/malloc/ft_strndup.c \
string/malloc/ft_strnew.c \
string/malloc/ft_strsplit.c \
string/malloc/ft_strsub.c \
string/malloc/ft_strtrim.c \
\
string/mem/ft_memccpy.c \
string/mem/ft_memchr.c \
string/mem/ft_memcmp.c \
string/mem/ft_memcpy.c \
string/mem/ft_memmove.c \
string/mem/ft_memset.c \
\
string/string/ft_bzero.c \
string/string/ft_strcat.c \
string/string/ft_striter.c \
string/string/ft_striteri.c \
string/string/ft_strlcat.c \
string/string/ft_strmap.c \
string/string/ft_strmapi.c \
string/string/ft_strncat.c \
\
write/ft_putchar.c \
write/ft_putchar_fd.c \
write/ft_putendl.c \
write/ft_putendl_fd.c \
write/ft_putnbr.c \
write/ft_putnbr_fd.c \
write/ft_putstr.c \
write/ft_putstr_fd.c \
write/ft_putwchar.c \
write/ft_putwstr.c \
write/print_memory.c \

OBJS = $(SRCS:.c=.o)

all: makefile $(INCLUDES_FILES) $(NAME)

header:
	@echo "\033[1;36m[${NAME}]\033[1;32m Compile && Archive\033[0m"

$(NAME): $(OBJS)
	@printf "\r\e\033[0m\e[K\033[1;31m $@ \033[1;32m - Finished\033[0m\n"
	@ar rc $(NAME) $(OBJS)
%.o: %.c
	@printf "\r\033[1;32m. Compiling .\e\033[0m\e[K \033[1;31m$<"
	@gcc $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	
	@$(RM) $(OBJS)

fclean: clean

	@$(RM) $(NAME)

re: fclean all
