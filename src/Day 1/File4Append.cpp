#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    // File kan geopend worden om te lezen (in), om te schrijven (out) en
    // file wordt aangemaakt indien deze niet aanwezig is + indien hij al bestaat wordt nieuwe inhoud onderaan toegevoegd (append)
    fstream file("Test.txt", ios::in | ios::out | ios::app);
    if (!file.is_open()){
        cout << "File could not be opened" << endl;
    }
    else {
        cout << "File opened succesfully" << endl;
        cout << "Writing to the file" << endl;
        file << "Dit is een lijn" << endl;

        file.seekg(0); //zet cursor terug bij start in file
        cout << "Reading from to the file" << endl;
        string line;
        while (file.good()){
            getline(file, line);
            cout << line << endl;
        }
    }
    
    return 0;
}