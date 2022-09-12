#include "DynamicIntArray.h"

#include <cassert>
#include <new>

DynamicIntArray::~DynamicIntArray()
{
    delete[] moptrData;
    moptrData = nullptr;
}

bool DynamicIntArray::Init(size_t capacity)
{
    if (capacity == 0)
    {
        return false;
    }

    if (mCapacity == capacity)
    {
        return true;
    }

    if (moptrData)
    {
        delete[] moptrData;
        moptrData = nullptr;
        mSize = 0;
        mCapacity = 0;
    }

    moptrData = new(std::nothrow) int[capacity];
    if (!moptrData)
    {
        return false;
    }

    mSize = 0;
    mCapacity = capacity;
    return true;
}

bool DynamicIntArray::Reserve(size_t capacity)
{
    if (mCapacity < capacity)
    {
        int* oldData = moptrData;

        moptrData = new(std::nothrow) int[capacity];

        if (!moptrData)
        {
            moptrData = oldData;
            return false;
        }

        mCapacity = capacity;

        for (size_t i = 0; i < mSize; ++i)
        {
            moptrData[i] = oldData[i];
        }

        delete[] oldData;
    }
    return true;
}

bool DynamicIntArray::Resize(size_t newSize)
{
    if (mCapacity < newSize)
    {
        bool reserveSucceeded = Reserve(newSize);
        if (!reserveSucceeded)
        {
            return reserveSucceeded;
        }
    }

    for (size_t i = mSize; i < newSize; ++i)
    {
        moptrData[i] = 0;
    }

    mSize = newSize;
    return true;
}

bool DynamicIntArray::PushBack(int newVal)
{
    assert(moptrData && "Has not been Initialized - call Init()");
    if(!moptrData)
    {
        return false;
    }

    if(mSize + 1 > mCapacity)
    {
        bool reserveResult = Reserve(mCapacity * RESIZE_MULTIPLIER);

        if(!reserveResult)
        {
            return false;
        }
    }

    moptrData[mSize++] = newVal;

    return true;
}

bool DynamicIntArray::PopBack(int& value)
{
    assert(moptrData && "Has not been Initialized - call Init()");
    if(!moptrData)
    {
        return false;
    }
    
    if(mSize > 0)
    {
        value = moptrData[--mSize];
        return true;
    }

    return false;
}

const int& DynamicIntArray::operator[](size_t index) const
{
    //assert(moptrData && index < mSize);
    return moptrData[index];
}

int& DynamicIntArray::operator[](size_t index)
{
    //assert(moptrData && index < mSize);
    return moptrData[index];
}
