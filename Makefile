OBJ := obj/main.o obj/io.o

out/imageq: $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system

$(OBJ): obj/%.o : src/%.cpp 
	g++ -I inc/ -c -std=c++98 -o $@ $^
