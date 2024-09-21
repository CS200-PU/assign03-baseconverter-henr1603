//******************************************************************************
// File name:   main.cpp
// Author:      AaJanae Henry
// Date:        09/14/2024
// Class:       CS200
// Assignment:  Base Converter
// Purpose:     Convert numbers entered by users to a decimal, binary, or
//              hexadecimal
// Hours:       27
//******************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int ONE = 1;
const int TWO = 2;
const int NINE = 9;
const int TEN = 10;
const int NEG_ONE = -1;
const char LETTER_A = 'A';
const char LETTER_F = 'F';
const string HEXADECIMAL = "0x";
const string BINARY = "0b";

//default fucntions 

void printTitle (const string& myTitle);
void choiceConversion (const string& input, const string& choice);
int hexCharToInt (char hexDigit);
char intToHexChar (int intConvert);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
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

  const string MY_TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****";
  const string NUMBER = "Enter your string to convert (q to quit): ";
  string input = "";
  string choice = "";
  string endProgram = "q";
  
  printTitle(MY_TITLE);

  while (choice != endProgram) {

    input = getNumber(NUMBER);
    choice = getBase(input);

    if(choice != endProgram) {
      choiceConversion(input,choice);
    }
  }
  return EXIT_SUCCESS;
}

/***********************************************************************
Function:     choiceConversion

Description:  gets the choice from the user and prints out the conversion
              options for the user 

Parameters:   input - the number entered from the user
              choice - which number to do the conversions for 

Returned:     none
***********************************************************************/

void choiceConversion (const string& input, const string& choice) {

  string decimal = "D";
  string hexaDecimal = "H";
  string binary = "B";

  if (choice == decimal) {
    cout << "The binary conversion is: " << decimalToBinary(input) << endl;
    
    cout << "The hexadecimal conversion is: " << decimalToHex(input) 
         << endl << endl;
    
  }

  else if (choice == binary) {
    cout << "The decimal conversion is: " << binaryToDecimal(input) << endl;
    
    cout << "The hexadecimal conversion is: " << binaryToHex(input) 
         << endl << endl;
    
  }

  else if (choice == hexaDecimal) {
    cout << "The decimal conversion is: " << hexToDecimal(input) << endl;
    
    cout << "The binary conversion is: " << hexToBinary(input) 
         << endl << endl;
  }
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
Function:     hexCharToInt

Description:  Converting a hex char to an integer 

Parameters:   hexDigit - the hex char passed in from user

Returned:     int - the integer that was the end of conversion 
***********************************************************************/

int hexCharToInt (char hexDigit) {

  char nine = '9';

  if (hexDigit >= '0' && hexDigit <= nine) {
    return hexDigit - '0';
  }

  else if (hexDigit >= LETTER_A && hexDigit <= LETTER_F) {
    return hexDigit - LETTER_A + TEN;
  }

  else {
    return NEG_ONE;
  }
}

/***********************************************************************
Function:     intToHexchar

Description:  Converting an integer to a hex char

Parameters:   intConvert - the int passed in to be converted 

Returned:     char - the char that was converted
***********************************************************************/

char intToHexChar (int intConvert) {

  int fifteen = 15;

  if (intConvert >= 0 && intConvert <= NINE) {
    return '0' + intConvert;
  }

  if (intConvert >= TEN && intConvert <= fifteen) {
    return LETTER_A + intConvert - TEN;
  }

  else {
    return NEG_ONE;
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
              q - if user is ending program
***********************************************************************/

char getBase (const string& strNumber) {

  char hex = 'H';
  char decimal = 'D';
  char binary = 'B';
  char quit = 'q';
  char letterB = 'b';
  char letterX = 'x';
  
  if (strNumber[0] == '0' && strNumber[ONE] == letterX) {
    return hex;
  }

  else if (strNumber[0] == '0' && strNumber[ONE] == letterB) {
    return binary;
  }

  else if (strNumber[0] == quit) {
    return quit;
  }

  else {
    return decimal;
  }
}

/***********************************************************************
Function:     getNumber

Description:  returns a string that represents a decimal, hexadecimal,
              or binary number from the user

Parameters:   prompt - the user input 

Returned:     the number entered
***********************************************************************/

string getNumber (const string& prompt) {

  string myNum;
  cout << prompt;
  cin >> myNum;

  return myNum;
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
 char one = '1';

  for (int i = TWO; i < length; ++i) {
    if (strNumber[i] == one) {
      calculate += pow(TWO, length - i - ONE);
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
    return BINARY + '0';
  }

  while (decimal > 0) {
    remainder = decimal % TWO;
    binary += std::to_string(remainder);
    decimal /= TWO;
  }

  reverse(binary.begin(), binary.end());

  return BINARY + binary;
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
    return HEXADECIMAL + '0';
  }

  while (decimal > 0) {
    remainder = decimal % sixteen;
    hex += intToHexChar(remainder);
    decimal /= sixteen;
  }

  reverse(hex.begin(), hex.end());

  return HEXADECIMAL + hex;
}

/***********************************************************************
Function:     hexToDecimal  

Description:  converts the pased in hexadecimal to decimal 

Parameters:   strNumber - the hexadecimal number passed in 

Returned:     decimal - the decimal we converted from the hexadecimal 
***********************************************************************/

string hexToDecimal (const string& strNumber) {

  int length = strNumber.size();
  int decimal = 0;
  int sixteen = 16;
  
  for (int i = TWO; i < length; ++i) {
    int hexValue = hexCharToInt((strNumber[i]));
    decimal +=  hexValue * (pow (sixteen, length - i - ONE));
  }

  return std::to_string(decimal);
}

/***********************************************************************
Function:     hexToBinary  

Description:  converts the pased in hexadecimal to decimal then to binary

Parameters:   strNumber - the hexadecimal number passed in 

Returned:     decimalToBinary(decimal) - the function that converts the 
                                         decimal to a binary
***********************************************************************/

string hexToBinary (const string& strNumber) {

  string decimal = hexToDecimal(strNumber);

  return decimalToBinary(decimal);
}

/***********************************************************************
Function:     binaryToHex  

Description:  converts the pased in binary to decimal then to hexadecimal

Parameters:   strNumber - the binary number passed in 

Returned:     decimalToHex(decimal) - the function that converts the 
                                      decimal to a hexadecimal 
***********************************************************************/

string binaryToHex (const string& strNumber) {

  string decimal = binaryToDecimal(strNumber);

  return decimalToHex(decimal);
}