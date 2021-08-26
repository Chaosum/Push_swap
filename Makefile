FOLDER_UTILS		= Utils

FOLDER_SORTING		= sorting

FOLDER_INSTRUCT		= instructions

SRCS				= push_swap.c

SRCS_UTILS			= ${addprefix ${FOLDER_UTILS}/,utils.c utils_bis.c utils_bis_re.c}

SRCS_SORTING		= ${addprefix ${FOLDER_SORTING}/,sorting_a.c sorting_b.c}

SRCS_INSTRUCT		= ${addprefix ${FOLDER_INSTRUCT}/,push.c swap.c rotate.c reverse_rotate.c}

OBJS				= ${SRCS:.c=.o} ${SRCS_UTILS:.c=.o} ${SRCS_INSTRUCT:.c=.o} ${SRCS_SORTING:.c=.o}

INCLUDES			= push_swap.h push_swap_struct.h ${FOLDER_UTILS}/utils.h ${FOLDER_INSTRUCT}/instructions.h ${FOLDER_SORTING}/sorting.h

NAME				= push_swap

CC					= gcc

CFLAGS				=  -Wall -Wextra -Werror # -g3 -fsanitize=address 

all:		MAKELIBFT ${NAME}

bonus:		all

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a
				@echo compilation complete !
			

${OBJS}:	${INCLUDES}

MAKELIBFT:
			@make -C ./libft

clean:
			@rm -f *.o ${FOLDER_UTILS}/*.o ${FOLDER_INSTRUCT}/*.o ${FOLDER_SORTING}/*.o
			@echo files cleaned !

fclean:		clean
			@rm -rf ${NAME}
			@make fclean -C ./libft

re:			fclean all

.PHONY: all clean fclean re MAKELIBFT
