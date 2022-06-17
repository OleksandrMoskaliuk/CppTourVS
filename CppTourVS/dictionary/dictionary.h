#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <iostream>
#include <string>
// for SetConsoleCp( 1251->coding, or back to 866->default) fix for translation
// words
#include <Windows.h>
#include "../_DataStructures/MyList/2WayList.h"
#include <conio.h>

namespace my_dictionary {
// interface:
// push word (string(word), translation() category() usage())
// delete word by name
// delete word by number
// dictionary info
//				words amount
//				print all words
//
// fstream -> writing and reading
//     ifstream -> reading from file
//     ofstreeam -> writing into file
//
//
// for fstream, this moves the file position pointer (both put and get)
// s.seekp(0);

// 1. word: train
//    translation: поїзд
//    category: items
//    usages: ...
// 2. word:
//
// file >> variable // read
// file << variable // write
//

class MyDictionary {
 private:

  struct Word {
    std::string word;
    std::string translation;
    std::string category;
    std::string example;
  };
  my_list::TwoWayList<Word> Data;

  bool load();
  bool save();
  bool save_word(Word new_word);

 public:

  MyDictionary() { load(); }
  ~MyDictionary() { save(); }

  const char* filename = "dctionary.bin";

  void open_menu();
  void show_info();
  void read();
  void test();
 
};  // class MyDictionary

};  // namespace my_dictionary

#endif  // !DICTIONARY_H
