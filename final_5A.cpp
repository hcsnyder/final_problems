#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main() {
  
  ifstream ifs("tweets.txt");
  
  ofstream ofs;
  
  string tweet;
  
  map<string, int> tweetMap;
 
  map<string, int> sortedMap;
  getline(ifs, tweet);
  while(!tweet.empty()) {  
    int space = 0; 
    int spaceLast = 0;
    int wordSpace;
    String word;
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
        if(tweepMap[word] > 0) {
          tweetMap[word]++;
        }
        else {
          tweetMap[word]=1;
        }
      }
    }
    getline(ifs, tweet);    
  } 

  map<string, int>::reverse_iterator rit;
  it=mymap.begin();
  int count = 1;
  while(tweetMap.size() != 0) {
    for(rit=tweetMap.rbegin(); rit != tweetMap.rend(); rit++) {
      if(rit->second == count) {
        string index = rit->first;
        sortedMap.[index]=(rit->second);
        map<string, int>::reverse_iterator eraseRit = rit;
        tweetMap.erase(eraseRit);
      }
    }
    count++;
  }
  ofs.open("sortedTweets.txt");
  ofs << "Word       # of appearance \n";
  for(rit=sortedMap.rbegin(); rit != sortedMap.rend(); rit++) {
    ofs << rit->first << "  " << rit->second << endl;
  }
  ofs.close();
}
