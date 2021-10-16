# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 14:41:21 by rzukale           #+#    #+#              #
#    Updated: 2021/10/16 15:09:29 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = particle-fire

SRCS = \
		main.cpp \

HEADERS = \
		headers$(SLASH)particle_fire.h \

WIN_INCLUDE_PATHS = \
	-ISDL2-2.0.16\i686-w64-mingw32\include\SDL2

LINUX_INCLUDE_PATHS = -I$(SDL_INC)

WIN_LIBRARY_PATHS = -LSDL2-2.0.16\i686-w64-mingw32\lib
LINUX_LINK_FLAGS = -lSDL2

CC = g++

ifeq ($(OS),Windows_NT)
	TARGET_SYSTEM := Windows
else
	TARGET_SYSTEM := $(shell uname -s)
	TARGET_SYSTEM := $(patsubst CYGWIN%,Cygwin,$(TARGET_SYSTEM))
	TARGET_SYSTEM := $(patsubst MSYS%,MSYS,$(TARGET_SYSTEM))
	TARGET_SYSTEM := $(patsubst MINGW%,MSYS,$(TARGET_SYSTEM))
endif

ifeq ($(TARGET_SYSTEM),Windows)
	NAME = particle-fire.exe
	INCLUDES = $(WIN_INCLUDE_PATHS)
	LIBS = $(WIN_LIBRARY_PATHS)
	CFLAGS = -Wall -Wextra -Werror -O1
	LDFLAGS = -lmingw32 -lSDL2main -lSDL2
	SDL_NEW = SDL2-2.0.16\i686-w64-mingw32
	SLASH = \\
	MKDIR = mkdir
	RM = del /s/q
	RESET := [0m
	RED := [31m
	GREEN := [32m
	YELLOW := [33m
	BLUE := [34m
	MAGENTA := [35m
	CYAN := [36m
	WHITE := [37m
else
	ABS_DIR = $(shell pwd)
	INCLUDES = $(LINUX_INCLUDE_PATHS)
	LIBS = $(shell $(ABS_DIR)/SDL2/bin/sdl2-config --libs) -L$(SDL_MIXER_NEW)lib
	CFLAGS = -Wall -Wextra -Werror $(shell $(ABS_DIR)/SDL2/bin/sdl2-config --cflags) -O3
	LDFLAGS = $(LINUX_LINK_FLAGS)
	SLASH = /
	MKDIR := mkdir -p
	RM = /bin/rm -rf
	RESET = "\033[0m"
	RED = "\033[0;31m"
	GREEN = "\033[0;32m"
	YELLOW = "\033[0;33m"
	BLUE = "\033[0;34m"
	MAGENTA = "\033[0;35m"
	CYAN = "\033[0;36m"
	WHITE = "\033[0;37m"
	SDL_ORIG = $(ABS_DIR)/SDL2-2.0.16/
	SDL_NEW = $(ABS_DIR)/SDL2/
	SDL_INC = SDL2/include/SDL2/
	CORES = $(shell echo 2+$(shell cat /proc/cpuinfo | grep processor | wc -l) | bc)
endif

S = srcs
O = objs
SRC = $(addprefix $S$(SLASH), $(SRCS))
OBJ = $(SRC:$S%=$O%.o)

.PHONY: all clean fclean re debug

all: $(NAME)

$(SDL_NEW):
ifeq ($(TARGET_SYSTEM), Linux)
	@if [ ! $(shell command -v wget 2> /dev/null) ]; then \
	sudo apt-get install wget -y; \
	fi
	@if [ ! -f "SDL2-2.0.16.tar.gz" ]; then \
	wget https://www.libsdl.org/release/SDL2-2.0.16.tar.gz; \
	fi
	@if [ ! -d "$(SDL_ORIG)" ]; then \
	tar -xzf SDL2-2.0.16.tar.gz; \
	fi
	@if [ ! -d "$(SDL_NEW)" ] ; then \
	mkdir -p $(SDL_NEW); \
	cd $(SDL_NEW) && \
	$(SDL_ORIG)./configure --prefix=$(SDL_NEW) && \
	make -j$(CORES) && make install ; \
	else    \
	make -j$(CORES) -C $(SDL_NEW) ; \
	fi
else
	@IF NOT EXIST $(SDL_NEW) ( install.bat )\
	ELSE ECHO $(GREEN)"Folder exists."$(RESET)
endif

$O:
	$(MKDIR) $@

$(OBJ): | $O

$(OBJ): $O%.o: $S% $(HEADERS)
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDES) $<

$(NAME): $(SDL_NEW) $(OBJ)
	$(CC) -o $@ $(INCLUDES) $(LIBS) $(CFLAGS) $(OBJ) $(LDFLAGS)
	@echo $(GREEN)Compiled executable $(NAME).

cleanobj:
ifneq ($(wildcard $(OBJ)),)
	@$(RM) $(wildcard $(OBJ))
endif

cleanobjdir: cleanobj
ifeq ($(TARGET_SYSTEM), Linux)
	@$(RM) $O
else
	@IF EXIST $O ( rd /s /q "$O" )
endif

clean: cleanobjdir
ifeq ($(TARGET_SYSTEM), Linux)
	@if [ -d "$(SDL_NEW)" ] ; then \
	make -C $(SDL_NEW) clean ; \
	fi;
endif
	@echo $(GREEN)Cleaned projects from object files.$(RESET)

fclean: clean
ifeq ($(TARGET_SYSTEM), Windows)
	@IF EXIST SDL2-2.0.16 ( $(RM) "SDL2-2.0.16" )
	@IF EXIST SDL2-2.0.16 ( rd /s /q "SDL2-2.0.16" )
	@IF EXIST "SDL2-devel-2.0.16-mingw.tar.gz" ( $(RM) "SDL2-devel-2.0.16-mingw.tar.gz" )
	@IF EXIST $(NAME) ( $(RM) "$(NAME)") \
	ELSE ( ECHO $(CYAN)No binary to remove. $(RESET) )
else
	@$(RM) $(NAME)
	@$(RM) $(SDL_NEW)
	@$(RM) $(SDL_ORIG)
	@$(RM) SDL2-2.0.16.tar.gz
endif
	@echo $(GREEN)Removed binaries and libraries.$(RESET)

re: fclean all
