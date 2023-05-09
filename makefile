TARGET = main
SRCS = $(wildcard *.cpp) $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
CC = g++
CCFLAGS = -std=c++11 -Wall

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.exe