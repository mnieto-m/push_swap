NAME = ./Push_swap

#flags#

G = gcc
GCFLAGS = -Werror -Wextra -Wall

#directorios#
SRC_DIR = src/
INCLUDE_DIR = include/
OBJ_DIR = objects/


INCLUDE = 
SRC = $(addprefix $(SRC_DIR) *.c)
OBJ = $(SRC.c = .o)

all : ${NAME}

${NAME} : ${OBJ}
	$(G) $(GCFLAGS) $(OBJ)


clean:
	$(RM) $(RMFLAGS) ${OBJ}

fclean: clean 
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re