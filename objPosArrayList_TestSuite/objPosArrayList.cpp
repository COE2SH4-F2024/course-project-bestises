#include "objPosArrayList.h"
#include <stdexcept> // For exception handling

// Constructor: Initializes the list with maximum capacity
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; // Set the capacity to the defined maximum
    listSize = 0;
    aList = new objPos[arrayCapacity];
}

// Destructor: Releases allocated memory
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// Copy Constructor: Performs deep copy
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

// Assignment Operator: Performs deep copy with self-assignment check
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other)
{
    if (this == &other)
        return *this;

    delete[] aList; // Clean up existing resources

    listSize = other.listSize;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = other.aList[i];
    }

    return *this;
}

// Returns the current size of the list
int objPosArrayList::getSize() const
{
    return listSize;
}

// Inserts an objPos at the head of the list
void objPosArrayList::insertHead(objPos thisPos)
{
    
    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos;
    ++listSize;
}

// Inserts an objPos at the tail of the list
void objPosArrayList::insertTail(objPos thisPos)
{
    
    aList[listSize] = thisPos;
    ++listSize;
}

// Removes the head element from the list
void objPosArrayList::removeHead()
{
    
    for (int i = 0; i < listSize - 1; ++i)
    {
        aList[i] = aList[i + 1];
    }

    --listSize;
}

// Removes the tail element from the list
void objPosArrayList::removeTail()
{
    
    --listSize;
}

// Returns the head element of the list
objPos objPosArrayList::getHeadElement() const
{
    
    return aList[0];
}

// Returns the tail element of the list
objPos objPosArrayList::getTailElement() const
{
    
    return aList[listSize - 1];
}

// Returns the element at the specified index
objPos objPosArrayList::getElement(int index) const
{
    

    return aList[index];
}
