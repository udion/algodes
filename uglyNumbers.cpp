#include <bits/stdc++.h>
using namespace std;

int main (){
    int T = 0;
    cin >> T;
    int N;
    for(int i=0; i<T; i++){
      cin >> N;
      int indexOf2=0;
      int indexOf3=0;
      int indexOf5=0;
      vector<int> un;
      un.push_back(1);
      int ans = un[0];
      for(int count=0; count<N-1;){
        ans = min(min(un[indexOf2]*2,un[indexOf3]*3),un[indexOf5]*5);
        if(ans == un[indexOf2]*2){
          indexOf2++;
        }
        else if(ans == un[indexOf3]*3){
          indexOf3++;
        }
        else{
          indexOf5++;
        }
        if(ans > un[count]){
            un.push_back(ans);
            count++;
        }
      }
      //for(auto itr = un.begin(); itr != un.end(); itr++){
      //  cout<<*itr<<" ";
    //}
    cout<<un[N-1]<<endl;
  }
}
