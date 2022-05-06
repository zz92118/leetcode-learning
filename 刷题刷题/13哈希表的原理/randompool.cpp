#include <iostream>
#include <unordered_map>
#include <cstdlib>
/*
针对insert我们可以实现二个map同步操作，
一个插入(key, index)，另外一个插入(index, key)，然后使用size计数即可，保持同步。

针对getRandom，虽然Hash表返回的是近似等概论的，
但是不是严格等概率的，所有我们利用随机数从(index, key)中得到一个key。

针对delete操作，我们确实可以直接在(key, index)进行操作，
但是这样我们在使用getRandom函数之后它会产生空洞了，
所以一种思路就是我们可以借助最后一行(key,index)进行赋值给需要删除的key，这样就可以消除空洞。

*/


/*
template T 泛型

*/
template <typename T> class RandomPool {
 public:
     std::unordered_map<T, int> keyIndexMap;
     std::unordered_map<int, T> indexKeyMap;
     int size;
     RandomPool(): size(0) {}   // default constructor

     void insertKey(T key) {
        if (keyIndexMap.find(key) == keyIndexMap.end()) {   // if don't have key
            keyIndexMap.emplace(key, size);  // we can also insert({key, size}) instead
            indexKeyMap.emplace(size, key);
            size++;
        }
     }

     void deleteKey(T key) {
        if (keyIndexMap.find(key) != keyIndexMap.end()) {  // if we have key
            int deleteIndex = keyIndexMap.at(key);  // find we we want to delete the index
            int lastIndex = --size;  // last index
            T lastKey = indexKeyMap.at(lastIndex);    // find the last key
            keyIndexMap.erase(key);
            keyIndexMap.erase(lastKey);
            indexKeyMap.erase(deleteIndex);
            indexKeyMap.erase(lastIndex);
            keyIndexMap.emplace(lastKey, deleteIndex);
            indexKeyMap.emplace(deleteIndex, lastKey);
        }
     }

     T getRandomKey() {
        int random = rand() % size;     // get [0, size-1]
        return indexKeyMap.at(random);  // we can also use indexKeyMap[random] instead
     }
};
int main()
{
    // RandomPool<std::string> randomPool;     // template
    // randomPool.insertKey("A");
    // randomPool.insertKey("B");
    // randomPool.insertKey("C");
    // std::cout << "===================Insert key===================" << std::endl;
    // std::cout << "keyIndexMap: " << std::endl;
    // for (auto& it: randomPool.keyIndexMap) {
    //     std::cout << it.first << ": " << it.second << std::endl;
    // }
    // std::cout << "indexKeyMap: " << std::endl;
    // for (auto it = randomPool.indexKeyMap.begin(); it != randomPool.indexKeyMap.end(); ++it) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
    // std::cout << "===================Random key===================" << std::endl;
    // std::string randomKey1 = randomPool.getRandomKey();
    // std::string randomKey2 = randomPool.getRandomKey();
    // std::string randomKey3 = randomPool.getRandomKey();
    // std::cout << "key1: " << randomKey1 << "\n" << "key2: "
    //           << randomKey2 << "\n" <<  "key3: " << randomKey3 << std::endl;

    // std::cout << "===================Delete key===================" << std::endl;
    // randomPool.deleteKey("A");  // delete "A"
    // std::cout << "keyIndexMap: " << std::endl;
    // for (auto& it: randomPool.keyIndexMap) {
    //     std::cout << it.first << ": " << it.second << std::endl;
    // }
    // std::cout << "indexKeyMap: " << std::endl;
    // for (auto it = randomPool.indexKeyMap.begin(); it != randomPool.indexKeyMap.end(); ++it) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
    // std::cout << "==================After delete random key========" << std::endl;
    // std::string randomKey11 = randomPool.getRandomKey();
    // std::string randomKey22 = randomPool.getRandomKey();
    // std::string randomKey33 = randomPool.getRandomKey();
    // std::cout << "key1: " << randomKey11 << "\n" << "key2: "
    //           << randomKey22 << "\n" <<  "key3: " << randomKey33 << std::endl;
    // return 0;
}
