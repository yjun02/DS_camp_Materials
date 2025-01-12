CC = gcc
CPP = g++
CFLAGS = -Wall -g
CPPFLAGS = -Wall -g

C_SOURCES = $(wildcard *.c)
CPP_SOURCES = $(wildcard *.cpp)

C_EXECUTABLES = $(C_SOURCES:.c=)
CPP_EXECUTABLES = $(CPP_SOURCES:.cpp=)

all: $(C_EXECUTABLES) $(CPP_EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	rm -f $(C_EXECUTABLES) $(CPP_EXECUTABLES)
