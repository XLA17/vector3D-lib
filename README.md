g++ -O3 -fopenmp -Wall -Iinclude main.cpp $(find src -name "*.cpp") -o main
./main