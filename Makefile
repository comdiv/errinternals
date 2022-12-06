.PHONY: build
build:
	clang -g -Wall  -o errorint.exe ./*.c -lreadline

run: build
	./errorint.exe

expand:
	mkdir -p build
	clang -E -dD main.c > build/main.e.c
	clang -E -dD bonus.c > build/bonus.e.c