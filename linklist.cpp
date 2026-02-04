#include "linklist.h"

linklist::linklist()
{

}


void linklist::pushFront(work& works)
{
    if (size == 0) {
        work  tmp;
        tmp = works;
        head = &tmp;
        headt=head;
        size++;
    }
    else {
        work  tmp;
        tmp = works;
        head=&tmp;
        size++;
    }
}

linklist &linklist::operator >>(work twork)
{
    this->pushFront(twork);
    return *this;
}



