OBJ := obj/main.o obj/io.o obj/comp.o
TRG := out/imageq

$(TRG): $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system

$(OBJ): obj/%.o : src/%.cpp 
	g++ -I inc/ -c -std=c++98 -o $@ $^

clean:
	rm $(OBJ) $(TRG)
