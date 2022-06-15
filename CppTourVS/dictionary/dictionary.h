#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string.h>

#include <fstream>
#include <iostream>
#include "word.h"

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
struct point 
{
  int x = 10;
  int y = 20;
  char ch[10] = {};
  std::string st = "none test";
};
class MyDictionary {
 public:
  MyDictionary() {}
  ~MyDictionary() {}

  void write() {
    std::string str = "Word in binary";
    point pnt;
    pnt.x = 3;
    pnt.y = 4;
    pnt.ch[0] = 'a';
    pnt.ch[1] = 'b';

    std::ofstream file("example.bin", std::ios::out | std::ios::binary);
    if (file.is_open()) {
      int size = str.size();
      std::cout << "size is: " << sizeof(pnt) << "\n";

      char *data = new char[size];

      memcpy(data, &str, size);

      file.write((char *)&pnt, sizeof(pnt));
      delete[] data;
      file.close();
    }
   
    };

    void read() {
      using namespace std;

      //char *data = new char[55];
      string master;    
      master.resize(200);
      point  pn;
      ifstream file("example.bin", ios::binary | ios::in);
      if (file.is_open()) {
        //file.seekg(0, ios::beg);

        file.read((char *)&pn, 64);

       //char *str = (char *)malloc(sizeof(char) * 5);
       //memcpy(&res, data, 55);
        
       cout << pn.x << " " << pn.y << " " << pn.ch << " " << pn.st;
        file.close();

      }
     
    
     
     
      std::cout << "\n" << master;
  
      //delete[] data;
   
    }

    void test() {
      using namespace std; 
    
      this->write();
      this->read();
     

    };

  };  // class MyDictionary

};  // namespace my_dictionary

#endif  // !DICTIONARY_H
