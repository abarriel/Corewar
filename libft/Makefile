#	Output's Name
NAME = libft.a

#	GCC flags
CFLAGS = -Werror
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)

# Includes directories
INC_PATH = includes/
INCLUDES_FILES= $(shell find . | grep "\.h")
INCLUDES += $(addprefix -iquote , $(INC_PATH))

# Sources Objects directories
SRCS = $(shell find . | grep "\.c")
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
