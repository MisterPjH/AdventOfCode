#include <iostream>
#include <fstream>
#include "string" //nodig voor getline()

using namespace std;

int main(){
ifstream file;
file.open("Test.txt");

if(!file.is_open()){
    cout << "File could not be opened";
}
else {
    string line;
    cout << "The file contains following content:" << endl;
    //Lees alle lijnen in van file, totdat "error"-bit getriggerd wordt
    while(file.good()){
    getline(file,line);   
    cout << line << endl;
    }
}

    return 0;
}