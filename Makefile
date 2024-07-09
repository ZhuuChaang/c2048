TARGET = c2048

SRCS = $(wildcard ./src/*.cpp)
FILE = $(notdir $(SRCS))
OBJS = $(patsubst %cpp, %o, ./obj/$(FILE))

TSRCS = $(wildcard ./test/*.cpp)
TFILE = $(notdir $(TSRCS))
TOBJS = $(patsubst %cpp, %o, ./obj/$(TFILE))

object: $(SRCS)
#	@echo $(SRCS)
#	@echo $(FILE)
#	@echo $(OBJS)
	g++ -c $^ -o $(OBJS)

test:$(TSRCS) $(OBJS)
	@g++ -c $(TSRCS) -o $(TOBJS)
	@g++ ./obj/matrix_test.o ./obj/matrix.o -o matrix_test
	./matrix_test

clean:
	@rm -f $(OBJS) $(TARGET) *_test