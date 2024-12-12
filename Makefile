out/imageq: main.cpp
	g++ -o $@ $^ -lsfml-graphics -lsfml-system
