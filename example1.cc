/*
 * example1.cc
 * 04/30/2020
 * Abed Ahmed
 * asa190005@utdallas.edu
 * 1.0
 * 2020, All Rights Reserved
 * 
 * 
 * main file for matrix size
 * 
 */ 

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <sstream>
#include "cdk.h"


#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

const int maxRecordStringLength = 25;

class BinaryFileHeader
{
public:

  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;

};

class BinaryFileRecord
{
public:

  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

using namespace std;

int main()
{

  WINDOW          *window;
  CDKSCREEN	  *cdkscreen;
  CDKMATRIX       *myMatrix;           // CDK Screen Matrix

  BinaryFileHeader* binaryHeader = new BinaryFileHeader ();

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"0", "a", "b", "c","d","e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED, vMIXED, vMIXED};

  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  drawCDKMatrix(myMatrix, true);

 ifstream binaryOpen("/scratch/perkins/cs3377.bin", ios::in | ios::binary);
 if (binaryOpen.is_open())
{

 binaryOpen.read ((char *) binaryHeader, sizeof (BinaryFileHeader));
   
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
   
  drawCDKMatrix (myMatrix, true);

  unsigned char x;
  cin >> x;
  binaryOpen.close ();
  endCDK ();
}
