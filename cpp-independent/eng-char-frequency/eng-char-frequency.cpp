/*
  English Character Frequencies - Isaiah Mon Desir

  The purpose of this program is to quite simply determine the frequency of 
  each letter and number in the English language by looking through multiple 
  dictionaries and literary works.

  Possible uses of the result of this program: Cypher decoding.
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <cassert>

using namespace std;

//Reads the file
int readFile(vector<int>&characterCount, string& filename){
  ifstream ifs(filename);
  string word;
  int allChars =0; //All considered chars rather than all characters in the doc
  //Go through all the words then add count to vector
  while(ifs >> word){
    for(char& letter: word){
      int ord = int(letter);
      //Capital letters
      if(ord >=65 && ord <= 90){
	characterCount[ord-65]+=1;
	allChars+=1;
      }
      //Lowercase letters
      else if(ord >= 97 && ord <= 122){
	characterCount[ord-71]+=1;
	allChars+=1;
      }
      //Digit
      else if(ord >= 48 && ord <= 57){
	characterCount[ord+4]+=1;
	allChars+=1;
      }
      else{}
    }
  }
  ifs.close();
  return allChars;
}

//Scans for filenames to be used as input text
int scanFiles(vector<int>&characterCount){
  vector<string>filenames;
  int allChars =0;
  ifstream ifs("filenames.txt");
  string filename;
  while (ifs >> filename){
    filenames.push_back(filename);
  }
  ifs.close();
  for (string& file: filenames){
    allChars += readFile(characterCount, file);
  }
  return allChars;
}

int main(){
  //Make vector of size 62 (26 Uppercase, 26 Lowercase, 10 digits
  vector<int> characterCount;
  vector<double> characterFrequency;
  for(size_t i =0; i < 62; ++i){
    characterCount.push_back(0);
    characterFrequency.push_back(0);
  }
  int allChars = 0;
  allChars+=scanFiles(characterCount);
  
  //Change characterCount to characterFrequency
  for(size_t i =0; i < 62; ++i){
    characterFrequency[i] = (characterCount[i]/ (double)(allChars)) * 100;
    if(i<=25) { cout << (char)(i + 65) << ": ";}
    else if(i<=51) {cout << (char)(i + 71) << ": ";}
    else{ cout << (char)(i - 4) << ": ";}
    cout << characterFrequency[i] << "%\n";
  }
  
  cout << "done" << endl;
}
