linux: main.c
	gcc -o koordgeo-linux64.bin main.c -lm

windows: main.c
	x86_64-w64-mingw32-gcc -o koordgeo-win64.exe main.c -lm

clean:
	rm -f koordgeo-win64.exe
	rm -f koordgeo-linux64.bin
