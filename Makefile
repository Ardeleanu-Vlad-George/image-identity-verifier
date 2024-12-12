out/imageq: src/main.cpp
	g++ -o $@ $^ -lsfml-graphics -lsfml-system
