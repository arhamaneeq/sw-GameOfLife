#include "../include/utility.hpp"

#if defined(__UNIX__) || defined(__APPLE__)

#include <sys/ioctl.h>
#include <unistd.h>

TerminalSize TerminalUtils::getTerminalSize() {
    struct winsize w;
    std::vector dim(2,0);
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        dim[0] = 50;
        dim[1] = 10;
        return dim; // fallback
    }
    dim[0] = w.ws_col;
    dim[1] = w.ws_row;
    return dim;
}

#endif

#if defined(_WIN32)
#include<Windows.h>

std::vector<int> Utils::getWindowSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    std::vector<int> dim(2,0);
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        dim[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        dim[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }

    return dim;
}

#endif

//TODO: Linux