main_release: main_release.o
	g++ -o ./bin/release/program.exe ./object/release/main.o

main_debug: main_debug.o
	g++ -o ./bin/debug/program.exe ./object/debug/main.o

main_release.o: main.cpp
	g++ -c main.cpp -o ./object/release/main.o

main_debug.o: main.cpp
	g++ -g -c main.cpp -o ./object/debug/main.o

preprocess: main.cpp
	g++ -E main.cpp -o main.ii

clean:
	rm -f *.o *.ii ./bin/debug/*.exe ./bin/release/*.exe ./object/debug/*.o ./bin/object/*.o