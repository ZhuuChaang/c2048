TARGET = c2048

SRCS = $(wildcard ./src/*.cpp)
FILE = $(notdir $(SRCS))
OBJS = $(patsubst %cpp, %o, ./obj/$(FILE))

object: $(SRCS)
	g++ -c $^ -o $(OBJS)

clean:
	@rm -f $(OBJS) $(TARGET) *_test