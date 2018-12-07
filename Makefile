ToyChain: main.cpp Block.cpp Blockchain.cpp sha256.cpp Block.h Blockchain.h sha256.h
	g++ \
	-std=c++11 \
	-o ToyChain \
	main.cpp Block.cpp Blockchain.cpp sha256.cpp

run: ToyChain 
	./ToyChain
