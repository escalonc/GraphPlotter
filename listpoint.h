#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "list.h"
#include "point.h"

class ListPoint : public List<Point*>
{
public:
    ListPoint() {}

    bool equals(Point *firstValue, Point *secondValue)
    {
        return firstValue->getVertex()->getName() == secondValue->getVertex()->getName();
    }
};

#endif // LISTPOINT_H
