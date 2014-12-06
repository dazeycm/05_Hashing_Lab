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
HashTable<Key, T>::HashTable(){

	hashPrimeNum = 0;
	numRemoved = 0;
	numItems = 0;
	backingArraySize = hashPrimes[hashPrimeNum];
	backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key, T>::~HashTable() {

	delete[] backingArray;
}

template <class Key, class T>
unsigned long HashTable<Key, T>::calcIndex(Key k){
	unsigned long int i = hash(k) % backingArraySize;
	while (!backingArray[i].isNull)	{
		if (!backingArray[i].isDel && backingArray[i].k == k)	{
			return i;
		}
		i = (i + 1) % backingArraySize;
	}
	return numItems;
}

template <class Key, class T>
void HashTable<Key, T>::add(Key k, T x){

	if (keyExists(k))	{
		throw std::string("Key already exists!");
	}

	unsigned long int i = hash(k) % backingArraySize;

	if (((numItems + numRemoved + 1) * 2) > backingArraySize)	{
		grow();
	}

	while (!backingArray[i].isNull && !backingArray[i].isDel)	{
		i = (i + 1) % backingArraySize;
	}

	if (backingArray[i].isDel)	{
		numRemoved--;
	}

	if (backingArray[i].isNull)	{
		numItems++;
	}

	backingArray[i].k = k;
	backingArray[i].x = x;

	backingArray[i].isNull = false;
	backingArray[i].isDel = false;
			
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	unsigned long int i = calcIndex(k);
	
	if (i != numItems)	{
		backingArray[i].isDel = true;
		numItems--;
		numRemoved++;
	}

}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	if (keyExists(k) == false)
		throw std::string("Invalid key was used in find() method");
	
	unsigned long int i = calcIndex(k);

	if (i != numItems)	{
		return backingArray[i].x;
	}

	throw std::string("Key does not exist in find() method");
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	unsigned long int i = calcIndex(k);
	if (i == numItems)	{
		return false;
	}
	

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	hashPrimeNum++;

	unsigned long int newSize = hashPrimes[hashPrimeNum];
	unsigned long int oldSize = backingArraySize;
	HashRecord *newArray = new HashRecord[newSize];

	backingArraySize = newSize;
	numRemoved = 0;

	for (unsigned int i = 0; i < oldSize; i++)	{
		if (!backingArray[i].isNull && !backingArray[i].isDel)	{
			int j = hash(backingArray[i].k) % backingArraySize;
			while (!newArray[j].isNull)	{
				j = (1 + j) % newSize;
			}

			newArray[j].k = backingArray[i].k;
			newArray[j].x = backingArray[i].x;
			
			newArray[j].isNull = false;
			newArray[j].isDel = false;
		}
	}
	
	delete[] backingArray;
	backingArray = newArray;
}
