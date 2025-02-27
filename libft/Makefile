CC = cc
NAME = libft.a
CFLAGS		= -Wall -Wextra -Werror

files 	   = ft_strlen \
			ft_memmove \
			ft_memcpy \
			ft_memchr \
			ft_strlcpy \
			ft_strlcat \
			ft_memset \
			ft_memcmp \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii  \
			ft_isprint \
			ft_bzero \
			ft_strnstr \
			ft_strncmp \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strtrim \
			ft_itoa \
			ft_strjoin \
			ft_split \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_strcmp \
			ft_atol \
			get_next_line\
			get_next_line_utils\



CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES) -I./
	ar -rcs $(NAME) $(OFILES)
	
clean:
	rm -f $(NAME) $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
