//You will need this so you can make a string to throw in
// remove
#include <string>

unsigned long hash(char c){ return 10*((unsigned long)c)%11; }
HashTable<char,int> mySillyTable;

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArray = new HashRecord[13];
	numItems = 0;
	backingArraySize = 13;
	numRemoved = 0;	
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
  delete[] backingArray;
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){

	if (numItems+numRemoved >= backingArraySize/2){
		grow();
	}
	
	int place = hash(k);
	int index = place % backingArraySize;
	//int jump = 1 + (place % (backingArraySize - 1));
		
			backingArray[index].x = x;
			backingArray[index].isNull = false;
			backingArray[index].k = k;
			
	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	
	int place = hash(k);
	int index = place % backingArraySize;
	int jump = 1 + (place % (backingArraySize - 1));
	
	backingArray[index].x = NULL;
	
	backingArray[index].isDel = true;
	backingArray[index].isNull = false;
	
	numItems--;
	numRemoved++;
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	if (keyExists(k) == 0){
		throw (std::string) "invalid key";
	}
	int place = hash(k);
	int index = place % backingArraySize;

	return backingArray[index].x;

	/*HashRecord p;
	p.k = k;
	int place = hash(k);
	int index = place % backingArraySize;
	p.k = backingArray[index].k;
	
	int jump = 1 + (place%(backingArraySize - 1));
	int i = index;
	while (!backingArray[i].isNull) {
		if (hash(backingArray[i].k) == index){
			return backingArray[i].x;
		}
		else {
			i = i + jump;
		}
	}*/
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	
	int place = hash(k);
	int index = place % backingArraySize;
	
	if (backingArray[index].k == k && backingArray[index].isDel == false){
		return true;
	}
 	return false;

}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){

HashRecord* temp = backingArray;
int tempSize = backingArraySize;
//backingArray = new HashRecord[backingArraySize*2];

//backingArraySize = backingArraySize*2;

	for (int k = 0; k < 26; k++){
		if (backingArraySize < hashPrimes[k]){
			backingArray = new HashRecord[hashPrimes[k]];
			backingArraySize = hashPrimes[k]; 
			k = 30;
			}
	}
	
	for (int j = 0; j < tempSize; j++){
		if (temp[j].isNull == false && temp[j].isDel == false)
			add(temp[j].k, temp[j].x);
	}
	
}
