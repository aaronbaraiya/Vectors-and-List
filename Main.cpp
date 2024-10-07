#include <iostream>
#include <vector>
#include "Random.h"
#include "List.h"
using namespace std;
template <typename T>
void print_list(List<T>);
List<int> max_subseq_sum_collect(const List<int>&, int&);
int main()
{
List<int> mylst;
vector<int> rnums;
random_vector(25, 1, 100, rnums, 4);
for (int i = 0; i < rnums.size(); i++)
mylst.push_back(rnums[i]);
cout << "My list of random numbers: " << endl;
print_list(mylst);
int maxsubsum;
List<int> maxsubseq = max_subseq_sum_collect(mylst, maxsubsum);
cout << endl;
cout << "The max subseq sum: " << maxsubsum << endl << endl;
cout << "The max subsum squence: " << endl;
print_list(maxsubseq);
cout << endl << endl;
List<int>::iterator itr1 = maxsubseq.begin();
for (; itr1 != maxsubseq.end(); ++itr1)
{
List<int>::iterator itr2 = mylst.begin();
while (itr2 != mylst.end())
{
if (*itr1 == *itr2)
{
int togo = *itr2;
itr2 = mylst.erase(itr2);
mylst.insert(itr2, 0);
}
else
itr2++;
}
}
cout << endl << endl;
cout << "My list after replacing all max subseq values with 0: " << endl;
print_list(mylst);
cout << endl << endl;
return 0;
}
template <typename T>
void print_list(List<T> lst)
{
cout << endl;
typename List<T>::iterator itr;
for (itr = lst.begin(); itr != lst.end(); ++itr)
cout << *itr << " ";
cout << endl;
}
List<int> max_subseq_sum_collect(const List<int>& lst, int& max)
{
int maxsum = 0;
int localsum = 0;
List<int> maxseq;
List<int> localseq;
List<int>::const_iterator itr = lst.begin();
for (; itr != lst.end(); itr++)
{
localsum += *itr;
localseq.push_back(*itr);
if (localsum > maxsum)
{
maxsum = localsum;
maxseq = localseq;
}
else if (localsum < 0)
{
localsum = 0;
localseq.clear();
}
}
max = maxsum;
return maxseq;
}
