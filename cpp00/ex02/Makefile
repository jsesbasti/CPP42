# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 13:43:37 by jsebasti          #+#    #+#              #
#    Updated: 2023/07/17 03:19:08 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Account
MKFL		= Makefile
NPD			= --no-print-directory
OBJ_DIR		= obj/


# ----Libraryes----
INC_DIR = inc/
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CC = clang++
CFLAGS = -Werror -Wextra -Wall -std=c++98
# =============

FILES = tests Account

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp .

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.cpp $(MKFL)
	@$(MP) $(dir $@)
	$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@

all:
	@$(MAKE) $(NAME) $(NPD)

$(NAME):: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME)::
	@echo "Hello, Account already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean $(NPD)
	@$(MAKE) $(NPD)

.PHONY: all clean fclean re