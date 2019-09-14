NAME	=	ft_gkrellm
CLANG	=	clang++ -Wall -Wextra -Werror
SRC		=	./main.cpp \
                Engine.cpp\
                AsciiPictures.cpp\
                Terminal.cpp\
                TimeMonitor.cpp\
                BaseDisplay.cpp\
                UserMonitor.cpp\
                SystemMonitor.cpp\
                MemoryMonitor.cpp\
                NetworkMonitor.cpp\
                CPUModule.cpp\
                PonyMonitor.cpp

HEADERS = 		Engine.hpp\
 				AsciiPictures.hpp\
 				Terminal.hpp\
 				TimeMonitor.hpp\
 				BaseDisplay.hpp\
 				UserMonitor.hpp\
 				CPUModule.hpp\
 				SystemMonitor.hpp\
                MemoryMonitor.hpp\
                NetworkMonitor.hpp\
                PonyMonitor.hpp\
                IMonitorDisplay.hpp\
                IMonitorModule.hpp
OBJ		=	$(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CLANG) -lncurses -o $(NAME) $(OBJ)
%.o: %.cpp $(HEADERS)
	$(CLANG) -o $@ -c $<
clean:
	rm -rf $(OBJ)
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
re: fclean all
