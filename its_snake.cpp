#include <bits/stdc++.h>
using namespace std;

bool moves_available(int,int);
bool atleastOne();
int next_movex(int,int);
int next_movey(int,int);

vector<vector<char> >pattern;
vector<vector<int> >marked;
int  N;

int main(){
  cin >> N;
  char ch;
  vector<char>c;
  vector<int>i;
  pattern.push_back(c);
  pattern.push_back(c);
  marked.push_back(i);
  marked.push_back(i);

  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++){
      cin>>ch;
      pattern[i].push_back(ch);
      marked[i].push_back(0);
    }
  }
  cout<<"got it!"<<endl;
  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++){
      //cin>>ch;
      cout<<pattern[i][j]<<" ";
      //marked[i].push_back(0);
    }
    cout<<endl;
  }


  int curri,starti=0;
  int currj,startj=0;
  curri = starti;
  currj = startj;

  while(moves_available(curri,currj)){
    marked[curri][currj] = 1;
    cout<<"right now:"<<curri<<" "<<currj<<endl;
    int ni = next_movex(curri,currj);
    //cout<<"dbg!"<<endl;
    int nj = next_movey(curri,currj);
    curri = ni;
    currj = nj;
    cout<<"next:"<<curri<<" "<<currj<<endl;
  }


  bool flag = true;
  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++){
      if((marked[i][j] == 1 && pattern[i][j] == '#') || (marked[i][j] == 0 && pattern[i][j] == '.')){
          continue;
      }
      else{
        cout<<"No"<<endl;
        flag = false;
        break;
      }
    }
  }
  if(flag && atleastOne()){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}

bool atleastOne(){
  bool t = false;
  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++){
      if(marked[i][j]==1){
        t = true;
        return t;
      }
    }
  }
  return false;
}

bool moves_available(int x, int y){
  bool t = false;
  if(x+1<N && pattern[x+1][y]=='#' && marked[x+1][y]==0){
    t = true;
  }
  if(y+1<2 && pattern[x][y+1]=='#' && marked[x][y+1]==0){
    t = true;
  }
  if(y-1>=0 && pattern[x][y-1]=='#' && marked[x][y-1]==0){
    t = true;
  }
  return t;
}

int next_movex(int x, int y){
  if((y+1<2 && pattern[x][y+1]=='#' && marked[x][y+1]==0) || (y-1>=0 && pattern[x][y-1]=='#' && marked[x][y-1]==0)){
    return x;
  }
  else{
    return x+1;
  }
}

int next_movey(int x, int y){
  if(y+1<2 && pattern[x][y+1]=='#' && marked[x][y+1]==0){
    return y+1;
  }
  else if(y-1>=0 && pattern[x][y-1]=='#' && marked[x][y-1]==0){
    return y-1;
  }
  else{
    return y;
  }
}
