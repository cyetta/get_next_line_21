NAME = test

SRCN = main.c get_next_line.c get_next_line_utils.c
HDRN = get_next_line.h
BSRCN =

SRCPATH = ./
INCPATH = ./

SRCS = ${addprefix ${SRCPATH}, ${SRCN}}
HDRS = ${addprefix ${INCPATH}, ${HDRN}}
BSRCS = ${addprefix ${SOURCE}, ${BSRCN}}

OBJ = ${SRCS:.c=.o}

BOBJ = ${BSRCS:.c=.o}

CC = gcc

RM	= rm -f

CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42

.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCPATH}

${NAME}:	${OBJ}
	${CC} ${CFLAG} -o $@ ${OBJ}


all:	${NAME}

bonus:
#	@make  SRCN="${SRCN} ${BSRCN}" all

clean:
	${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
