SRC			= \
ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen \
ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat \
ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd \
ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri \
ft_printf ft_print_p ft_print_s ft_print_x ft_put_u ft_putchar ft_putnbr\
ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRCS		= $(addsuffix .c, ${SRC})

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

