#include <cstddef>
#include <ios>
#include <map>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../headers/Node.hpp"
#include "../headers/Cryption.hpp"

using namespace std;

int main (int argc, char *argv[]) {

    if (argc > 3 && argc < 3) {
        cout << "Please use the correct format: ./huffman -(e,d) <file_path>" << endl;
        return 1;        
    }

    if (argv[1][0] != '-') {
        cout << "Please use the correct format: ./huffman -(e,d) <file_path>" << endl;
        return 1; 
    }

    if (string(argv[1]) == "-e" || string(argv[1]) == "-d"){
        if (string(argv[1]) == "-e") {
            string file_path = argv[2];
            
            fstream file(file_path);
            if (!file) {
                std::cerr << "Unable to open file";
                return 1;
            }

            map<char, int> table_b;
            char ch;
            while(file.get(ch)) {
                if (!table_b[ch]) {
                    table_b[ch] = 1;
                } 
                else if (table_b[ch]) {
                    table_b[ch]++;
                }
            }

            vector<HuffNode> nodes;
            map<char, string> table_a;
            for (const auto& pair: table_b) {
                nodes.push_back(HuffNode(pair.second, pair.first));
            }

            Tree(nodes);
            Travel(nodes[0], table_a);
            Encode(file_path, table_a, file_path + ".ym");

            cout << "Encoded file: " << file_path + ".ym" << endl;
        }

        if (string(argv[1]) == "-d") {
            string file_path = argv[2];
            Decode(file_path, file_path.substr(0, file_path.length() - 3));

            cout << "Decoded file: " << file_path.substr(0, file_path.length() - 3) << endl;
        }
    }

    return 0;
}
