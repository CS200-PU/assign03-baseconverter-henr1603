//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        09/14/2024
// Class:       CS200- AaJanae Henry
// Assignment:  Base Converter
// Purpose:     Convert numbers entered by users to a decimal, binary, or
//              hexadecimal
// Hours:       
//******************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int TWO = 2;
//default fucntions 

int hexCharToInt (char hexDigit);
char intToHexChar (int intConvert);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

/***********************************************************************
Function:     main

Description:  Convert numbers entered by users to a decimal, binary, or
              hexadecimal 

Parameters:   None

Returned:     return status
***********************************************************************/

int main () {

  const string myTitle = "*****HEX-DECIMAL-BINARY CONVERTER*****";

  
  
  return EXIT_SUCCESS;
}

/***********************************************************************
Function:     hexCharToInt

Description:  Converting a hex char to an integer 

Parameters:   hexDigit - the hex char passed in from user

Returned:     int - the integer that was the end of conversion 
***********************************************************************/

int hexCharToInt (char hexDigit) {
  int ten = 10;

  if (hexDigit >= 0 && hexDigit <= 9) {
    return hexDigit - 0;
  }

  if (hexDigit >= 'A' && hexDigit <= 'F') {
    return hexDigit - 'A' + ten;
  }

  else {
    return -1;
  }

}

/***********************************************************************
Function:     intToHexchar

Description:  Converting an integer to a hex char

Parameters:   intConvert - the int passed in to be converted 

Returned:     char - the char that was converted
***********************************************************************/
char intToHexChar (int intConvert) {
  int ten = 10;

  if (intConvert >= 0 && intConvert <= 9) {
    return '0' + (intConvert);
  }

  if (intConvert >= 10 && intConvert <= 15) {
    return 'A' + (intConvert - ten);
  }

  else {
    return -1;
  }
}

/***********************************************************************
Function:     getBase

Description:  returns what we have as a base either decimal, binary,
              or hexadecimal  

Parameters:   strNumber - the string representing a decimal, hexadecimal,
              or binary number 

Returned:     D - if the number is decimal
              H - if the number is a hexadecimal 
              B - if the number is binary 
***********************************************************************/

char getBase (const string& strNumber) {

  char hex = 'H';
  char decimal = 'D';
  char binary = 'B';

  if (strNumber[0] == '0' && strNumber[1] == 'x') {
    return hex;
  }

  if (strNumber[0] == '0' && strNumber[1] == 'b') {
    return binary;
  }

  return decimal;
  
}

/***********************************************************************
Function:     getNumber

Description:  returns a string that represents a decimal, hexadecimal,
              or binary number 

Parameters:   prompt - the user input 

Returned:      - if the number is decimal
              H - if the number is a hexadecimal 
              B - if the number is binary 
***********************************************************************/

string getNumber (const string& prompt) {
  string myNum;
  cout << prompt;
  cin >> myNum;
 return myNum;
}

/***********************************************************************
Function:     printTitle 

Description:  prints the title of the program  

Parameters:   myTitle - the title to print

Returned:     none
***********************************************************************/

void printTitle (const string& myTitle) {

  cout << "**************************************" << endl;
  cout << myTitle << endl;
  cout << "**************************************" << endl;

}

/***********************************************************************
Function:     binaryToDecimal

Description:  converts the pased in binary to a decimal  

Parameters:   strNumber - the binary number passed in 

Returned:     std::to_string(calculate) - the decimal converted as string
***********************************************************************/

string binaryToDecimal (const string& strNumber) {
 int calculate = 0;

  for (int i = TWO; i < strNumber.size(); ++i)
  {
    if (strNumber[i] == 0){
      calculate += 0 * pow(TWO,i);
    }
    if (strNumber[i] == 1){
      calculate += 1 * pow(TWO,i);
    }
  }
  return std::to_string(calculate);
}

/***********************************************************************
Function:     decimalToBinary 

Description:  converts the pased in decimal to binary 

Parameters:   strNumber - the decimal number passed in 

Returned:     binary - the binary we converted from the decimal 
***********************************************************************/

string decimalToBinary (const string& strNumber) {
  int decimal = stoi(strNumber);
  int remainder = 0; 
  string binary = "";
  
  if (decimal == 0) {
    return "0";
  }

  while (decimal > 0) {
    remainder = decimal % TWO;
    binary = ::to_string(remainder) + binary;
    decimal /= TWO;
  }

  return binary;
}

/***********************************************************************
Function:     decimalToHex 

Description:  converts the pased in decimal to hexadecimal 

Parameters:   strNumber - the decimal number passed in 

Returned:     hex - the hexadecimal we converted from the decimal 
***********************************************************************/

string decimalToHex (const string& strNumber) {
  int decimal = stoi(strNumber);
  int remainder = 0; 
  int sixteen = 16;
  string hex = "";
  
  if (decimal == 0) {
    return "0";
  }

  while (decimal > 0) {
    remainder = decimal % sixteen;
    intToHexChar(remainder);
    hex = ::to_string(intToHexChar(remainder)) + hex;
    //need to reverse the string 
    decimal /= sixteen;
  }

  return hex;
}
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);