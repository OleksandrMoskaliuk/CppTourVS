#ifndef _8BIT_H
#define _8BIT_H

#include <stdio.h>
#include <math.h>
#include <iostream>

namespace _8bit {

//(arguments)(logic sentence)?(true):(false);
#define Isbitset(data, position)                                 \
  (position <= 8) ? (data & (128 >> (position - 1))) ? (1) : (0) \
                  : (data)  // and operation

#define UnsetBit(data, position) \
  (position <= 8) ? (data & ~(128 >> (position - 1))) : (data)

#define SetBit(data, position) \
  (position <= 8) ? (data | (128 >> (position - 1))) : (data)  // or operation

#define InvertBit(data, position)                    \
  (position <= 8) ? (data & (128 >> (position - 1))) \
                        ? UnsetBit(data, position)   \
                        : SetBit(data, position)     \
                  : (data)
//and
//     1 & 1 = 1
//     1 & 0 = 0
//     0 & 0 = 0 
//or
//     1 | 0 = 1
//     1 | 1 = 1
//     0 | 0 = 0

class My8bit {
 public:
  My8bit(int number);
  ~My8bit(){};
  void info();
  void set_bit(uint16_t position, bool state);
 private:
  uint16_t  f8bit_to_dec();
  typedef unsigned char byte;
  bool data[8] = {};
  byte Dat = 11;  // 0000 8021
};

int entry_point();

}  // namespace _8bit

#endif  // !_8BIT_H
