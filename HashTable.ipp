//Collision: Two items want the same spot 
//Separate Chaining: Linked List of hash records, Items that collide are put in the same chain as each other
//Open Addressing: Start looking at an index, if it isn't there, keep looking...
//Linear Probing: If not here, go right 
//Index = key % backingArraySize
//BackingArray > 2 * numItems
//BackingArraySize should always be a prime #
//hash(key) = a*key where a > 1000 or some other big number... a is the multiplicative

//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
  //TODO
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  //TODO
}

template <class Key, class T>
unsigned long HashTable<Key,T>::calcIndex(Key k){
  //TODO
  return numItems; //This indicates failure, since it is an impossible value
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){
  //TODO
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
  //TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
  //TODO
  T dummy;
  return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
  //TODO
  return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
  //TODO
  return 0;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
  //TODO
  //Call own insert method
}
