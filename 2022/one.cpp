#include <iostream> // gestione output 
#include <fstream> // gestione file 
#include <string> // string 

int main() {
    std::string line; // dichiarazione variabile 
    std::ifstream file("small.txt"); // file aperto 
    
    if (file.is_open()) {
        while (getline(file, line)) { // getline legge le linee del file aperto 
            std::cout << line << '\n';
        }
        file.close();
    } else {
        std::cout << "Impossibile aprire il file\n";
    }
    return 0;
}