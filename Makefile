a.out: main.cpp bigNumber.h bigNumber.cpp list.cpp list.h node.cpp node.h
	g++ main.cpp bigNumber.cpp list.cpp node.cpp -g
