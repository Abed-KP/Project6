/*
 * binaryClass.h
 * 04/30/2020
 * Abed Ahmed
 * asa190005@utdallas.edu
 * 1.0
 * 2020, All Rights Reserved
 * 
 * Provided Binary Class
 */ 

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <sstream>
#include "cdk.h"

#ifndef BINARYCLASS
#define BINARYCLASS

using namespace std;


class BinaryFileHeader
{
public:
 uint32_t magicNumber; /* Should be 0xFEEDFACE */
 uint32_t versionNumber;
 uint64_t numRecords;
};

const int maxRecordStringLength = 25;
class BinaryFileRecord
{
public:
 uint8_t strLength;
 char stringBuffer[maxRecordStringLength];
};

void binMatrix(CDKMATRIX*,BinaryFileHeader*,ifstream&);

#endif


