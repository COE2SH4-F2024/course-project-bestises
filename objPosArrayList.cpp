#include "objPosArrayList.h"



objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    listSize = 0;
    aList = new objPos[arrayCapacity];
}


objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// Copy Constructor
objPosArrayList::objPosArrayList(const objPosArrayList& other)
{
    listSize = other.listSize;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }
}

// Assignment Operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other)
{
    if (this == &other)
        return *this;

    delete[] aList; 
    listSize = other.listSize;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }

    return *this;
}


int objPosArrayList::getSize() const
{
    return listSize;
}


void objPosArrayList::insertHead(objPos thisPos)
{
    
    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos;
    ++listSize;
}


void objPosArrayList::insertTail(objPos thisPos)
{
    
    aList[listSize] = thisPos;
    ++listSize;
}


void objPosArrayList::removeHead()
{
    
    for (int i = 0; i < listSize - 1; ++i)
    {
        aList[i] = aList[i + 1];
    }

    --listSize;
}


void objPosArrayList::removeTail()
{
    
    --listSize;
}


objPos objPosArrayList::getHeadElement() const
{
    
    return aList[0];
}


objPos objPosArrayList::getTailElement() const
{
    
    return aList[listSize - 1];
}


objPos objPosArrayList::getElement(int index) const
{
    

    return aList[index];
}

void objPosArrayList::replaceElement(int index, objPos element)
{
    aList[index] = element;
}