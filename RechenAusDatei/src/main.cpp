#include <iostream>
#include <fstream>
#include "../header/calculator.hpp"
#include <sstream>

void ausgabe(std::string rechenart, int wert1,int wert2, std::ofstream& output){
    if (rechenart=="addition") {
        int ergebniss = rechenarten::addition(wert1, wert2) ;
        output << wert1 << " + " << wert2 << " = " << ergebniss << std::endl;
    }

    else if (rechenart=="subtraktion") {
        int ergebniss = rechenarten::subtraktion(wert1, wert2);
        output << wert1 << " - " << wert2 << " = " << ergebniss << std::endl;
    }

    else if (rechenart=="multiplikation") {
        int ergebniss = rechenarten::multiplikation(wert1, wert2);
        output << wert1 << " * " << wert2 << " = " << ergebniss << std::endl;
    }

    else if (rechenart=="division") {
        int ergebniss = rechenarten::division(wert1, wert2);
        output << wert1 << " / " << wert2 << " = " << ergebniss << std::endl;
    }

    else{
        output << "Unglütige rechenart: " <<rechenart<< std::endl;
    }
}


void verarbeiteZeile(const std::string& line, std::ofstream& output ) {

    std::istringstream ss(line);
    std::string rechenart;
    int wert1, wert2;
    if (std::getline(ss, rechenart, ';') && ss >> wert1 && ss.ignore() && ss >> wert2) {
        ausgabe(rechenart, wert1, wert2,output);
    }

    else{
        if (line =="") {
            output << " " << std::endl;
        }
        else{
            output << "Ungültige Eingabe: " << line << std::endl;
        }
    }
}



void allesEinlesen(std::ifstream& input, std::ofstream& output) {
    if (input.is_open()&&output.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            verarbeiteZeile(line,output);		
        }
    } else {
        std::cout << "Fehler beim Öffnen der Dateien" << std::endl;
    }
}

int main(){
    std::string output_file_path ="data/value_results.dat";
    std::string input_file_path ="data/values.dat";
    std::ifstream input_file(input_file_path);
    std::ofstream output_file(output_file_path);
    
    allesEinlesen(input_file,output_file);
    return 0;
}



