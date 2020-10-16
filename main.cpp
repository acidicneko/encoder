#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

//global variables used acroos functions
string file, cur_dir, subject;

//help function so that I DRY
void help(){
    cout << "Marks Organiser 0.9 Beta\n--------------\ninit = Initialise the current directory\n--------------\ncommit \"FILENAME\"= make a new record with the given filename to store data\n--------------\nset \"FILENAME\" = make the given file default to store data\n--------------\npush \"SUBJECT\" \"GRADES\" = record the given subject with given marks or grades\n--------------\nMade by Ayush Yadav\n";
}

//parser for variable checking of files
int parser(string line){
    string tok, str;
    bool start = false;
    bool file_var = false;
    bool dirVar = false;
    for(int i = 0; i<line.length(); i++){
        tok += line[i];//read char by char
        if(tok == "dir="){
            tok = "";
            dirVar = true;
        }
        else if(tok == "def_file="){
            tok = "";
            file_var = true;
        }
        else if(tok == subject + "="){
            tok = "";
            return 1;
        }
        else if(tok == "\""){
            if(start == false){
                start = true;
                tok = "";
            }
            else{
                start = false;
                if(file_var == true){
                    file = str;
                    str = "";
                }
                else if(dirVar == true){
                    cur_dir = str;
                    str = "";
                }
            }
        }
        else if(start == true){
            str += tok;
            tok = "";
        }
    }
    return 0;
}

int main(int argc, char **argv){
    ofstream obj;
    ifstream check;
    ofstream outfile;
    string filenm;
    string arg;
    bool dirInit = true;

    //init file checking that is .marko_init
    ifstream initFile;
    initFile.open(".marko_init");
    //parsing file with function above to check for variables
    while(getline(initFile, arg)){
        parser(arg);
    }
    initFile.close();
    arg = "";//emptying the string

    //checking if the provided .marko.init is real
    initFile.open(".marko_init");
    if(!initFile || cur_dir != get_current_dir_name()){
        dirInit = false;
        initFile.close();
    }

    //making token for comparison
    if(argc > 1){
        arg = argv[1];
    }
    //initialising the current dir
    if(arg == "init"){
        check.open(".marko_init");
        //checking if dirctory has been already initialised
        if(check){
            cout << "directory already initialised by marko!\n";
            dirInit = true;
            return 1;//if yes then close with error
        }
        //else initialise the dir
        obj.open(".marko_init");
        obj << "dir=\"" << get_current_dir_name() << "\"\n";
        cout << "directory initialised\n";
        dirInit = true;
        obj.close();
        check.close();
    }
    //make new records
    else if(arg == "commit" && dirInit == true){
        check.open(argv[2]);
        //if record exists then give error
        if(check){
            cout << "record \"" << argv[2] << "\" already exists" << endl;
            return 1;
        }
        //else make the record
        obj.open(argv[2]);
        cout << "record saved with name: " << argv[2] << endl;
        obj.close();
        check.close();
    }
    //set default record to save your marks in
    else if(arg == "set" && dirInit == true){
        if(argc > 2){
            filenm = argv[2];
        }
        //check if given file exists
        check.open(filenm);
        if(!check){
            cout << "no such record saved with name \"" << filenm << "\"\n";
            check.close();
            return 1;//if not then exit with error
        }
        //register the default file to .marko_init
        outfile.open(".marko_init", std::ios_base::app);
        outfile << "def_file=\"" << filenm << "\"" << endl;
        cout << "default record set to " << filenm << endl;
    }
    //recording to default records
    else if(arg == "push" && dirInit == true){
        string grade;
        int isPresent = 0;
        //if subject is provided to program
        if(argc > 2){
            subject = argv[2];
            //if grades are provided to program
            if(argc > 3){
                //no default record found
                if(file == ""){
                    cout << "please set a default record to save marks in\n";
                    return 1;
                }

                //know if subject has been already recorded
                ifstream defFile(file);
                string content;
                while(getline(defFile, content)){
                    isPresent = parser(content);
                }
                if(isPresent == 1){
                    cout << "subject with that name already pushed to record!\n";
                    return 1;//exit the program with error code
                }

                //if not found record it to default record
                grade = argv[3];
                outfile.open(file, std::ios_base::app);
                outfile << subject << "=\"" << grade << "\"\n";
                cout << "Subject: " << subject << " && Grades: " << grade << endl;
            }
            //grades not given to program
            else{
                cout << "please enter valid grades\n";
            }
        }
        //subject not given to program
        else{
            cout << "please enter a valid subject name\n";
        }
    }
    else if(arg == "help"){
        help();
    }
    else if(argc == 1){
        cout << "type \"help\" for a list of basic commands\n";
    }
    else if(arg == "--version"){
        cout << "Marks Organiser Beta 0.9\nMade by Ayush Yadav\n";
    }
    else if(dirInit == false){
        cout << "please initialise the directory first!\n";
    }
    else{
        cout << "no such operation supported!\n";
    }
    return 0;
}
