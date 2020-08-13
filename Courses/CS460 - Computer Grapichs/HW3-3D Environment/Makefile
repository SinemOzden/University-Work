CC=g++
CFLAGS=-c -Wall

LDFLAGS = -lGL -lglut  -lGLU
INSTALLED_DEPS = -Idependencies/include -Ldependencies/lib

SOURCES=main.cpp menu.cpp display.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=project 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS) $(INSTALLED_DEPS)

main.o: main.cpp menu.h display.h util.h
	$(CC) $(CFLAGS) $< $(LDFLAGS) $(INSTALLED_DEPS)

menu.o: menu.cpp menu.h display.h util.h
	$(CC) $(CFLAGS) $<  $(LDFLAGS) $(INSTALLED_DEPS)

display.o :display.cpp display.h util.h
	$(CC) $(CFLAGS) $< $(LDFLAGS) $(INSTALLED_DEPS)

clean:
	rm *.o project 
