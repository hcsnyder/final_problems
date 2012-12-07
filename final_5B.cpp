#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void analysis(vector<string> tweets) {

  ofstream analysis;
  unsigned int numWords = tweets.size();

  string curr = tweets.back();
  tweets.pop_back();
  string temp = tweets.back();
  unsigned int uniqueWords = 1;
  while(tweets.size() != 0) {
    if(curr != temp) {
      uniqueWords++;
    }
    curr = temp;
    tweets.pop_back();
    temp = tweets.back();
  }
  analysis.open("analysis.txt");

  analysis << "Total Number of Unique Words \n";
  analysis << uniqueWords << endl;
  analysis << "Lexical Diversity \n";
  unsigned int lexD = numWords/uniqueWords;
  analysis << lexD;
}
