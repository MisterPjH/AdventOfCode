#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //Variables
    string fileName = "Input.txt";
    string fullStr = "";
    string delimiterStr = " "; //Delimiter between command and position is a space
    int horizontalPos = 0;
    int depth = 0;
    int aim = 0;
    int multipliedValue = 0;
    int amountOfLines = 0;
    size_t position = 0; //Object able to represent size of any object in bytes
    ifstream input_file;

    //Read file content
    input_file.open(fileName);

    if(!input_file.is_open()){
        cerr << "Could not open file '" << fileName << "'" << endl;
    }
    else {
        //Count amount of lines in file
        while(getline(input_file,fullStr)){
            amountOfLines++;
        }
        input_file.clear(); //Reset the stream state
        input_file.seekg(0,ios::beg); //Put cursor in file again at the start

        //Create two dynamic arrays and store all commands and positions in it
        string *arrayCommands = new string[amountOfLines];
        int *arrayPositions = new int(amountOfLines);
        for(int i=0;i<amountOfLines;i++){
            getline(input_file, fullStr);
            position = fullStr.find(delimiterStr); //Find amount of characters until delimiter
            arrayCommands[i] = fullStr.substr(0, position); //Find first substring until delimiter
            arrayPositions[i] = stoi(fullStr.substr(position + delimiterStr.length())); //Find second substring at delimiter position and convert it to integer
        
            if (arrayCommands[i] == "forward"){
                horizontalPos = horizontalPos + arrayPositions[i];
                depth = depth + (aim * arrayPositions[i]);
            }
            else if (arrayCommands[i] == "up"){
                aim = aim - arrayPositions[i];
            }
            else if (arrayCommands[i] == "down"){
                aim = aim + arrayPositions[i];
            }
            else {
                cerr << "Command isn't valid: " << arrayCommands[i] << " (only use 'forward', 'up' or 'down')" << endl;
            }

            cout << "Depth: " << depth << " / Horizontal Position: " << horizontalPos << " / Aim: " << aim << endl;
        }

    multipliedValue = depth * horizontalPos;
    cout << "Multiplied value is: " << depth << " * " << horizontalPos << " = " << multipliedValue << endl;
    }

    return 0;
}