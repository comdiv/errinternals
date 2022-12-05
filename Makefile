build:
	clang -o errorint.exe ./*.c -lreadline

run: build
	./errorint.exe
