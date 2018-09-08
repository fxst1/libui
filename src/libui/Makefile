# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2018/09/08 14:05:26 by fjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g
INC = -I ../../inc/ -I ../../inc/SDL2 -I ../../libft/ -I ../../SDL2-2.0.8/include/
LIBFT = ../../libft/libft.a
LIBS = -L ../../libft/ -lft -L ../../sdllib -l SDL2-2.0.0
OBJDIR = ../../obj/

SDLDIR = ../../SDL2-2.0.8/
SRC := $(filter %.c, $(shell find . -type f))
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

TARGET = ../../libui.a

all: $(TARGET)

$(TARGET) : $(OBJ)
	ar -rc $(TARGET) $(OBJ)

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)

cleanlib:
	make -C libft fclean

fclean: cleanlib
	@rm -rf $(OBJDIR)
	@rm -rf $(LIBUI)
	@rm -rf $(GUIMP)

re: fclean all
