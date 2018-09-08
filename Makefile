# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2018/09/08 17:19:17 by fjacquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
OBJDIR = ./obj/

LIBUI = libui.a
GUIMP = guimp
SDL = ./libSDL2.a
SDLDIR = SDL2-2.0.8

all: $(GUIMP)

$(LIBUI) :
	make -C ./src/libui

$(GUIMP) : $(LIBUI)
	make -C ./src/guimp

$(LIBFT):
	make -C libft

$(SDL):
	cd $(SDLDIR) && ./configure
	make -C $(SDLDIR)
	ln -sf ./SDL2-2.0.8/build/.libs/libSDL2.a ./libSDL2.a

clean:
	@rm -rf $(OBJDIR)

cleanlib:
	make -C libft fclean

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(LIBUI)
	@rm -rf $(GUIMP)

re: fclean all
