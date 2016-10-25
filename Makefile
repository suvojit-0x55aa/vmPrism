CFLAGS = -Wall -std=c++0x
DIR = vmPrism
OBJ = FIFOPolicy.o
OBJS = $(OBJ:%=$(DIR)/%)
SRCS = $(OBJS:%.o=%.h)

$(OBJS): $(SRCS)
	g++ -c -o $@ $(CFLAGS) $(SRCS)
