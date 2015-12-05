a.out: main.cpp bigNumber.h bigNumber.cpp list.cpp list.h node.cpp node.h
	g++ main.cpp bigNumber.cpp list.cpp node.cpp -g -Werror

run:a.out
	./a.out

test:a.out
	gdb -tui ./a.out

