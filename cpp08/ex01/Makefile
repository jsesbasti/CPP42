# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 07:41:15 by jsebasti          #+#    #+#              #
#    Updated: 2023/12/12 11:01:13 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Span
NPD			= --no-print-directory
OBJ_DIR		= obj/


# ----Libraryes----
INC_DIR = inc/
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CC = clang++
CFLAGS = -Werror -Wextra -Wall -O3 -g -std=c++98 -fsanitize=address
# =============
 
FILES = main $(NAME)

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp src

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.cpp
	@$(MP) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@
	@echo "Object of the file $(basename $<) has been created 🤐"

all:
	@$(MAKE) $(NAME) $(NPD)

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling $(NAME) 😈"

$(NAME)::
	@echo "Hello, $(NAME) already compiled 😇"

-include $(DEP)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(OBJ_DIR) and company leave 42 🗑"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been black holed 🕳"

re:
	@$(MAKE) fclean $(NPD)
	@$(MAKE) $(NPD)

.PHONY: all clean fclean re