#pragma once

class DynamicIntArray
{
public:
    DynamicIntArray(const DynamicIntArray& other) = default;

    DynamicIntArray(DynamicIntArray&& other) noexcept : moptrData(other.moptrData),
                                                        mSize(other.mSize),
                                                        mCapacity(other.mCapacity)
    {
    }

    DynamicIntArray& operator=(const DynamicIntArray& other)
    {
        if (this == &other)
            return *this;
        moptrData = other.moptrData;
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        return *this;
    }

    DynamicIntArray& operator=(DynamicIntArray&& other) noexcept
    {
        if (this == &other)
            return *this;
        moptrData = other.moptrData;
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        return *this;
    }

    DynamicIntArray(): moptrData(nullptr), mSize(0), mCapacity(0) {}

    ~DynamicIntArray();

    inline size_t Size() const { return mSize; }
    inline size_t Capacity() const { return mCapacity; }

    bool Init(size_t capacity = INITIAL_CAPACITY);

    bool Reserve(size_t capacity);

    bool Resize(size_t newSize);

    bool PushBack(int newVal);
    bool PopBack(int& value);

    const int& operator[](size_t index) const;
    int& operator[](size_t index);


private:
    int * moptrData;
    size_t mSize;
    size_t mCapacity{};

    static const size_t INITIAL_CAPACITY = 10;
    static const size_t RESIZE_MULTIPLIER = 2;
};
