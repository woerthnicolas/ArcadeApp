#include "GridElement.h"
#include "../../Graphics/Color.h"

GridElement::GridElement(): mType(NONE), mColor(Color::White()), mIsFixed(true)
{
    
}

void GridElement::Update(uint32_t dt)
{
}

void GridElement::Draw(Screen& screen)
{
}

void GridElement::SetFixed()
{
    mIsFixed = true;
}

bool GridElement::GetFixed() const
{
    return mIsFixed;
}


