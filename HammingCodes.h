//
// Created by saad on 18/04/2020.
//

#ifndef HAMMINGALGO_HAMMINGCODES_H
#define HAMMINGALGO_HAMMINGCODES_H

#include <fstream>
#include <bitset>
#include <random>
#include <sstream>
#include <time.h>
void EncodeHamming(bool *message, bool(&codeword)[12]);
int * FindSyndrome(bool *codeword);
void TranslateToHamming(std::string originalFile, std::string newFile);
void DecodeHamming(int *syndrome, bool *codeword, bool *decodedMessage);
char BoolWordToByte(bool *message);
#endif //HAMMINGALGO_HAMMINGCODES_H
