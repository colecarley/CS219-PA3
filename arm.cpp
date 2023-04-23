#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "operators.h"
#include <cctype>
#include <vector>
using namespace std;

enum firstFlags
{
    N,
    Z,
};

vector<string> tokenize(string line);
uint32_t convertToNum(string before, uint32_t *);
void print(string instruction, bool flagUpdate, uint32_t *registers, bool *flags);

int main()
{
    map<string, uint32_t (*)(uint32_t, uint32_t, bool *)> OPERATORS;
    OPERATORS["ADD"] = ADD;
    OPERATORS["AND"] = AND;
    OPERATORS["SUB"] = SUB;
    OPERATORS["ASR"] = ASR;
    OPERATORS["LSL"] = LSL;
    OPERATORS["LSR"] = LSR;
    OPERATORS["NOT"] = NOT;
    OPERATORS["ORR"] = ORR;
    OPERATORS["XOR"] = XOR;
    OPERATORS["MOV"] = MOV;
    OPERATORS["CMP"] = SUB;
    OPERATORS["TST"] = ADD;

    uint32_t registers[12];
    bool flags[4] = {0, 0, 0, 0};
    string fileName = "input.txt";
    ifstream reader;
    reader.open(fileName);

    string temp;
    uint32_t operand1, operand2;
    while (getline(reader, temp))
    {
        vector<string> tokens = tokenize(temp);
        operand1 = convertToNum(tokens[2], registers);
        if (tokens.size() > 3)
        {
            operand2 = convertToNum(tokens[3], registers);
        }

        uint32_t output = OPERATORS[tokens[0].substr(0, 3)](operand1, operand2, flags);

        bool flagUpdate = (tokens[0].substr(0, 3) == "CMP" || tokens[0].substr(0, 3) == "TST" || tokens[0].length() == 4);
        if (flagUpdate)
        {
            signed int signedOutput = output;
            flags[0] = signedOutput < 0;
            flags[1] = output == 0;
        }

        if (tokens[0].substr(0, 3) != "CMP" && tokens[0].substr(0, 3) != "TST")
        {
            registers[int(tokens[1][1]) - 48] = output;
        }

        print(temp, flagUpdate, registers, flags);
    }

    return 0;
}

vector<string> tokenize(string line)
{
    vector<string> tokens;
    stringstream ss(line);
    string temp;
    while (getline(ss, temp, ' '))
    {
        tokens.push_back(temp);
    }

    for (int i = 0; i < tokens[0].length(); i++)
    {
        tokens[0][i] = toupper(tokens[0][i]);
    }

    return tokens;
}

uint32_t convertToNum(string before, uint32_t *registers)
{
    if (toupper(before[0]) == 'R')
    {
        return registers[int(before[1]) - 48];
    }
    return stoul(before.substr(1, before.length() - 1), nullptr, 16);
}

void print(string instruction, bool flagUpdate, uint32_t *registers, bool *flags)
{
    cout << instruction << endl;
    cout << "R0: 0x" << hex << registers[0] << "\t"
         << "R1: Ox" << hex << registers[1] << "\t"
         << "R2: Ox" << hex << registers[2] << "\t"
         << "R3: Ox" << hex << registers[3] << endl
         << "R4: Ox" << hex << registers[4] << "\t"
         << "R5: Ox" << hex << registers[5] << "\t"
         << "R6: Ox" << hex << registers[6] << "\t"
         << "R7: Ox" << hex << registers[7] << endl;

    cout << "N = " << flags[0] << "\tZ = " << flags[1] << "\tC = " << flags[2] << "\tV = " << flags[3] << endl;
}
