c2048: matrix.o src/c2048.cpp
	g++ -c src/c2048.cpp -o c2048.o
	g++ c2048.o matrix.o -o c2048 -lncurses


matrix.o: src/matrix.cpp 
	g++ -c src/matrix.cpp -o matrix.o


clean:
	@rm -f $(OBJS) $(TARGET) *_test