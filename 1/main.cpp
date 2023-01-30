#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream newfile;
    newfile.open("input.txt", ios::in); //open file in 'read' mode
    if(newfile.is_open()){ 
        string line;
        int one = 0;
        int two = 0;
        int three = 0;

        while(getline(newfile, line)){
            int elf = 0; //total amount per elf
            while(line != ""){
                elf += stoi(line);
                getline(newfile, line);
            }
            if(elf > one){
                three = two;
                two = one;
                one = elf;
            } else if(elf > two){
                three = two;
                two = elf;
            } else if(elf > three){
                three = elf;
            }
            cout << one << "  |  " << two << "  |  " << three << "  |  " << endl;
        }
        cout << one << endl;
        cout << two << endl;
        cout << three << endl;
        cout << one + two + three;
    }
    //test
    return 0;
}

