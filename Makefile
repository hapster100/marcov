SRCS=./*/*.cpp main.cpp
OUT=run

all:
	g++ $(SRCS) -o $(OUT)