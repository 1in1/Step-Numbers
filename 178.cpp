#include <iostream>
#include <vector>
#include <chrono>
typedef unsigned long long big;
using namespace std;

big search(int current, int remaining, int mask)
{
  static big found[10][60][(1<<10)];

  mask |= (1 << current);
  if(remaining == 1 && mask == (1<<10)-1)
    return 1;
  if(remaining == 1)
    return 0;

  big result = 0;
  if(found[current][remaining][mask] > 0)
    return found[current][remaining][mask];


  if(current>0)
    result += search(current-1, remaining-1, mask);
  if(current<9)
    result += search(current+1, remaining-1, mask);

  found[current][remaining][mask] = result;
  return result;
}


int main()
{
  //vector<big> found;
  int upto;
  cin>>upto;

  auto start = chrono::high_resolution_clock::now();
  big end= 0;
  for(int i = 1; i<10; i++){
    for(int j = 10; j<=upto; j++){
      end+= search(i, j, (1<<i));
    }
  }
  cout<<end<<endl;
  auto stop = chrono::high_resolution_clock::now();
 	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
 	cout << "Done. Took "<<duration.count()<< " microseconds total." << endl;
}
