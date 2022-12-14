#ifndef _8BIT_H
#define _8BIT_H

namespace byte {

typedef unsigned char byte;

// (arguments)(logic sentence)?(true):(false);
#define Isbitset(byte, position)                                 \
  (position <= 8) ? (byte & (128 >> (position - 1))) ? (1) : (0) \
                  : (byte)  // and operation

#define UnsetBit(byte, position) \
  (position <= 8) ? (byte & ~(128 >> (position - 1))) : (byte)

#define SetBit(byte, position) \
  (position <= 8) ? (byte | (128 >> (position - 1))) : (byte)  // or operation

#define InvertBit(byte, position)                    \
  (position <= 8) ? (byte & (128 >> (position - 1))) \
                        ? UnsetBit(data, position)   \
                        : SetBit(data, position)     \
                  : (data)
// and
//      1 & 1 = 1
//      1 & 0 = 0
//      0 & 0 = 0
// or
//      1 | 0 = 1
//      1 | 1 = 1
//      0 | 0 = 0

class My8bit {
 private:
  bool data[8] = {};
  byte byte_m = 11;  // 0000 8021
 public:
  My8bit(int number);
  ~My8bit(){};
  void info();
  void set_bit(unsigned char position, bool state);
  byte get_byte();
  int get_dec();
  void test();
};

}  // namespace _8bit

#endif  // !_8BIT_H
