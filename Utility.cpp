#include "Utility.h"


void allUpper(string& string) {
    for (size_t i = 0; i < string.size(); i++) {
        string[i] = toupper(string[i]);     //! Iterates over each character from a string and changes it to uppercase
    }
}