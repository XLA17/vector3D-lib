wsl
g++ -O3 -std=c++20 -fopenmp -Wall -Iinclude main.cpp $(find src -name "*.cpp") -o main
./main