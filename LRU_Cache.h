//
// Created by Ryan.Zurrin001 on 1/22/2022.
//

#ifndef LRUCACHE_LRU_CACHE_H
#define LRUCACHE_LRU_CACHE_H
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

template<typename K, typename V>
class cache_node {
public:
    K key;
    V value;
    cache_node(K k, V v) : key(k), value(v) {}
};


template <typename K, typename V>
class LRU_Cache {
private:
    int capacity;
    list<cache_node<K, V>> cache_list;
    unordered_map<K, typename list<cache_node<K, V>>::iterator> cache_map;
public:
    explicit LRU_Cache(int capacity) : capacity(capacity) {}

    void insertKeyValue(K key, V value) {
        if (cache_map.find(key) != cache_map.end()) {
            cache_map[key]->value = value;
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        } else {
            if (cache_list.size() == capacity) {
                cache_map.erase(cache_list.back().key);
                cache_list.pop_back();
            }
            cache_node<K, V> new_node(key, value);
            cache_list.push_front(new_node);
            cache_map[key] = cache_list.begin();
        }
    }

    V getValue(K key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        } else {
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            return cache_map[key]->value;
        }
    }

    K mostRecentKey() {
        return cache_list.front().key;
    }

};


#endif //LRUCACHE_LRU_CACHE_H
