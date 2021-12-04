#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //FSTREAM (kan tellg, seekg, tellp of seekp gebruiken)
    //IFSTREAM (enkel maar tellg of seekg)
    ifstream file("Test.txt", ios::in);
    if(!file.is_open()){
        cout << "Error";
    }
    else {
        //Geeft positie van cursor in bestand weer (read modus)
        cout << file.tellg() << endl;
        string line;
        //Zet cursor op positie 2 (Read modus)
        file.seekg(2);
        getline(file,line);
        cout << line << endl;
    }

    //OFSTREAM (enkel maar tellp of seekp)
    ofstream file1("Test1.txt", ios::out);
    if(!file1.is_open()){
        cout << "Error";
    }
    else {
        //Geeft positie van cursor in bestand weer (write modus)
        cout << file1.tellp() << endl;
        file1 << "Test";
        cout << file1.tellp() << endl;
        //Zet cursor op positie 2 (Write modus)
        file1.seekp(2); //seekp(2,ios::beg) of seekp(2,ios::end) of seekp(2,ios::cur) om te bepalen van waar er gestart wordt
        file1 << "BlaBlaBla";
        cout << file1.tellp() << endl;
    }

    return 0;
}