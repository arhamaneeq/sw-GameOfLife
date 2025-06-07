#ifndef UTILITY_HPP
#define UTILITY_HPP

#include<vector>
#if defined(__UNIX__) || defined(__linux__) || defined(__APPLE__)
#include <sys/ioctl.h>
#include <unistd.h>
#endif
#if defined(_WIN32)
#include<Windows.h>
#endif
namespace Utils {
    std::vector<int> getWindowSize();
}
#endif
