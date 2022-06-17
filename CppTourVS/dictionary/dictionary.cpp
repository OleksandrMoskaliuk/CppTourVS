#include "dictionary.h"


bool my_dictionary::MyDictionary::save() {
  //
  std::ofstream s(filename, std::ios::binary | std::ios::trunc | std::ios::out);
  if (!s.is_open()) {
    std::cout << "failed to open" << filename << '\n';
    return false;
  } else {
    s.seekp(0);
    for (int i = 0; i < Data.get_size(); i++) {
      int index2 = 0;
      s << i << '.' << "\n";
      s << i << '.' << index2++ << " word: " << Data[i].word << "\n";
      s << i << '.' << index2++ << " translation: ";
      SetConsoleCP(1251);
      s << Data[i].translation;
      SetConsoleCP(866);
      s << "\n"
        << i << '.' << index2++ << " category: " << Data[i].category << "\n";
      s << i << '.' << index2 << " examples: " << Data[i].example << "\n";
    }
  }
  s.close();
  return true;
}

bool my_dictionary::MyDictionary::save_word(Word new_word) {
  // check if word is not in data
  for (int i = 0; i < Data.get_size(); i++) {
    if (Data[i].word.compare(new_word.word)) return false;
  }
  // if this is new word
  Data.push_back(new_word);
  return true;
}

bool my_dictionary::MyDictionary::load() {
  std::ifstream file(filename, std::ios::in, std::ios::binary);
  if (!file.is_open()) {
    std::cout << "failed to open" << filename << '\n';
    return false;
  } else {
    file.seekg(0);
    char symbol_buffer = ' ';
    std::string word = "";
    Word word_node;
    while (file.get(symbol_buffer)) {
      word += symbol_buffer;

      // std::cout << (int)symbol_buffer << std::endl;
      if ((int)symbol_buffer == 32) word = "";
      if (std::string("word:").compare(word) == 0) {
        // removes redunant space
        file.get(symbol_buffer);
        std::getline(file, word_node.word);
        word = "";
      }
      if (std::string("translation:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.translation);
        word = "";
      }
      if (std::string("category:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.category);
        word = "";
      }
      if (std::string("examples:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.example);
        Data.push_back(word_node);
        word = "";
      }
    }
  }
  file.close();
  return true;
}

void my_dictionary::MyDictionary::open_menu() 
{
  int cursor = 0;
  while (cursor != 9) {
    std::cout << ">>> YOUR DICTIONARY\n"
              << ">>> 1. Show dictionary\n"
              << ">>> 2. Add word\n"
              << ">>> 3. Remove word\n"
              << ">>> 4. Edit word\n"
              << ">>> 9. Close\n";

    std::cin >> cursor;
    switch (cursor) {
      case 1: {
        system("cls");

        show_info();
        break;
      }
      case 9: {
        exit(1);
        break;
      }
      default:
        break;
    }
     
    
  }
  
  
}

void my_dictionary::MyDictionary::show_info() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 13);
  setlocale(LC_ALL, "ru");
  std::cout << ">>>" << std::endl;
  for (int i = 0; i < Data.get_size(); i++) {
    // SetConsoleTextAttribute(hConsole, 1 ... 255);
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "   word: " << Data[i].word << std::endl;
    SetConsoleCP(1251);
    std::cout << "   translation: " << Data[i].translation << std::endl;
    SetConsoleCP(866);
    std::cout << "   categoty: " << Data[i].category << std::endl;
    std::cout << "   example: " << Data[i].example << std::endl;
    SetConsoleTextAttribute(hConsole, 13);
    std::cout << ">>>" << std::endl;
  }
  SetConsoleTextAttribute(hConsole, 13);
}

void my_dictionary::MyDictionary::read() {
  using namespace std;

  // char *data = new char[55];
  string master;
  master.resize(200);
  ifstream file("example.bin", ios::binary | ios::in);
  if (file.is_open()) {
    // file.seekg(0, ios::beg);

    file.read((char*)&master, 64);

    // char *str = (char *)malloc(sizeof(char) * 5);
    // memcpy(&res, data, 55);

    // cout << master.x << " " << pn.y << " " << pn.ch << " " << pn.st;
    file.close();
  }

  std::cout << "\n" << master;

  // delete[] data;
}

void my_dictionary::MyDictionary::test() {
  open_menu();
};

