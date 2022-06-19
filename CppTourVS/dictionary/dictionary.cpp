#include "dictionary.h"

bool my_dictionary::MyDictionary::save_to_file() {
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
  if (check_if_exist(new_word.word)) return false;
  // if this is new word
  Data.push_back(new_word);
  return true;
}

bool my_dictionary::MyDictionary::check_if_exist(std::string new_word) {
  for (int i = 0; i < Data.get_size(); i++) {
    if (!Data[i].word.compare(new_word)) return true;
  }
  return false;
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
        std::getline(file, word_node.word, '\n');
        word = "";
      }
      if (std::string("translation:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.translation, '\n');
        word = "";
      }
      if (std::string("category:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.category, '\n');
        word = "";
      }
      if (std::string("examples:").compare(word) == 0) {
        file.get(symbol_buffer);
        std::getline(file, word_node.example, '\n');
        // examples is the last field of word node
        Data.push_back(word_node);
        word = "";
      }
    }
  }
  file.close();
  return true;
}

// MAIN MENU
void my_dictionary::MyDictionary::open_menu() {
  std::vector<std::string> menu_info;
  // to add new case just push back it to menu_info vector;
  menu_info.push_back("_SHOW_DICTIONARY");  // case 0
  menu_info.push_back("_ADD_WORD");         // case 1
  menu_info.push_back("_REMOVE_WORD");      // case 2
  menu_info.push_back("_EDIT_WORD");        // case 3
  menu_info.push_back("_TEST_YOURSELF");    // case 4
  menu_info.push_back("_SAVE");             // case 5
  menu_info.push_back("_SAVE_AND_EXIT");    // case 6
  menu_info.push_back("_EXIT");             // case 7
  bool print_once = true;
  int choice = 0;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  add_to_history("Press 'w' , 's'  to move cursor\nUse 'e' to enter\n");
  while (true) {
    // action menu info
    if (print_once) {
      std::string temp_buffer = menu_info[choice];
      menu_info[choice] =
          std::string(">>> ") + menu_info[choice] + std::string(" <<<");
      for (uint8_t i = 0; i < menu_info.size(); i++) {
        if (i == choice) {
          SetConsoleTextAttribute(hConsole, 13);
          std::cout << menu_info[i] << "\n";
        } else {
          SetConsoleTextAttribute(hConsole, 10);
          std::cout << menu_info[i] << "\n";
        }
      }
      SetConsoleTextAttribute(hConsole, 10);
      menu_info[choice] = temp_buffer;
      print_history();
      print_once = false;
    }

    // main input actions
    switch ((char)_getch()) {
      case 'w':  // key up
      {
        system("cls");
        choice--;
        print_once = true;
        if (choice < 0) choice = menu_info.size() - 1;
        break;
      }

      case 's':  // key right
      {
        system("cls");
        choice++;
        print_once = true;
        if (choice > menu_info.size() - 1) choice = 0;
        break;
      }

      case 'e':  // go to another action
        switch (choice) {
          case 0:  // _SHOW_DICTIONARY
          {
            system("cls");
            SetConsoleTextAttribute(hConsole, 13);
            show_dictionary();
            std::cout << "\n";
            add_to_history("Press 'w' or 's' to exit\n");
            print_history();
          } break;
          case 1:  // _ADD_WORD
          {
            Word new_word;
            add_to_history("Type empty 'w', 's' or '' to get back\n");
            while (true) {
              system("cls");
              std::cout << "ADDING_NEW_WORLD:\n";
              std::cout << "word: ";  // 6,1
              std::cout << "\n\n\n\n";
              print_history();
              change_cursor_xy(6, 1);
              std::getline(std::cin, new_word.word);
              if (!new_word.word.compare("w") || !new_word.word.compare("s") ||
                  !new_word.word.compare("")) {
                goto case_1_end;
              }
              if (check_if_exist(new_word.word)) {
                add_to_history(std::string(
                    "Word: '" + new_word.word +
                    "' alreaddy exist!\nPress 'w' or 's'  to exit\n"));
              } else {
                add_to_history(std::string("Word: '" + new_word.word +
                                           "' was succesfully added!\n"));
                break;
              }
            }
            std::cout << "translation: ";
            setlocale(LC_ALL, "ru");
            SetConsoleCP(1251);
            std::getline(std::cin, new_word.translation);
            setlocale(LC_ALL, "en");
            SetConsoleCP(866);
            std::cout << "category: ";
            std::getline(std::cin, new_word.category);
            std::cout << "example: ";
            std::getline(std::cin, new_word.example);
            save_word(new_word);
          case_1_end:
            system("cls");
            print_once = true;
          } break;
          case 2:  // _REMOVE_WORD
          {
            bool if_succeed = false;
            system("cls");
            std::cout << "_REMOVE_WORD:\n";
            add_to_history("What word you want to remove?\n");
            std::string to_rm;
            std::cout << "word to remove: ";
            std::getline(std::cin, to_rm);
            for (long int i = 0; i < Data.get_size(); i++) {
              if (!Data[i].word.compare(to_rm)) {
                // TO DO: Data.remove(i) cause error code
                Data.remove(i);
                // Data.pop_front();
                if_succeed = true;
              }
            }
            if (if_succeed) {
              add_to_history(
                  std::string("Word: '" + to_rm + "' was removed!\n"));
            } else {
              add_to_history(
                  std::string("Word: '" + to_rm + "' not  exist!\n"));
            }
            system("cls");
            print_once = true;
          } break;
          case 3:  // _EDIT_WORD
          {
            system("cls");
            std::cout << "_EDIT_WORD:\n";
            std::cout << "What word you want to edit:\n";
            std::string to_edit;
            std::getline(std::cin, to_edit);
            for (long int i = 0; i < Data.get_size(); i++) {
              if (!Data[i].word.compare(to_edit)) {
                if (edit_word(i)) {
                  add_to_history("Editing was successfull\n");
                } else {
                  add_to_history("Editing was fialed\n");
                }
                break;
              }
            }
            system("cls");
            print_once = true;
          } break;

          case 4:  // _TEST_YOURSELF
          {
            system("cls");
            std::cout << "_TEST_YOURSELF:\n";

          } break;
          case 5:  // _SAVE
          {
            save_to_file();
            add_to_history(std::string("List of data was saved to file: ") +
                           filename + "\n");
            system("cls");
            print_once = true;
          } break;
          case 6:  // SAVE_AND_EXIT
          {
            save_to_file();
            _exit(1);
          } break;

          case 7:  // _EXIT
          {
            _exit(1);
          } break;

          default:
            break;
        }
        break;

      default:  // default
        break;
    }
  }
}

