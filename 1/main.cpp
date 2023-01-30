#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream = newfile;
    newfile.open("input.txt", ios::in); //open file in 'read' mode
    if(newfile.is_open()){ 
        string line;
        while(getline(newfile, line)){
            cout << line << endl;
        }
    }
    //test
    return 0;
}

