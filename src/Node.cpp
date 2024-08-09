#include "../headers/Node.hpp"
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

HuffNode::HuffNode(int weight, char character) {
    this->weight = weight;
    this->character = character;
    this->isLeaf = true;
}

HuffNode::HuffNode(int weight, HuffNode* left, HuffNode* right) {
    this->weight = weight;
    this->left = left;
    this->right = right;
}

int HuffNode::Weight() {
    return this->weight;
}

char HuffNode::Character() {
    return this->character;
}

bool HuffNode::IsLeaf() {
    return this->isLeaf;
}

HuffNode* HuffNode::Left() {
    return this->left;
}

HuffNode* HuffNode::Right() {
    return this->right;
}

bool Compare(HuffNode &a, HuffNode &b) {
    return a.Weight() < b.Weight();
}

void Sort(std::vector<HuffNode> &nodes) {
    std::sort(nodes.begin(), nodes.end(), Compare); 
}

void Tree(std::vector<HuffNode> &nodes) {
    if (nodes.size() > 1) {
        Sort(nodes);

        int sum = nodes[0].Weight() + nodes[1].Weight();
        HuffNode newNode(sum, new HuffNode(nodes[0]), new HuffNode(nodes[1]));
        nodes.push_back(newNode);

        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        Tree(nodes);
    } 
}

void Travel(HuffNode Node, std::map<char, std::string> &table,
        std::string buffer) {
    if (Node.IsLeaf() == false) {
        Travel(*Node.Left(), table, buffer + "0");
        Travel(*Node.Right(), table, buffer + "1");
    }
    else if (Node.IsLeaf() == true) {
        table[Node.Character()] = buffer;
    }
}

