#include <iostream>
#include <fstream>


int main(int argc, char ** argv) {
    std::cout << "Enkelt compiler starting" << std::endl;

    std::ifstream in("test.txt");

    char curr;
    
    while (curr != EOF) {
        curr = in.get();
        std::cout << curr;
    }

    in.close();

    return 0;
}