#include <iostream>
using namespace std;

class HashTable
{
private:
int size;// Size will always be odd
int* arr;
int cResMethod;
int rh;
public:
    
    HashTable (int S,int Flag,int Coll)
    {
        if (S%2 == 0) //making sure size is odd.
            S++;
        
        size = S;
        rh = Flag;
        cResMethod = Coll;
        arr = new int[size];
        for (int i=0 ; i<size ; i++)
        {
            arr[i] = -1;
        }
    }

    int hashFunction(int val)
    {
        return (val % size) ;
    }

    void insert(int value)
    {
        if (rh == 1 && loadFactor() > 0.5)
            REHASH();
        
        int idx = hashFunction(value);
        if (arr[idx] == -1)
        {
            arr[idx] = value;
        }
        else //collision occured :(
        {
            //call collision resolving functions here.
            
            if (cResMethod == 1)
                idx = LinearProbing(idx);
            else if (cResMethod == 2)
                idx = LPSteps(idx, 3); //step size = 3.
            else if (cResMethod == 3)
                idx = PseudoRP(idx);
            else
                idx = doubleHashing(idx, value);
            
                    
            if (idx != -1)
                arr[idx] = value;

        }
    }

    void deleteVal(int val)
    {
        int idx = hashFunction(val);
        if (arr[idx] == val)
        {
            arr[idx] = -1;
        }
        else
        {
            if (cResMethod == 1)
                idx = LPF(idx,val);
            else if (cResMethod == 2)
                idx = LPSF(idx, 3,val); //step size = 3.
            else if (cResMethod == 3)
                idx = PRPF(idx,val);
            else
                idx = DHF(idx, val);
        }

        if (arr[idx] == val)
        {
            arr[idx] = -1;
        }
    }

    void updateVal(int val, int val2) //updates val1 to val2
    {
        int idx = hashFunction(val);
        if (arr[idx] == val)
        {
            arr[idx] = val2;
        }
        else
        {
            if (cResMethod == 1)
                idx = LPF(idx,val);
            else if (cResMethod == 2)
                idx = LPSF(idx, 3,val); //step size = 3.
            else if (cResMethod == 3)
                idx = PRPF(idx,val);
            else
                idx = DHF(idx, val);
        }
        
        if (arr[idx] == val)
        {
            arr[idx] = val2;
        }
    }

    int* Access(int val)
    {
        int* ptr = nullptr;
        int idx = hashFunction(val);
        if (arr[idx] == val)
        {
            ptr = &arr[idx];
            return ptr;
        }
        else
        {
            if (cResMethod == 1)
                idx = LPF(idx,val);
            else if (cResMethod == 2)
                idx = LPSF(idx, 3,val); //step size = 3.
            else if (cResMethod == 3)
                idx = PRPF(idx,val);
            else
                idx = DHF(idx, val);
        }
        
        if (arr[idx] == val)
        {
             ptr = &arr[idx]; //ptr points to the memory location of value.
        }
        return ptr;
    }

    
    int LinearProbing(int ColIdx) //method 1.
    {
        int i = ColIdx;
        if (ColIdx == size-1)
            ColIdx = 0;
        else
            ColIdx++;
        
        while (ColIdx != i)
        {
            if (arr[ColIdx] == -1) //empty space found.
                return ColIdx;
            else
            {
                if (ColIdx == size-1)
                    ColIdx = 0;
                else
                    ColIdx++;
            }
        }
        return -1; // no free index;
    }
    
    int LPF(int ColIdx, int val) //method 1.
    {
        int i = ColIdx;
        if (ColIdx == size-1)
            ColIdx = 0;
        else
            ColIdx++;
        
        while (ColIdx != i)
        {
            if (arr[ColIdx] == val) //Value found.
                return ColIdx;
            else
            {
                if (ColIdx == size-1)
                    ColIdx = 0;
                else
                    ColIdx++;
            }
        }
        return -1; //val not found;
    }
    
    int LPSteps(int ColIdx, int step) //method 2.
    {
        int i = ColIdx;
       
        do
        {
            if (arr[ColIdx] == -1) //empty space found.
                return ColIdx;
            else
            {
                if (ColIdx + step > size-1)
                    ColIdx = ColIdx + step - size ; //wraparound.
                else
                    ColIdx += step;
            }
        } while (ColIdx != i);
        return -1; // no free index;
    }
    
    int LPSF(int ColIdx, int step, int val)
    {
        int i = ColIdx;
       
        do
        {
            if (arr[ColIdx] == val) //empty space found.
                return ColIdx;
            else
            {
                if (ColIdx + step > size-1)
                    ColIdx = ColIdx + step - size ; //wraparound.
                else
                    ColIdx += step;
            }
        } while (ColIdx != i);
        return -1; // no free index;
    }
    
