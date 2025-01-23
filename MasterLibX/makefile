# big header

# ****************|  Variable  |**************** #
NAME =	Mlibx.a

CC =	gcc
CFlags = -Wall -Wextra -Werror
AR =	ar rcs

# ****************|  Sources  |**************** #

DIR_LAYOUT =	layout
DIR_MEMORY=		memory
DIR_STORAGE=	storage
DIR_OBJECTS=	.obj

INC_LAYOUT =	-I $(DIR_LAYOUT)
INC_MEMORY =	-I $(DIR_MEMORY)
INC_STORAGE =	-I $(DIR_STORAGE)

SRC_LAYOUT = $(DIR_LAYOUT)/window.c
SRC_MEMORY = #$(DIR_MEMORY)/memory.c
SRC_STORAGE = #$(DIR_STORAGE)/storage.c

INC_GLOBAL = $(INC_LAYOUT) $(INC_MEMORY) $(INC_STORAGE)
SRC_GLOBAL = $(SRC_LAYOUT) $(SRC_MEMORY) $(SRC_STORAGE)

# ****************|  Objects  |**************** #

OBJ_LAYOUT = $(SRC_LAYOUT:$(DIR_LAYOUT)/%.c=$(DIR_OBJECTS)/%.o)
OBJ_MEMORY = $(SRC_MEMORY:$(DIR_MEMORY)/%.c=$(DIR_OBJECTS)/%.o)
OBJ_STORAGE = $(SRC_STORAGE:$(DIR_STORAGE)/%.c=$(DIR_OBJECTS)/%.o)

OBJ_GLOBAL = $(OBJ_LAYOUT) $(OBJ_MEMORY) $(OBJ_STORAGE)

# ****************|  Rules  |**************** #

all: compile

compile: $(OBJ_GLOBAL)
	$(AR) $(NAME) $(OBJ_GLOBAL)

$(DIR_OBJECTS)/%.o: $(DIR_LAYOUT)/%.c
	$(CC) $(CFlags) $(INC_GLOBAL) -c $< -o $@

$(DIR_OBJECTS)/%.o: $(DIR_MEMORY)/%.c
	$(CC) $(CFlags) $(INC_GLOBAL) -c $< -o $@

$(DIR_OBJECTS)/%.o: $(DIR_STORAGE)/%.c
	$(CC) $(CFlags) $(INC_GLOBAL) -c $< -o $@

$(DIR_OBJECTS):
	mkdir -p $(DIR_OBJECTS)

clean:
	rm -f $(OBJ_GLOBAL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all compile clean fclean re