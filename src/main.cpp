#include<iostream>
#include<thread>
#include<chrono>

int main() {
    const int width = 40, height = 10;
    int i = 0;

    while (true) {
        std::cout << "\033[H\033[J";
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << (((x + y + i) % 2 == 0) ?  "#" : " "); 
            }
            std::cout << "\n";
        }

        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}