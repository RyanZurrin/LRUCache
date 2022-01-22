#include <iostream>
#include "LRU_Cache.h"
int main() {
    LRU_Cache<string , int> cache(3);
    cache.insertKeyValue("mango", 10);
    cache.insertKeyValue("apple", 20);
    cache.insertKeyValue("guava", 30);
    cout << cache.mostRecentKey() << endl;
    cache.insertKeyValue("mango", 40);
    cout << cache.mostRecentKey() << endl;

    cache.insertKeyValue("banana", 20);
    if(cache.getValue("apple") == nullptr)
        cout << "apple not found" << endl;
    else
        cout << "apple found" << endl;
    if(cache.getValue("banana") == nullptr)
        cout << "banana not found" << endl;
    else
        cout << "banana found" << endl;
    if(cache.getValue("guava") == nullptr)
        cout << "guava not found" << endl;
    else
        cout << "guava found" << endl;
    if(cache.getValue("mango") == nullptr)
        cout << "mango not found" << endl;
    else
        cout << "mango found" << endl;
    return 0;

}
