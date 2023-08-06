all:
	mkdir -p release

	gcc -DNO_COMPRESSION main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o release/pro
	strip --strip-unneeded release/pro
	upx --lzma --best release/pro

	gcc main.c -Ofast -lm -lz -lSDL2 -lGLESv2 -lEGL -o release/pro_compressed
	strip --strip-unneeded release/pro_compressed
	upx --lzma --best release/pro_compressed

	gcc -DNO_COMPRESSION -DSKYBLUE main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o release/prosky
	strip --strip-unneeded release/prosky
	upx --lzma --best release/prosky

	gcc -DSKYBLUE main.c -Ofast -lm -lz -lSDL2 -lGLESv2 -lEGL -o release/prosky_compressed
	strip --strip-unneeded release/prosky_compressed
	upx --lzma --best release/prosky_compressed

test:
	gcc -DNO_COMPRESSION main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o pro_test
	./pro_test
	rm pro_test

clean:
	rm -r release
