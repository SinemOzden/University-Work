To compile the first 3 parts of the assigment run these lines:
g++ -Wall -g -I/usr/include -c main.cpp -o main.o
g++ main.cpp -lglut -lGL -lGLU -lXxf86vm
./a.out

For mouse click part run:
g++ -Wall -g -I/usr/include -c mouse.cpp -o mouse.o
g++ mouse.cpp -lglut -lGL -lGLU -lXxf86vm
./a.out
