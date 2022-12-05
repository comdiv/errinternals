build:
	clang -o errorint.exe ./*.c -lreadline

run: build
	./errorint.exe

expand:
	mkdir -p build
	clang -E -dD main.c > build/main.expanded.txt
	clang -E -dD bonus.c > build/bonus.expanded.txt