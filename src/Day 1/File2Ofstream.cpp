#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //File wordt overschreven + indien file niet bestaat, aangemaakt
    //ofstream zal standaard out + trunc commando uitvoeren
    ofstream file("Test.txt");

    if (!file.is_open()){
        cout << "File could not be opened";
    }
    else { 
        file << "Title" << endl;
        file << "SubTitle" << endl;
        file << "End" << endl;
        file.close();
        cout << "File is succesfully written";
    }

    return 0;
}