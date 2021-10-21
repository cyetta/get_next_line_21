NAME = test

SRCN = main.c get_next_line.c get_next_line_utils.c
HDRN = get_next_line.h
BSRCN =

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

CFLAG = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAG} -o $@ ${OBJ}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@ -I ${INCPATH}

include ${wildcard ${DPDS}}

bonus:
	@make  SRCN="${SRCN} ${BSRCN}" all

clean:
	${RM} ${OBJ} ${BOBJ} ${DPDS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
