#ifndef LIB_HPP
#define LIB_HPP
#include <iostream>


class data{
  public:
  char key[100];
  char value[100];
  data() {}
  data(std::string _key_, std::string _value_);
  void print_info();
};

bool find(std::string filename, std::string _key_);
void create(std::string filename, std::string _key_, std::string _value_);
void read(std::string filename);
void update_value(std::string filename, std::string _key_, std::string _value_);
void del(std::string filename, std::string _key_);
std::string get_value(std::string filename, std::string _key_);


#endif // LIB_HPP
