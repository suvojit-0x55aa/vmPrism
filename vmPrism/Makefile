CFLAGS = -Wall -std=c++14

OBJ = FIFOPolicy.o

SRCS = $(OBJ:%.o=%.h)

$(OBJ): $(SRCS)
	g++ -c -o $@ $(CFLAGS) $(SRCS)
