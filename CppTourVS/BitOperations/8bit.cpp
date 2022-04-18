#include "8bit.h"

namespace _8bit {

My8bit::My8bit(int number) {
  if (number > 255) {
    std::cout << "ERROR: Number larger then cell, data partition will be lost\n";
  }
  byte n = number;
  for (uint16_t i = 1; i <= 8; i++) {
    this->data[i - 1] = Isbitset(n, i);
  }
}
void My8bit::info() {
  std::cout << "dec: " << f8bit_to_dec() << "\n";
  std::cout << "8bit: ";
  for (bool &cell : this->data) {
    std::cout << cell;
  }
}

void My8bit::set_bit(uint16_t position, bool state) 
{
  if (position < 1 && position > 8) {
    std::cout << "ERROR wrong set bit position\n";
    return;
  }
  this->data[position] = state;
}

uint16_t My8bit::f8bit_to_dec() { 
  int index = 7;
  int result = 0;
  for (bool &cell : this->data) 
  {
    if (cell) {
      result += pow(2, index);
    }
    index--;
  }
    return result; }



int entry_point() {
  My8bit my8b(11);
  my8b.info();

  return 0;
} 

}  // namespace _8bit
