main := main.cpp
draw := draw.cpp
mouse := mouse.cpp
simu := simu.cpp

build: $(main)
	g++ --std=c++0x -stdlib=libc++ -framework GLUT -framework OpenGL $(main) $(draw) $(mouse) $(simu) -Wno-deprecated -o main

run: build
	./main

clean:
	rm -f main a.out
