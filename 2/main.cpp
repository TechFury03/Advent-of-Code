#include <iostream>
#include <fstream>

using namespace std;

int outcome(char, char);

int main(){
    fstream input;
    input.open("input.txt", ios::in | ios::binary);
    if(input.is_open()){
        char kar, played, toBePlayed;
        int totalPoints = 0;
        input.get(kar);
        while(!input.eof()){
            if(kar >= 'A' && kar <= 'C'){
                played = kar;
            } else if(kar >= 'X' && kar <= 'Z'){
                if(kar == 'Y'){ //DRAW
                    toBePlayed = played + ('X'-'A');
                } else if(kar == 'X' && played == 'A'){
                    toBePlayed = 'Z';
                } else if(kar == 'X' && played == 'B'){
                    toBePlayed = 'X';
                } else if(kar == 'X' && played == 'C'){
                    toBePlayed = 'Y';
                } else if(kar == 'Z' && played == 'A'){
                    toBePlayed = 'Y';
                } else if(kar == 'Z' && played == 'B'){
                    toBePlayed = 'Z';
                } else if(kar == 'Z' && played == 'C'){
                    toBePlayed = 'X';
                }
                totalPoints += outcome(played, toBePlayed) + (toBePlayed - 'W');
                cout << totalPoints << endl;
            }
            input.get(kar);
        }
        cout << totalPoints;
    }
    return 0;
}

int outcome(char a, char b){
    if(a == 'A'){ //rock
        switch(b){
            case 'X': //rock
                return 3; //draw
            case 'Y': //paper
                return 6; //win
        }
        return 0;
    }

    if(a == 'B'){ //paper
        switch (b){
            case 'X': //rock
                return 0; //lose
            case 'Y':  //paper
                return 3; //draw
        }
        return 6;
    }

    if(a == 'C'){ //scissors
        switch(b){
            case 'X': //rock
                return 6;
            case 'Y': //paper
                return 0; //lose
        }
        return 3;
    }
}