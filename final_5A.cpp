#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main() {
  
  ifstream ifs("tweets.txt");
  
  ofstream ofs;
  
  string tweet;
  
  vector<string> tweetList;
  map<string, int> sortedList;
  getline(ifs, tweet);
  while(!tweet.empty()) {  
    int space = 0; 
    int spaceLast = 0;
    int wordSpace;
    string word;
    for(int i=0; i<tweet.size(); i++) {

 
      char c = tweet[i];
      if(c == ' ') {
        space = i;
        if(spaceLast == 0) {
          wordSpace = space-spaceLast;
          word = tweet.substr(spaceLast, wordSpace);
          spaceLast = space;
        }
        else {
          wordSpace = space-(spaceLast+1);
          word = tweet.substr(spaceLast+1, wordSpace);
          spaceLast = space;
        }
        if(i+1 == tweet.size()) {
          wordSpace = space-spaceLast;
          word = tweet.substr(spaceLast+1, wordSpace);
        }
        tweetList.push_back(word);
      }
    }
    getline(ifs, tweet);    
  } 
  vector<string> tweetsort;
  string curr1 = tweetList.back();
  while(tweetList.empty() != true) {
    tweetList.pop_back();
    int place = 0;
    tweetsort.push_back(curr1);
    unsigned int pos1 = tweetList.size()-2;
    string temp1 = tweetList[pos1];
    while(pos1 >= 0) {
      if(temp1 == curr1) {
        tweetsort.push_back(temp1);
        tweetList.erase(tweetList.rbegin()+place);
      }
      place++;
      pos1--;
      temp1 = tweetList[pos1];
    }
  }
  string curr = tweetList[0];
  string temp = tweetList[1];
  int count = 1;
  int wordCount = 0;
  while(wordCount <= tweetsort.size()) {
    int pos = 1;
    if(temp == curr) {
      wordCount++;
      if(wordCount > count) {
        while(temp == curr) {
          pos++;
          curr = temp;
          temp = tweetList[pos];
        }
        wordCount = 1;
      }
      else {
        pos++;
        curr = temp;
        temp = tweetList[pos];
      }
    }
    else {
      if(wordCount == count) {
        sortedList[curr] = wordCount;
      }
        curr = temp;
        pos++;
        temp = tweetList[pos];
        wordCount == 0;
      }
    }
    ofs.open("sortedTweets.txt");
    ofs << "Word       # of appearance \n";
    map<string, int>::reverse_iterator rit;
    for(rit=sortedList.rbegin(); rit!=sortedList.rend(); rit++) {
      ofs << rit->first << "  " << rit->second << endl;
    }
  ofs.close();
}
