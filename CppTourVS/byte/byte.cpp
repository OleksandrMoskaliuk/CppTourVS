#include "byte.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

namespace byte {

My8bit::My8bit(int number) {
  if (number > 255) {
    std::cout
        << "ERROR: Number larger then cell, data partition will be lost\n";
  }
  for (uint16_t i = 1; i <= 8; i++) {
    this->data[i - 1] = Isbitset((byte)number, i);
  }
}

void My8bit::info() {
  std::cout << "dec: " << get_dec() << "\n";
  std::cout << "8bit: ";
  for (bool &cell : this->data) {
    std::cout << cell;
  }
  std::cout << std::endl;
  // as unigned int
  unsigned int result_in_integer = 0;
  int multiplier = 1;
  for (int i = 7; i >= 0; i--) {
    if (this->data[i]) {
      std::cout << i << "\n";
      result_in_integer += multiplier;
    }
    multiplier = multiplier * 10;
  }
  std::cout << result_in_integer; 

}

void My8bit::set_bit(unsigned char position, bool state) {
  if (position < 1 && position > 8) {
    std::cout << "ERROR wrong set bit position\n";
    return;
  }
  this->data[position] = state;
}

byte My8bit::get_byte() { return byte(); }

int My8bit::get_dec() {
  int index = 7;
  int result = 0;
  for (bool &cell : this->data) {
    if (cell) {
      result += pow(2, index);
    }
    index--;
  }
  return result;
}

void My8bit::test() 
{
  My8bit my8b(101);
  my8b.info();
}

}  // namespace _8bit
