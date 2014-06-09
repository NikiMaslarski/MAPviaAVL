#include <iostream>
#include <avl_tree.h>

using namespace std;

int main()
{
    Map<char, int> pesho;
    cout << boolalpha << pesho.isEmpty() << endl;
    pesho.put('h', 2);
    pesho.put('c', 4);
    pesho.put('b', 10);
    pesho.put('a', 1);
    pesho.put('z', 11);
    cout << pesho.contains('a') << endl;
    cout << pesho.remove('a') << "  " << pesho.remove('z') << endl;
    cout << "removed" << endl;
    cout << pesho.contains('a') << "  " << pesho.contains('z');

}
