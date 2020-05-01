/*
 * file2.cc
 * 04/30/2020
 * Abed Ahmed
 * asa190005@utdallas.edu
 * 1.0
 * 2020, All Rights Reserved
 * 
 * 
 * file2 for BinaryFileHeader
 * 
 */ 


#include "binaryClass.h"


using namespace std;

void binMatrix(CDKMATRIX* myMatrix,BinaryFileHeader* binaryHeader,ifstream& binaryOpen)
{


   
  stringstream col1;
  string col1s;
  col1 << hex << binaryHeader->magicNumber;
  col1s += col1.str ();

  stringstream col2;
  string col2s;
  col2 << binaryHeader->versionNumber;
  col2s += col2.str();

  stringstream col3;
  string col3s;
  col3 << binaryHeader->numRecords;
  col3s += col3.str();

  setCDKMatrixCell (myMatrix, 1, 1, ("Magic:0x" + col1s).c_str ()); 
  setCDKMatrixCell (myMatrix, 1, 2, ("Version: " +col2s).c_str ());
  setCDKMatrixCell (myMatrix, 1, 3, ("NumRecords: " + col3s).c_str ());

  drawCDKMatrix (myMatrix, true);
 }

