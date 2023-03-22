#include "byte.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

namespace byte {

My8bit::My8bit() { byte_m = 0; }

My8bit::My8bit(int number) {
  if (number > 255) {
    std::cout
        << "ERROR: Number larger then cell, data partition will be lost\n";
  }
  for (uint8_t i = 1; i <= 8; i++) {
    if (Isbitset((byte)number, i)) {
      byte_m = SetBit(byte_m, i);
    }
  }
}

void My8bit::info() {
  std::cout << "dec: " << get_dec() << "\n";
  std::cout << "8bit: ";
  for (int i = 1; i <= 8; i++) {
    if (Isbitset(byte_m, i)) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
  }
  std::cout << "\n";
}

void My8bit::set_bit(unsigned char position) {
  if (position < 1 && position > 8) {
    std::cout << "ERROR wrong set bit position\n";
    return;
  }
  byte_m = SetBit(byte_m, position);
}

void My8bit::unset_bit(unsigned char position) {
  if (position < 1 && position > 8) {
    std::cout << "ERROR wrong set bit position\n";
    return;
  }
  byte_m = UnsetBit(byte_m, position);
}

void My8bit::reset_data() { byte_m = 0; }

bool My8bit::get_bit(unsigned char position) {
  return Isbitset(byte_m, position);
}

byte My8bit::get_byte() { return byte_m; }

int My8bit::get_dec() {
  int result = 0;
  int pow_index = 7;
  for (int i = 1; i <= 8; ++i) {
    if (Isbitset(byte_m, i)) {
      result += std::pow(2, pow_index);
    }
    --pow_index;
  }
  return result;
}

}  // namespace byte
