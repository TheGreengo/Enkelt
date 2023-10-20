#include <iostream>
#include <fstream>


int main(int argc, char ** argv) {
    std::cout << "Enkelt compiler starting" << std::endl;

    std::ifstream in("test.txt");

    in.close();

    return 0;
}