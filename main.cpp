#include <iostream>
#include <avl_tree.h>

using namespace std;

int main()
{
    Map<char, int> pesho;
    cout << boolalpha << pesho.isEmpty() << endl;
    pesho.put('a', 2);
    cout << pesho.isEmpty();
}
