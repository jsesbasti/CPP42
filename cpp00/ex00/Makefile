# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 01:04:01 by jsebasti          #+#    #+#              #
#    Updated: 2023/10/02 12:56:59 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Megaphone
MKFL		= Makefile
OBJ_DIR		= obj/


# ----Libraryes----
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CC = clang++
CFLAGS = -Werror -Wextra -Wall -std=c++98
# =============

SRC = Megaphone.cpp

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.cpp
	@$(MP) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@
	@echo "Object of the file $(basename $<) has been created 🤐"

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling $(NAME) 😈"

$(NAME)::
	@echo "Hello, Megaphone already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) --no-print-directory

.PHONY: all clean fclean re