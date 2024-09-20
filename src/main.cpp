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
  const string number = "Enter your string to convert (q to quit): ";
  string input = "";

  printTitle(myTitle);

  input = getNumber (number);

  getBase(input);

  if (getBase(input) == 'D') {
    cout << "The binary conversion is: " << decimalToBinary(input) << endl;
    
    cout << "The hexadecimal conversion is: " << decimalToHex(input) << endl;
    
  }

  if (getBase(input) == 'B') {
    cout << "The decimal conversion is: " << binaryToDecimal(input) << endl;
    
    //cout << "The hexadecimal conversion is: " << binaryToHex(input) << endl;
    
  }

  if (getBase(input) == 'D') {
    cout << "The decimal conversion is: " << decimalToBinary(input) << endl;
    
    cout << "The binary conversion is: " << decimalToHex(input) << endl;
    
  }

 


  
  
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

Returned:     the string prompt
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
 int length = strNumber.size();

  for (int i = 2; i < length; ++i){

    if (strNumber[i] == '1') {
      calculate += pow(TWO, length - i - 1);
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
  string binary = "0b";
  
  if (decimal == 0) {
    return "0b0";
  }

  while (decimal > 0) {
    remainder = decimal % TWO;
    binary += ::to_string(remainder);
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
  string hex = "0x";
  
  if (decimal == 0) {
    return "0x0";
  }

  while (decimal > 0) {
    remainder = decimal % sixteen;
    hex += ::to_string(intToHexChar(remainder));
    decimal /= sixteen;
  }

  return hex;
}

/***********************************************************************
Function:     hexToDecimal  

Description:  converts the pased in hexadecimal to decimal 

Parameters:   strNumber - the hexadecimal number passed in 

Returned:     decimal - the decimal we converted from the hexadecimal 
***********************************************************************/

string hexToDecimal (const string& strNumber) {
  int decimal = stoi(strNumber, nullptr, 16);
  
  string decimalString = to_string(decimal);

  return decimalString;
}

/***********************************************************************
Function:     hexToDecimal  

Description:  converts the pased in hexadecimal to decimal 

Parameters:   strNumber - the hexadecimal number passed in 

Returned:     decimal - the decimal we converted from the hexadecimal 
***********************************************************************/

string hexToBinary (const string& strNumber) {

}

/***********************************************************************
Function:     hexToDecimal  

Description:  converts the pased in hexadecimal to decimal 

Parameters:   strNumber - the hexadecimal number passed in 

Returned:     decimal - the decimal we converted from the hexadecimal 
***********************************************************************/

string binaryToHex (const string& strNumber) {

}