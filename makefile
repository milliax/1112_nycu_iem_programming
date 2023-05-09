TARGET = main
SRCS = $(wildcard *.cpp) $(wildcard lib/*.cpp)
OBJS = $(SRCS:.cpp=.o)
CC = g++
CCFLAGS = -std=c++11 

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.exe