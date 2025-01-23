CC = gcc
AR = ar rc
SRC = functions1.c functions2.c functions3.c functions4.c functions5.c functions6.c \
    functions7.c functions8.c functions9.c functions10.c functions11.c functions12.c
OBJ = ${SRC:.c=.o}
NAME = library.a
MAIN = push_swap.c
MAIN_O = push_swap
CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME} exec

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
exec: ${MAIN} header.h
	gcc $(MAIN) -L. -lrary -o $(MAIN_O)
%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

#bonus: ${OBJB}
#	${AR} ${NAME} ${OBJB}

clean:
	rm -f ${OBJ} $(MAIN_O)
fclean : clean 
	rm -f ${NAME}
	
re: fclean all