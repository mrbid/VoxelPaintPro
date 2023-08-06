all:
	gcc -DNO_COMPRESSION ../main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o voxelpaintpro

install:
	cp voxelpaintpro $(DESTDIR)

uninstall:
	rm $(DESTDIR)/voxelpaintpro

clean:
	rm voxelpaintpro
