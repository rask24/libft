NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= -I $(INC_DIR)
ARFLAGS			= crs

BUILD_DIR		= build
INC_DIR			= include

SRC				=  $(addprefix memory/, ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_xmalloc.c) \
					$(addprefix output/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c) \
					$(addprefix type/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c) \
					$(addprefix string/, ft_atoi.c ft_itoa.c ft_free_strs.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtol.c ft_strtrim.c) \
					$(addprefix list/, ft_lstadd_back.c ft_lstadd_front.c ft_lstbefore.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c) \
					$(addprefix ft_printf/, ft_printf.c ft_vprintf.c ft_dprintf.c ft_vdprintf.c print_integer/putnbr_base.c print_integer/calc_digits_base.c print_by_format.c configure_format_info.c print_integer/print_integer.c print_integer/configure_integer_info.c print_string/print_padding.c print_string/print_char.c print_string/print_str.c) \
					$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
					$(addprefix ft_file/, file_to_lines.c) \
					$(addprefix integer/, ft_abs.c ft_max.c ft_min.c ft_chmax.c ft_chmin.c ft_swap.c)
OBJ				= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

# colors
RESET			= \033[0m
ORANGE			= \033[0;33m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
	@make _main

.PHONY: _main
_main:
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(WHITE)compling...$(RESET)"
	@make _build

.PHONY: _build
_build: $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@echo "\n$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)compiled ✔$(RESET)"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

.PHONY: clean
clean:
	@$(RM) $(OBJ)
	@echo "$(BLUE)[libft]\t\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)deleted ✔$(RESET)"

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	norminette ft_printf get_next_line list memory string type file output integer libft.h

include unit_test.mk
