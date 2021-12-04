#include <iostream>
#include <fstream>

using namespace std;

int main(){
fstream file;
// File kan geopend worden om te lezen (in), om te schrijven (out) en
// file wordt aangemaakt indien deze niet aanwezig is + indien hij al bestaat overschreven (trunc)
file.open("Test.txt", ios::in | ios::out | ios::trunc);

if (!file.is_open()){
cout << "File could not be opened";
}
else {
    //Read or write
    cout << "File Opened succesfully";
    file.close();
}

    return 0;
}