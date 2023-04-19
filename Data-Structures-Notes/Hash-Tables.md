# Hash Tables

* A Hash Table is a data structure that associates keys with values
* It can perform a lookup operation efficiently
* It transforms the key into a hash using a hashing function. It uses the hash to locate the value of the key
* The hash maps directly to an index in the array containing the values

```cpp
HashTable<Element>
make-hash-table(integer n) : HashTable
// Create a hash table with n buckets (the array size)

get-value(HashTable h, Comparable key) : Element
// Returns the value of the element for the given key. The key must be some comparable type

remove(HashTable h, Comparable key)
// Remove the element for the given key from the hash table. The key must be some comparable type
```

## Time complexity and common uses of hash tables

* Hash tables are used to implement associative arrays, sets, and caches
* Hash tables provide constant time lookup on average, and have a worst case scenario of **O(n)**
* Hash tables are most useful when we need to store a large number of data records
* Hash tables can be used as an in-memory data structure or a persistent data structure

## Choosing a good hash function

* A good hash function is needed for good hash table performance
* A bad hash function will increase the likelyhood of collisions occuring, which is when differnet keys map to the same bucket
* It is not possible to bring collisions down to zero, but collisions affect performance negatively, so it is best to reduce them as much as possible
* Some hash functions are computationally expensive
* There is no consensus on what makes a good hash function, but the book looks at the following criteria:
  * simplicity
  * speed
  * strength
* We would not want to use a cryptographic hashing function for a hash table because it would take to long and we don't need the features found in a cryptographic hash function
* It would be better to use a universal hash function than a static hash
* To test a hash function for its strenght, we test the avalanche effect. The avalanche effect states that changing 1 bit from the input should change on average half the bits in the output
* One good hashing function for hash tables is the Jenkins One-at-a-time hash

```cpp
// Jenkins one-at-a-time hash
uint32 joaat_hash(uchar *key, size_t len) {
  uint32 hash = 0;
  size_t i;

  for (int i = 0; i < len; ++i) {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash >> 15);
  return hash;
}
```

* Conversion from the hash value to a bucket index for a hash table can be down by masking the lower k bits for a table of size 2^k
  * This is equivalent to computing the hash modulo the table size

## Collision resolution
* If two keys hash to the same index, we cannot store one of the keys at that index
* We have to find an index where we can store the second and following hashes and be able to find them when we look for them later on
* The most common collision resolution techniques are **chaining** and **open addressing**

#### Chaining

* In the simplest form of chaining, a linked list is stored at every bucket of the hash table and every key that collides to one bucket is stored in the linked list from that bucket
* Chaining has advantages over open addressing. The performance degradation of a hash table using chainging is slower than one using open addressing
* Chaining has disadvantages when there is not much data stored in the hash tabe because the performance of linked list can be expensive
* Other data structures can be used to implement chaining instead of linked list. A self-balancing tree can be used and it would have a better Big O than a linked list, but since hash tables are not designed to have many collisions, this is unecessarry

#### Open Addressing

* Open addressing hash tables store records directly in the array
* A hash collition is solved by probing the array for alternate locations where the element can be stored
* When searching for an element that was stored this way, the function iterates throght the elements until it either finds the element or finds an empty bucket, meaning that the element is not found in the hash table
* The load factor of a hash table is the percentage of buckets that are filled in the array
* As the load factor increases, the performance of probing the array decreases
* There are three types of probing methods:
  * linear probing
  * quadratic probing
  * double hashing
