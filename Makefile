NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

#includes
INCS 		= 	-I ./include/

#sources
SRC_PATH = src/
SRC 	= 		a_write.c \
				b_write.c \
				conditions.c \
				debugging.c \
				extremes.c \
				indexing.c \
				into_lists.c \
				main_initiate.c \
				operations.c \
				operations1.c \
				operations2.c \
				rotations.c \
				sort_all_helping.c \
				sorting_3.c \
				sorting_5.c \
				sorting_all.c

SRCS 	= 		$(addprefix $(SRC_PART), $(SRC))

#objects
OBJ_PATH 	= 	obj/
OBJ 		= 	$(SRC:.c=.o)
OBJS 		= 	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS)
	@echo "$(BOLD)[ 🙊 Compiling shit together... ]$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS)
	@echo "$(BOLD)[ 🪄 Program ready! ]$(NC)"


clean :
	@$(RM) $(OBJS) $(OBJ_PATH)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
