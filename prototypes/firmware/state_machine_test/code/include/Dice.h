// ======================================
// Filename:
//   Dice.h
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

#ifndef ROBOX_STATE_MACHINE_TEST_DICE_H
#define ROBOX_STATE_MACHINE_TEST_DICE_H

#include <Arduino.h>

class Dice
{
public:
	explicit Dice(uint8_t nrOfSides = 6);
	Dice(const Dice& other) = delete;
	virtual ~Dice();

	/**
	 * @brief Roll dice.
	 * 
	 */
	void Roll();
	/**
	 * @brief Get the amount of sides of this die.
	 * 
	 * @return uint8_t Amount of sides.
	 */
	uint8_t GetSides() const;
	/**
	 * @brief Get the generated result of dice throw.
	 * 
	 * @return uint8_t Generated value.
	 */
	uint8_t GetValue() const;

	Dice& operator=(const Dice& rhs) = delete;
	bool operator==(const Dice& rhs) const;
	bool operator==(uint8_t rhs) const;
	bool operator!=(const Dice& rhs) const;
	bool operator!=(uint8_t rhs) const;
	uint64_t operator+(const Dice& rhs) const;
	uint64_t operator+(uint64_t rhs) const;

private:
	uint8_t m_sides;
	uint8_t m_value;
};

bool operator==(uint8_t lhs, const Dice& rhs);
bool operator!=(uint8_t lhs, const Dice& rhs);
uint64_t operator+(uint64_t lhs, const Dice& rhs);

#endif // ROBOX_STATE_MACHINE_TEST_DICE_H