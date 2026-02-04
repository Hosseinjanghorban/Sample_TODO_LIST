#ifndef LINKLIST_H
#define LINKLIST_H
#include "work.h"

class linklist
{
public:
    QString listname;
    work* headt = nullptr;
    work* head = nullptr;
    int size = 0;
    void pushFront(work & works);
    linklist & operator >>(work twork);
    linklist();
};

#endif // LINKLIST_H
