#include <iostream>
#include <fstream>

int main(int argc, char ** argv) {
    std::cout << "Hello World" << std::endl;

    std::ifstream in("test.txt");

    char curr;
    
    while (curr != EOF) {
        curr = in.get();
        std::cout << curr;
    }

    in.close();

    return 0;
}