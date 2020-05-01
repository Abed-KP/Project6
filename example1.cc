/*
 * example1.cc
 * 04/30/2020
 * Abed Ahmed
 * asa190005@utdallas.edu
 * 1.0
 * 2020, All Rights Reserved
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
#include "binaryClass.h"


#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{

  WINDOW      *window;
  CDKSCREEN   *cdkscreen;
  CDKMATRIX   *myMatrix;           // CDK Screen Matrix

BinaryFileHeader* binaryHeader = new BinaryFileHeader ();
BinaryFileRecord* binaryRecord = new BinaryFileRecord (); 

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
{
   binaryOpen.read ((char *) binaryHeader, sizeof (BinaryFileHeader));
   
  
  binMatrix(myMatrix,binaryHeader,binaryOpen);
  
  int i = 2;
   
  while (binaryOpen.read ((char *) binaryRecord, sizeof (BinaryFileRecord))
	 && i <= 5)
    {
      stringstream ss;
      string s; 
      stringstream col1;
      string col1s;
      
      ss << (int)binaryRecord->strLength;
      s += ss.str ();
      
      col1 << binaryRecord->stringBuffer;
      col1s += col1.str ();


      setCDKMatrixCell (myMatrix, i, 1, ("strlen: " + s).c_str ());
      setCDKMatrixCell (myMatrix, i, 2, col1s.c_str ());
      i++;
    }

}
  

 }

  drawCDKMatrix (myMatrix, true);
  unsigned char x;
  cin >> x;
  binaryOpen.close ();
  endCDK ();
}



