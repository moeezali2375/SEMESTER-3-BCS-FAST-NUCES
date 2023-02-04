#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std ;

template <class v>
struct HashItem
{
    int key;
    v value;
    short status;
public:
    HashItem()
    {
        key = 0 ;
        status = 0 ;
    }
    

};

template <class v>
class HashMap
{
protected:
    HashItem<v>* hashArray;
    int capacity;
    int currentElements;
    float getLoadFactor()
    {
        return ((float)currentElements/(float)capacity) ;
    }
    void doubleCapacity()
    {
        capacity = capacity + capacity ;
        HashItem<v>* oldhashArray = hashArray ;
        hashArray = new HashItem<v>[capacity];
        currentElements = 0 ;
        for(int i = 0 ; i < capacity/2 ; i++)
        {
            if(oldhashArray[i].status == 2)
            {
                insert(oldhashArray[i].key,oldhashArray[i].value);
            }
        }
        cout<<"Capacity : "<<capacity<<endl;
    }
    int Hash(int key,int size)
    {
        return key % size ;
    }
    virtual int getNextCandidateIndex(int key, int i)
    {
        return Hash(key,capacity)+i ;
    }

    public:
    HashMap()
    {
        capacity = 10 ;
        currentElements = 0 ;
        hashArray = new HashItem<v>[capacity] ;
    }
    HashMap(int const capacity_)
    {
        capacity = capacity_ ;
        currentElements = 0 ;
        hashArray = new HashItem<v>[capacity] ;
    }
    
    void insert(int const key, v const value)
    {
        
        int idx = Hash(key, capacity) ;
        if(hashArray[idx].status == 0)
        {
            
            hashArray[idx].key = key ;
            hashArray[idx].value = value ;
            hashArray[idx].status = 2 ;
            currentElements++;
           // cout<<" Load Factor : "<<getLoadFactor()<<endl;
        }
        else
        {
            int next = 0 ;
            for(int i = 1 ; i <= capacity ; i++)
            {
                next = getNextCandidateIndex(key, i);
                if(next >= capacity )
                    next = next % capacity ;

                if(hashArray[next].status == 0)
                {
                    hashArray[next].key = key ;
                    hashArray[next].value = value ;
                    hashArray[next].status = 2 ;
                    currentElements++;
                   // cout<<" Load Factor : "<<getLoadFactor()<<endl;
                    break ;
                }
            }
        }
        if(getLoadFactor() >= 0.75)
        {
            cout<<"Size Doubled "<<endl;
            doubleCapacity();
        }

    }
    bool deleteKey(int const key)
    {
        if(currentElements > 0 )
        {
        
            int idx = Hash(key, capacity) ;
            if(hashArray[idx].status == 2 && hashArray[idx].key == key )
            {
                
                hashArray[idx].status = 1 ;
                currentElements--;
                cout<<"deleted at idx : "<<idx<<" : current size : "<<currentElements << endl;
                currentElements--;
                return true ;
            }
            else
            {
                int  next = 0 ;
                for(int i = 1 ; i <= capacity ; i++)
                {
                    next = getNextCandidateIndex(key, i);
                    if(next >= capacity )
                        next = next % capacity ;

                    if(hashArray[next].status == 2 && hashArray[next].key == key)
                    {
                       
                        hashArray[next].status = 1 ;
                        currentElements--;
                        cout<<"Deleted at idx : "<<next<<" : current size : "<<currentElements << endl;
                        currentElements--;
                        return true ;
                    }
                }
            }
            
        }
        return false ;
        
    }
    v* get(int const key)
    {
        if(currentElements > 0 )
        {
        
            int idx = Hash(key, capacity) ;
            if( hashArray[idx].key == key )
            {
                if(hashArray[idx].status !=1)
                {
                   // cout<<"idx : "<<idx<<endl;
                    v* obj = &hashArray[idx].value ;
                    return obj ;
                }
            }
            else
            {
                int  next = 0 ;
                for(int i = 1 ; i <= capacity ; i++)
                {
                    next = getNextCandidateIndex(key, i);
                    if(next >= capacity )
                        next = next % capacity ;

                    if( hashArray[next].key == key )
                        if(hashArray[next].status !=1)
                        {
                            
                            //cout<<hashArray[next].key<<"  : idx : "<<next<<endl;
                            v* obj = &hashArray[next].value ;
                            return obj ;
                        }

                }
            }
        }
        return nullptr ;
    }
    void print()
    {
        for(int i = 0 ; i < capacity ; i++)
        {
            if(hashArray[i].status == 2)
                cout<<"-> ( "<<i<<" ), key : "<<hashArray[i].key<<" , Value : "<<hashArray[i].value <<endl;
        }
    }
    ~HashMap()
    {
        if(hashArray!=nullptr)
            delete []hashArray ;
        
    }
};
template<typename T>
class QHashMap : public HashMap<T>{
    
    int getNextCandidateIndex(int key, int i)
    {
        return this->Hash(key,HashMap<T> :: capacity) + (i*i);
    }
public:
    QHashMap() : HashMap<T>(){}
    QHashMap(int const capacity_) : HashMap<T>(capacity_){}
    ~QHashMap()
    {
        ~HashMap<T>() ;
    }

    
    
};

int getPrime(int cap)
{
   
    int random = rand()% cap ;
    if(random < 2)
        return random +2 ;
    else if(random == 2)
        return random ;
    else if(random % 2 == 0)
        random = random + 1 ;
    
    bool flag = 0 ;
    for(int i = 2 ; i < random ; i++)
    {
        if(random % i == 0)
        {
            flag = 1 ;
            break ;
        }
    }
    if(flag == 0)
        return random ;
    else
        return getPrime(cap);
    
}
template<typename T>
class DHashMap : public HashMap<T>{
    
    int getNextCandidateIndex(int key, int i)
    {
        int first_value = this->Hash(key,HashMap<T> :: capacity) ;
        int prime =  getPrime(HashMap<T> :: capacity);
        int second_value = prime - this->Hash(key,prime) ;
        return  this->Hash(first_value + (i*second_value),HashMap<T> :: capacity );
    }
public:
    DHashMap() : HashMap<T>(){}
    DHashMap(int const capacity_) : HashMap<T>(capacity_){}
    ~DHashMap()
    {
        ~HashMap<T>() ;
    }

    
    
};
void populateHash(string filename, HashMap<string> *hash)
{
    ifstream fin(filename);
    int rool;
    string name;
    while(fin.eof()==0)
    {
        fin >> rool;
        fin >> name;
        cout<<name<<endl;
        hash->insert(rool, name);
    }
    fin.close();
}



int main()
{
    srand(time(0));
    HashMap<string> *map;
    map=new HashMap<string>;
    populateHash("students.txt", map);
    map->print();
    cout<<*map->get(9);
    map->deleteKey(9);
    assert(map->get(9)==nullptr);
    map->print();
    
    delete map;

        
    map=new QHashMap<string>;
    populateHash("students.txt", map);
    map->print();
    cout<<*map->get(98);
    map->deleteKey(98);
    assert(map->get(98)==nullptr);
    map->print();
    delete map;

    map=new DHashMap<string>;
    populateHash("students.txt", map);
    map->print();
    cout<<*map->get(101);
    map->deleteKey(101);
    assert(map->get(101)==nullptr);
    map->print();
    delete map;

    return 0;


}
