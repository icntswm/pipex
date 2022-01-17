
.PHONY: all clean fclean re

SRCS	=	pipex.c			\
			pipex_utils.c

LIBFT	=	libft

OBJS	=	${SRCS:.c=.o}


NAME	=	pipex
P_HEAD	=	pipex.h

LB_HEAD	=	/libft/libft.h
LB_LBFT	=	libft/libft.a

RM		=	rm -f
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:		${P_HEAD} ${LB_HEAD}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			make -C ${LIBFT}
			${CC} ${OBJS} ${LB_LBFT} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBFT}

re:			fclean all
