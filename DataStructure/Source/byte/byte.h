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
// 11  // 0000 8021

class My8bit {
 private:
  byte byte_m = 0;
 public:
  My8bit();
  My8bit(int number);
  ~My8bit(){};
  /* Usefull info */
  void info();
  /* Set bit position from 1...8 */
  void set_bit(unsigned char position);
  /* Unset bit position from 1..8 */
  void unset_bit(unsigned char position);
  /* Set all bits to zeto value */
  void reset_data();
  /* Get specific bit from 1...8 */
  bool get_bit(unsigned char position);
  /* Get raw byte data */
  byte get_byte();
  /* Convert byte to dec value*/
  int get_dec();
};

}  // namespace _8bit

#endif  // !_8BIT_H
