#ifndef NODE
#define NODE
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

class HuffNode {
    private:
        HuffNode* left;
        HuffNode* right;
        int weight;
        char character;
        bool isLeaf = false;
        
    public:
        HuffNode(int weight, char character);
        HuffNode(int weight, HuffNode* left, HuffNode* right);

        int Weight(); 
        char Character();
        bool IsLeaf();
        HuffNode* Left();
        HuffNode* Right();
};

bool Compare(HuffNode &a, HuffNode &b);
void Sort(std::vector<HuffNode> &nodes);
void Tree(std::vector<HuffNode> &nodes);
void Travel(HuffNode Main, std::map<char, std::string> &table, std::string buffer = "");

#endif 
