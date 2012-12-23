#ifndef CURSOR_H
#define CURSOR_H

#include "VisibleObject.h"

class Cursor : public VisibleObject{

public:
    Cursor();
    ~Cursor();
    void Load();
    void Update(float elapsedTime);
};

#endif

