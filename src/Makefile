##
## OnWorkset
## Makefile
##

NAME	=	../onWorkset

CC	=	gcc

# LIBNAME	=	libbtree.a

INCNAME	=	../includes/onWorkset.h

ARRC	=	ar rc $(LIBNAME)

# COPY_LIB_PATH	=	./libbtree.a

# COPY_INC_PATH	=	./include/

SRC	=	instance.c \
		main.c \

SRC_TEST	=	main.c \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)	clean

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -I$(INCNAME) -o $(NAME)
	# $(ARRC) $(OBJ)
	#mv $(LIBNAME) $(COPY_LIB_PATH)
	# cp $(INCNAME) $(COPY_INC_PATH)

clean:
	rm -f *.o *~

fclean:	clean
	rm -f ./$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