void my_dictionary::MyDictionary::show_dictionary() {
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
  setlocale(LC_ALL, "en");
}

void my_dictionary::MyDictionary::read() {
  using namespace std;

  // char *data = new char[55];
  string master;
  master.resize(200);
  ifstream file("example.bin", ios::binary | ios::in);
  if (file.is_open()) {
    // file.seekg(0, ios::beg);

    file.read((char *)&master, 64);

    // char *str = (char *)malloc(sizeof(char) * 5);
    // memcpy(&res, data, 55);

    // cout << master.x << " " << pn.y << " " << pn.ch << " " << pn.st;
    file.close();
  }

  std::cout << "\n" << master;

  // delete[] data;
}

void my_dictionary::MyDictionary::test() { open_menu(); }

bool my_dictionary::MyDictionary::edit_word(long int index) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  std::vector<std::string> word_menu;
  word_menu.push_back("_EDIT_WORD");          // case 0
  word_menu.push_back("_EDIT_TRANSLATION");   // case 1
  word_menu.push_back("_EDIT_CATEGORY");      // case 2
  word_menu.push_back("_EDIT_EXAMPLE");       // case 3
  word_menu.push_back("_BACK_TO_MAIN_MENU");  // case 4
  int menu_cursor = 0;
  bool print_once = true;
  bool exit = false;
  while (!exit) {
    if (print_once) {
      system("cls");
      SetConsoleTextAttribute(hConsole, 11);
      std::cout << "Word: '" << Data[index].word << "'\n";
      setlocale(LC_ALL, "ru");
      SetConsoleCP(1251);
      std::cout << "Translation: '" << Data[index].translation << "'\n";
      setlocale(LC_ALL, "en");
      SetConsoleCP(866);
      std::cout << "Category: '" << Data[index].category << "'\n";
      std::cout << "Example: '" << Data[index].example << "'\n";
      SetConsoleTextAttribute(hConsole, 13);
      std::string temp_buffer = word_menu[menu_cursor];
      word_menu[menu_cursor] =
          std::string(">>> ") + word_menu[menu_cursor] + std::string(" <<<");
      for (uint8_t i = 0; i < word_menu.size(); i++) {
        if (i == menu_cursor) {
          SetConsoleTextAttribute(hConsole, 13);
          std::cout << word_menu[i] << "\n";
        } else {
          SetConsoleTextAttribute(hConsole, 10);
          std::cout << word_menu[i] << "\n";
        }
      }
      SetConsoleTextAttribute(hConsole, 10);
      word_menu[menu_cursor] = temp_buffer;
      print_history();
      print_once = false;
    }
    switch ((char)_getch()) {
      case 'w':  // key up
      {
        system("cls");
        menu_cursor--;
        print_once = true;
        if (menu_cursor < 0) menu_cursor = word_menu.size() - 1;
        break;
      }

      case 's':  // key right
      {
        system("cls");
        menu_cursor++;
        print_once = true;
        if (menu_cursor > word_menu.size() - 1) menu_cursor = 0;
        break;
      }

      case 'e':  // go to another action
        switch (menu_cursor) {
          case 0:  // _EDIT_WORD
          {
            bool succes = false;
            add_to_history("Press 's' or 'w' to get back\n");
            while (!succes) {
              system("cls");
              SetConsoleTextAttribute(hConsole, 13);
              std::string new_name;
              std::cout << "Current word: " << Data[index].word;
              std::cout << "\n";
              print_history();
              change_cursor_xy(0, 1);
              std::cout << "Type new word: ";  // 15,0
              // change_cursor_xy(15, 0);
              std::getline(std::cin, new_name);
              if (!new_name.compare("s") || !new_name.compare("w")) {
                goto edit_word_end_case;
              }
              if (check_if_exist(new_name)) {
                add_to_history(std::string("ERROR: '" + new_name +
                                           "' ALREADY EXIST IN DICTIONARY!\n"));
              } else {
                add_to_history(
                    std::string("Word: '" + new_name + "' was edited!\n"));

                Data[index].word = new_name;
              edit_word_end_case:
                print_once = true;
                succes = true;
                system("cls");
              }
            }
          } break;
          case 1:  // _EDIT_TRANSLATION
          {
            system("cls");
            SetConsoleTextAttribute(hConsole, 13);
            std::cout << "Current translation: '" << Data[index].translation
                      << "'\n";
            std::string new_translation;
            std::cout << "Type new translation: ";
            std::getline(std::cin, new_translation);
            Data[index].translation = new_translation;
            system("cls");
            print_once = true;
          } break;
          case 2:  // _EDIT_CATEGORY
          {
            system("cls");
            SetConsoleTextAttribute(hConsole, 13);
            std::cout << "Current class: '" << Data[index].category << "'\n";
            std::string new_class;
            std::cout << "Type new class: ";
            std::getline(std::cin, new_class);
            Data[index].category = new_class;
            system("cls");
            print_once = true;
          } break;
          case 3:  // _EDIT_EXAMPLE
          {
            system("cls");
            SetConsoleTextAttribute(hConsole, 13);
            std::cout << "Current example: '" << Data[index].example << "'\n";
            std::string new_example;
            std::cout << "Type new example: ";
            std::getline(std::cin, new_example);
            Data[index].example = new_example;
            system("cls");
            print_once = true;
          } break;
          case 4:  // _BACK_TO_MAIN_MENU
          {
            return true;
          } break;

          default:
            break;
        }
    }
  }
  return true;
}
void my_dictionary::MyDictionary::print_history() {
  while (history.size() > history_buffer) {
    history.pop_back();
  }
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
  std::cout << "\nHISTORY:\n" << history;
  SetConsoleTextAttribute(hConsole, 13);
}
void my_dictionary::MyDictionary::add_to_history(std::string str) {
  history = str + history;
}
void my_dictionary::MyDictionary::change_cursor_xy(int x, int y) {
  COORD pos = {x, y};
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(output, pos);
}
