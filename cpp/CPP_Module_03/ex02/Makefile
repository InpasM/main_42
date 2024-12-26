# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msapin <msapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:19:36 by msapin            #+#    #+#              #
#    Updated: 2023/09/05 15:01:52 by msapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ##################################### #
#               VARIABLES               #
# ##################################### #

NAME		=	fragTrap

UNAME		=	$(shell uname)

NOCOLOR		=	\033[0m
BGREEN		=	\033[1;32m

HEADER		=	ClapTrap.hpp ScavTrap.hpp	FragTrap.hpp

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

SRCS	=	main.cpp	ClapTrap.cpp	ScavTrap.cpp	FragTrap.cpp


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

run:
		$(MAKE) all
		./$(NAME)

clean:
			$(RM) $(OBJS)

fclean:
			$(MAKE) clean
			$(RM) $(NAME)
			$(RM) $(OBJS_DIRS)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:		all clean fclean re run