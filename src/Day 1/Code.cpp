#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //Variables
    string fileName = "Input.txt";
    string measurementStr = "";
    int measurementCurrent = 0;
    int measurementCompare = 0;
    int amountOfMeasurements = 3;
    int amountOfLines = 0;
    int counterGreater = 0;
    int counterArray = 0;
    ifstream input_file; //Only read

    //Read file content
    input_file.open(fileName);

    if (!input_file.is_open()){
        cerr << "Could not open file '" << fileName << "'" << endl; 
    }
    else {
        cout << "Comparing Values:" << endl; 

        //Count amount of lines in file
        while(getline(input_file,measurementStr)){
            amountOfLines++;
        }
        input_file.clear(); //Reset the stream state
        input_file.seekg(0,ios::beg); //Put cursor in file again at the start

        //Create a dynamic array and store all measurements in it
        int *arrayMeasurements = new int(amountOfLines);
        for(int i=0;i<amountOfLines;i++){
            getline(input_file, measurementStr);
            arrayMeasurements[i] = stoi(measurementStr); //Convert String into Int
            cout << arrayMeasurements[i] << endl;
        }
        
        //Read first sum of measurements
        for(int i=counterArray;i<(amountOfMeasurements+counterArray);i++){
            measurementCurrent = measurementCurrent + arrayMeasurements[i];
        }

        //Read all other measurements
        while (counterArray < (amountOfLines - amountOfMeasurements + 1)){
            measurementCompare = measurementCurrent; //Save previous measurement
            measurementCurrent = 0;
            counterArray++;

            for(int i=counterArray;i<(amountOfMeasurements+counterArray);i++){
                measurementCurrent = measurementCurrent + arrayMeasurements[i];
            }

            if (measurementCurrent > measurementCompare){
                counterGreater++;
                cout << counterArray << ": " << measurementCurrent << " > " << measurementCompare << " Counter: " << counterGreater << endl;
            }
            else{
                cout << counterArray << ": " << measurementCurrent << " <= " << measurementCompare << " Counter: " << counterGreater << endl;
            }
        }
        cout << "Final counter result: " << counterGreater << endl;
        input_file.close();
    }

    return counterGreater;
}
