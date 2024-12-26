# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msapin <msapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:19:47 by msapin            #+#    #+#              #
#    Updated: 2023/08/29 10:22:28 by msapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ##################################### #
#               VARIABLES               #
# ##################################### #

NAME		=	HarlFilter

UNAME		=	$(shell uname)

NOCOLOR		=	\033[0m
BGREEN		=	\033[1;32m

HEADER		=	Harl.hpp

MAKEFILE	=	Makefile

CPP			=	c++

CFLAGS 		= 	-Wall -Wextra -Werror -std=c++98

RM 			= 	rm -rf

AR 			= 	ar

ARFLAGS 	= 	-rcs


# ##################################### #
#                 PATHS                 #
# ##################################### #

OBJS_DIRS	=	.objs/


# ##################################### #
#                SOURCES                #
# ##################################### #

SRCS	=	main.cpp	Harl.cpp


# ##################################### #
#                OBJECTS                #
# ##################################### #

OBJS	=	$(addprefix $(OBJS_DIRS),	$(SRCS:.cpp=.o))

$(OBJS_DIRS)%.o: $(SRCS_PATH)%.cpp $(MAKEFILE) $(HEADER)
	$(CPP) $(CFLAGS) -o $@ -c $<


# ##################################### #
#                 RULES                 #
# ##################################### #

all:		$(OBJS_DIRS) $(NAME)

$(OBJS_DIRS):
			mkdir -p $(OBJS_DIRS)

$(NAME):	$(OBJS)
ifeq ($(UNAME),Linux)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BGREEN)Linux Compilation Done$(NOCOLOR)"
else ifeq ($(UNAME),Darwin)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BGREEN)Mac OS Compilation Done$(NOCOLOR)"
endif

clean:
			$(RM) $(OBJS)

fclean:
			$(MAKE) clean
			$(RM) $(NAME)
			$(RM) $(OBJS_DIRS)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:		all clean fclean re