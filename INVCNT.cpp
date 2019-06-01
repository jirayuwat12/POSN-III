#include <iostream>
#include <vector>

using namespace std;

int main(){
  int idx = 10;
  idx -= (idx & -idx);
  cout<<idx;
}
