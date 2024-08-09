#ifndef CRYPTION
#define CRYPTION
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

void Encode(string fname, map<char, string> codes, string output_file);
void Decode(string fname, string output_file);

#endif
