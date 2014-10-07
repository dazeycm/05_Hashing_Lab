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
	numRemoved = 0;
	numItems = 0;
	backingArraySize = hashPrimes[0];
	backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
	delete[] backingArray;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::calcIndex(Key k){
	//int j = hash(k)%backingArraySize;
	return 0;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){

}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	//TODO
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	T dummy;
	return dummy;
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	//TODO one line function after calling calcindex
	return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	//TODO USES NEW
	//Call own insert method
}
