NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= -I .
ARFLAGS			= crs

BUILD_DIR		= build

SRC				=  $(addprefix memory/, ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c) \
					$(addprefix output/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c) \
					$(addprefix type/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c) \
					$(addprefix string/, ft_atoi.c ft_itoa.c ft_free_strs.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtol.c ft_strtrim.c) \
					$(addprefix list/, ft_lstadd_back.c ft_lstadd_front.c ft_lstbefore.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c) \
					$(addprefix ft_printf/, ft_printf.c nbr_utils.c conversion_router.c parse_spec.c print_integer.c print_string.c) \
					$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
					$(addprefix file/, file_to_line_array.c) \
					$(addprefix integer/, ft_abs.c ft_max.c ft_min.c ft_chmax.c ft_chmin.c ft_swap.c)

OBJ				= $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

GTESTDIR		=	gtest
GTEST			=	$(GTESTDIR)/gtest $(GTESTDIR)/googletest-release-1.11.0
TESTDIR			=	test
TEST_COMPILE	=	clang++ -std=c++11 \
					$(TESTDIR)/gtest.cpp $(GTESTDIR)/googletest-release-1.11.0/googletest/src/gtest_main.cc \
					$(GTESTDIR)/gtest/gtest-all.cc -I $(GTESTDIR) -I . -L . -l ft -lpthread -o tester

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

all: $(NAME)

$(NAME): $(SRC)
	@make _main

_main:
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(WHITE)compling...$(RESET)"
	@make _build

_build: $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@echo "\n$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)compiled ✔$(RESET)"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)─$(RESET)"

clean:
	@$(RM) $(OBJ)
	@echo "$(BLUE)[libft]\t\tobject files$(RESET)\t$(GREEN)deleted ✔$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[libft]\t\t$(NAME)$(RESET)\t\t$(GREEN)deleted ✔$(RESET)"

re: fclean all

norm:
	norminette ft_printf get_next_line list memory string type file output integer libft.h

include unit_test.mk

.PHONY: all clean fclean re norm test title
