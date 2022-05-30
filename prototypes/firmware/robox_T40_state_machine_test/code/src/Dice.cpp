// ======================================
// Filename:
//   Dice.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Dice, can be thrown.
// ======================================

#include "Dice.h"
#include "Entropy.h"

Dice::Dice(const uint8_t nrOfSides) : m_sides(nrOfSides), m_value(0)
{
    Entropy.Initialize();
    Roll();
}

Dice::~Dice()
{
}

void Dice::Roll()
{
    m_value = Entropy.random(1, m_sides + 1);
}

uint8_t Dice::GetSides() const
{
    return m_sides;
}

uint8_t Dice::GetValue() const
{
    return m_value;
}

bool Dice::operator==(const Dice& rhs) const
{
    return m_value == rhs.m_value;
}

bool Dice::operator==(uint8_t rhs) const
{
    return m_value == rhs;
}

bool Dice::operator!=(const Dice& rhs) const
{
    return !operator==(rhs);
}

bool Dice::operator!=(uint8_t rhs) const
{
    return !operator==(rhs);
}

uint64_t Dice::operator+(const Dice& rhs) const
{
    return m_value + rhs.m_value;
}

uint64_t Dice::operator+(uint64_t rhs) const
{
    return this->m_value + rhs;
}
bool operator==(uint8_t lhs, const Dice& rhs)
{
    return rhs.operator==(lhs);
}
bool operator!=(uint8_t lhs, const Dice& rhs)
{
    return rhs.operator!=(lhs);
}
uint64_t operator+(uint64_t lhs, const Dice& rhs)
{
    return rhs.GetValue() + lhs;
}