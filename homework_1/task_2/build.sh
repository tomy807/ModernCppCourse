rm -r build
mkdir build

c++ -I ./include/ -c src/subtract.cpp -o build/subtract.o
c++ -I ./include/ -c src/sum.cpp -o build/sum.o

ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

rm -r results
mkdir -p results/bin

c++ src/main.cpp -I ./include/ -L ./build/ -lipb_arithmetic -o ./results/bin/test_ipb_arithmetic