    int PseudoRP(int ColIdx) //Pseudo-random probing -- method 3.
    {
        int perm[] = {3, 2, 1, 4, 3, 8, 5, 7, 6, 9, 10, 12, 11, 14, 13, 16, 15, 18, 19, 17};
        int i = ColIdx;
        int stepSize = perm[ColIdx];
        
        ColIdx = LPSteps(i, stepSize);
        
        return ColIdx;
    }
    
    int PRPF(int ColIdx, int val)
    {
        int perm[] = {3, 2, 1, 4, 3, 8, 5, 7, 6, 9, 10, 12, 11, 14, 13, 16, 15, 18, 19, 17};
        int i = ColIdx;
        int stepSize = perm[ColIdx];
        
        ColIdx = LPSF(i, stepSize,val);
        
        return ColIdx;
    }
    
    int HF2(int key)
    {
        return ( 1+ key % (size-2));
    }
    
    int doubleHashing(int ColIdx,int key)
    {
        int i = ColIdx;
        int stepSize = HF2(key);
        
        ColIdx = LPSteps(i, stepSize);
        
        return ColIdx;
    }
    
    int DHF(int ColIdx,int val)
    {
        int i = ColIdx;
        int stepSize = HF2(val);
        
        ColIdx = LPSF(i, stepSize, val);
        
        return ColIdx;
    }
    
    float loadFactor()
    {
        float count = 0;
        
        for (int i=0 ; i<size ; i++)
        {
            if (arr[i] != -1)
                count++;
        }
        
        return count/size;
    }
    
    void REHASH()
    {
        HashTable temp(size*2+1,1,cResMethod);
        
        for (int i=0 ; i<size ; i++)
        {
            if (arr[i] != -1)
                temp.insert(arr[i]);
        }
        
        *this = temp;
    }
    
    
    void Print()
    {
        for (int i=0 ; i<size ; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
};


int main()
{
    HashTable myHashTable1(9,0,1);       //  Linear probing.
    myHashTable1.insert(4);
    myHashTable1.insert(3);
    myHashTable1.insert(8);
    myHashTable1.insert(11);
    myHashTable1.insert(12);
    myHashTable1.insert(9);
    myHashTable1.insert(1);
    
    myHashTable1.Print();
    
    myHashTable1.deleteVal(9);
    myHashTable1.updateVal(11, 2);
    myHashTable1.deleteVal(12);
    
    cout<<endl;
    myHashTable1.Print();

    cout<<endl<<endl;
    
    HashTable myHashTable2(9,0,2);      //  Linear probing with Steps.
    myHashTable2.insert(4);
    myHashTable2.insert(3);
    myHashTable2.insert(8);
    myHashTable2.insert(11);
    myHashTable2.insert(12);
    myHashTable2.insert(9);
    myHashTable2.insert(1);
    
    myHashTable2.Print();
    
    myHashTable2.updateVal(11, 2);
    myHashTable2.deleteVal(9);
    myHashTable2.deleteVal(12);
    
    cout<<endl;
    
    myHashTable2.Print();
    cout<<endl<<endl;
    
    HashTable myHashTable3(9,0,3);       //  Pseudo-random probing for collision resolution.
    myHashTable3.insert(4);
    myHashTable3.insert(8);
    myHashTable3.insert(3);
    myHashTable3.insert(13);
    myHashTable3.insert(12);
    myHashTable3.insert(9);
    myHashTable3.insert(1);
    
    myHashTable3.Print();
    
    myHashTable3.deleteVal(9);
    myHashTable3.updateVal(13, 2);
    myHashTable3.deleteVal(12);
    
    cout<<endl;
    myHashTable3.Print();
    cout<<endl<<endl;
    
    HashTable myHashTable4(9,0,4);      // Double hashing .
    myHashTable4.insert(4);
    myHashTable4.insert(8);
    myHashTable4.insert(3);
    myHashTable4.insert(13);
    myHashTable4.insert(12);
    myHashTable4.insert(9);
    myHashTable4.insert(1);
    
    myHashTable4.Print();
    
    myHashTable4.deleteVal(9);
    myHashTable4.updateVal(13, 2);
    myHashTable4.deleteVal(12);
    
    cout<<endl;
    myHashTable4.Print();
    cout<<endl<<endl;
    
    HashTable myHashTable5(9,1,1);       //  Linear probing.
    myHashTable5.insert(4);
    myHashTable5.insert(3);
    myHashTable5.insert(8);
    myHashTable5.insert(11);
    myHashTable5.insert(12);
    myHashTable5.insert(9);
    myHashTable5.insert(1);
    
    myHashTable5.Print();
    
    myHashTable5.deleteVal(9);
    myHashTable5.updateVal(11, 2);
    myHashTable5.deleteVal(12);
    
    cout<<endl;
    myHashTable5.Print();
    
    
    return 0;
}


