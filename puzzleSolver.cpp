/*
  Patrick Hourican
  pjh4as
  11/19/2020
  puzzleSolver.cpp

  Source: Professor Floryan's recorded lecture from 11/18 at 11:00 AM.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;

vector<string> genNeighbors(string curr);
string swap(string s, size_t i, size_t j);
void bfs(string start, map<string, int> dist);

map<string, int> dist;
queue<string> q;

int main() {

  string start = "";
  
  char n1, n2, n3, n4, n5, n6, n7, n8, n9;
  
  cout << "Enter puzzle"<< endl;
  cin >> n1 >> n2 >> n3;
  cin >> n4 >> n5 >> n6;
  cin >> n7 >> n8 >> n9;

  start+=n1;
  start+=n2;
  start+=n3;
  start+=n4;
  start+=n5;
  start+=n6;
  start+=n7;
  start+=n8;
  start+=n9;

  cout << "Solving puzzle" << endl;
  
  
  q.push(start);
  dist[start] = 0;

  bfs(start, dist);

}

/**
 * @brief breadth first search performed on the starting string and distance map.
 *
 * @param start The starting string that is entered.
 * @param dist The starting dist map.
 * @post the outputs for the code will be printed within this method. 
 */
void bfs(string start, map<string, int> dist){

  while(q.size() > 0) {
    string curr = q.front();
    q.pop();

    if(curr == "123456780") {
      cout << dist[curr] << endl;
      return;
    }

    vector<string> neighbors = genNeighbors(curr);
   
    for(int i=0; i<neighbors.size();i++){
      if(dist.find(neighbors[i])==dist.end()){
	dist[neighbors[i]]=(dist[curr]+1);
	q.push(neighbors[i]);
      }
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  return;
}

/**
 * @brief This returns a list of the neighboring strings.
 * @note The possible strings to be returned are based on the 0 position in the string.
 *
 * @param curr The string of the current combination ont he board.
 * @return vector of neighboring strings.
 */
vector<string> genNeighbors(string curr) {
  
  vector<string> neighbors;

  size_t hole = curr.find_first_of('0');

  if(hole>=3){
    neighbors.push_back(swap(curr, hole, hole-3));
  }
  if(hole<=5){
    neighbors.push_back(swap(curr, hole, hole+3));
  }
  if(hole%3 != 0){
    neighbors.push_back(swap(curr, hole, hole-1));
  }
  if((hole+1) % 3 != 0){
    neighbors.push_back(swap(curr, hole, hole+1));
  }

  return neighbors;
}

/**
 * @brief This method swaps two characters in a string.
 *
 * @param s The string containing the characters to swap.
 * @param i The first character to swap.
 * @param j The second character to swap.
 * @return string with characters swapped.
 */
string swap(string s, size_t i, size_t j) {
  char tempC;

  tempC = s[i];

  s[i]=s[j];
  s[j]=tempC;

  return s;
}
