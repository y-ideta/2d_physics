main := main.cpp
draw := draw.cpp
mouse := mouse.cpp

build: $(main)
	g++ --std=c++0x -stdlib=libc++ -framework GLUT -framework OpenGL $(main) $(draw) $(mouse) -Wno-deprecated -o main

run: build
	./main

clean:
	rm -f main a.out
