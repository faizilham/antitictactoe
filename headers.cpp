#include "headers.h"

std::string IntToStr(int n){
    std::stringstream ss;
    ss<<n;
    return ss.str();
}
