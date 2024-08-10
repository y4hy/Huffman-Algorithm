#include "../headers/Cryption.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void Encode(string fname, map<char, string> codes, string output_file) {
    fstream file(fname);
    if (!file) {
        std::cerr << "Unable to open file";
        return;
    }

    fstream output(output_file, ios::out);
    if (!output) {
        std::cerr << "Unable to open file";
        return;
    }

    for (auto it = codes.begin(); it != codes.end(); it++) {
        output << it->first << " " << it->second << "\n";
    }

    output << "<end>" << "\n";

    string buffer = "";
    char c;
    while (file.get(c)) {
        buffer += codes[c];
        while (buffer.length() >= 8) {
            char byte = 0;
            for (int i = 0; i < 8; i++) {
                byte = byte << 1;
                if (buffer[i] == '1') {
                    byte |= 1;
                }
            }
            output.put(byte);
            buffer = buffer.substr(8);
        }
    }

    file.close();
    output.close();
}

void Decode(string fname, string output_file){
    fstream file(fname);
    if (!file) {
        std::cerr << "Unable to open file";
        return;
    }

    fstream output(output_file, std::ios::app); 
    if (!output) {
        std::cerr << "Unable to open file";
        return;
    }

    map<string, char> codes;
    string line = ""; 
    while (getline(file, line)) {
        if (line == "<end>") {
            break;
        }

        if (line == "") {
            getline(file, line);
            codes[line.substr(1)] = '\n';
        }
        
        codes[line.substr(2)] = line[0];
    }

    string buffer = "";
    char c;
    while (file.get(c)) {
        for (int i = 0; i < 8; i++) {
            buffer += (c & 0x80) ? "1" : "0";
            c = c << 1;
        }

        for (auto it = codes.begin(); it != codes.end(); it++) {
            if (buffer.find(it->first) == 0) {
                output.put(it->second);
                buffer = buffer.substr(it->first.length());
            }
        }
    }

    file.close();
    output.close();
}
