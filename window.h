
#ifndef WIN
#define WIN

#include "functions.h"

class Window{
public:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif