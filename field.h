#ifndef FIELD_H
#define FIELD_H

#include "VisibleObject.h"

class field : public VisibleObject{

public:
    field(int id); //constructor
    ~field(); //destructor
    void Load();
    void Update(float elapsedTime);
    void setRed();
    bool clicked;
private:
    int field_no;
};

#endif
