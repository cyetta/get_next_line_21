NAME = test

SRCN = main.c get_next_line.c get_next_line_utils.c
HDRN = get_next_line.h
BSRCN = main.c get_next_line_bonus.c get_next_line_utils_bonus.c

SRCPATH = ./
INCPATH = ./

SRCS = ${addprefix ${SRCPATH}, ${SRCN}}
BSRCS = ${addprefix ${SRCPATH}, ${BSRCN}}
HDRS = ${addprefix ${INCPATH}, ${HDRN}}

OBJ = ${SRCS:.c=.o}
BOBJ = ${BSRCS:.c=.o}
DPDS = ${SRCS:.c=.d} ${BSRCS:.c=.d}

CC = gcc

RM	= rm -f

CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAG} -o $@ ${OBJ}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@ -I ${INCPATH}

include ${wildcard ${DPDS}}

debug:
	@make CFLAG="${CFLAG} -g3" all

bonus:
	@make SRCN="${BSRCN}" debug

clean:
	${RM} ${OBJ} ${BOBJ} ${DPDS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
