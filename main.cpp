#include <iostream>
#include <fstream>
#include <unistd.h>
#include "lib.hpp"
#include <stdarg.h>

std::string ver = "ENCODER (enc) 1.0.2-beta\nCopyright (C) 2020 Ayush Yadav.\nThis is free software; There is no warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";

std::string def_file = "";

int exist(std::string filename);
void msg(std::string text);
void help();
void error(std::string text);
void create_file(std::string filename);
int bootstrap();


int main(int argc, char *argv[]) {

  std::string arg;

  if(argc > 1)
    arg = argv[1];

  if(argc == 1){
    help();
  }

  else if(arg == "--version"){
    std::cout << ver;
  }

  else if(arg == "init"){
    if(exist(".enc.dat")){
      error("directory already initialised!!");
      return 1;
    }
    create(".enc.dat", "dir", get_current_dir_name());
    msg("directory initialised");
  }


  else if(bootstrap() == 1)
    return 1;


  else if(arg == "commit"){
    if(argc > 2){
      if(exist(argv[2])){
        error("file already exists!!");
        return 1;
      }
      create_file(argv[2]);
      msg("file created");
    }
    else{
      error("please provide valid filename!!");
      return 1;
    }
  }

  else if(arg == "set"){
    if(argc > 2){
      if(!exist(argv[2])){
        error("given file doesn't exists!!");
        return 1;
      }
      create(".enc.dat", "def_file", argv[2]);
      msg("default file set");
    }
    else{
      error("please provide a valid filename!!");
      return 1;
    }
  }


  else if(arg == "help"){
    help();
  }

  else if(arg == "read"){
    if(argc > 2){
      if(!exist(argv[2])){
        error("given file doesn't exists!!");
        return 1;
      }
      read(argv[2]);
    }
    else {
      error("please provide a valid filename!!");
    }
  }

  else if(arg == "push"){
    if(!exist(def_file) || def_file == ""){
      error("default file not set!!");
      return 1;
    }

    if(argc > 3){
      create(def_file, argv[2], argv[3]);
      msg("data recorded");
    }
    else if(argc == 2){
      error("please provide a valid key and value!!");
      return 1;
    }
    else if(argc == 3){
      error("please provide a valid value!!");
      return 1;
    }
  }

  else if(arg == "pull"){
    if(exist(".enc.dat")){
      def_file = get_value(".enc.dat", "def_file");
      if(!exist(def_file) || def_file == ""){
        error("default file not set!!");
        return 1;
      }
    }


    if(argc > 2){
      del(def_file, argv[2]);
      msg("data deleted");
    }
    else if(argc == 2){
      error("please provide a valid key to delete!!");
      return 1;
    }
  }

  else{
    error("unknown command line argument!!");
  }
  return 0;
}



int exist(std::string filename){
  std::ifstream obj;
  obj.open(filename);
  if(obj){
    obj.close();
    return 1;
  }
  obj.close();
  return 0;
}

void msg(std::string text){
  std::cout << "\033[32menc: \033[0m" << text << std::endl;
}

void create_file(std::string filename){
  std::ofstream obj;
  obj.open(filename);
  obj.close();
}

void error(std::string text){
  std::cout << "\033[31;1menc: \033[0m" << text << std::endl;
}

void help(){
  std::cout << "NAME\n\tenc - ENCODER\n\nSYNOPSIS\n\tenc [option] [arguments]\n\nDESCRIPTION\n\tEncoder is a data recorder program mainly developed for recording marks in academics.\n\tIt can be used for anything, not just academic uses!\n\nOPTIONS\n\tinit\tInitialises the current directory for data recording.\n\tcommit [FILENAME]\tCreate new files for data recording.\n\t NOTE-> It is necessary to create databases with this option! Files created by other means may not be compatible with ENCODER!\n\tset [FILENAME]\tSet a default file to record data in.\n\tpush [KEY] [VALUE]\tRecord the given KEY and VALUE to default file set.\n\tread [FILENAME]\tRead the given file.\n\tNOTE-> The given file must be read from read option! Any other means of reading may not work and may even corrupt the file!\n";
}

int bootstrap(){
  if(!exist(".enc.dat")){
    error("please initialise the directory first!!");
    return 1;
  }
  else if(get_value(".enc.dat", "dir") != get_current_dir_name()){
      error("please initialise the directory first!!\nprovided .marko.dat isn't real!!");
      return 1;
  }

  else if(get_value(".enc.dat", "def_file") != ""){
    def_file = get_value(".enc.dat", "def_file");
    return 0;
  }
  return 0;
}
