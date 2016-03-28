

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int locateMinimum( const string array[], int n);
int findLastOccurrence( const string array[], int n, string target);
int flipAround( string array[], int n);
bool hasNoDuplicates( const string array[], int n);
void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize );
bool isndup(string array[],int n, string dupcheck); //made for myself
int shiftRight( string array[ ], int n, int amount, string   placeholderToFillEmpties );
bool isInIncreasingOrder( const string array[ ], int  n );

bool isndup(string array[],int n, string dupcheck) //This help function checks that and individual string
                                                    //doesnt have a duplicate in a determined array
{
    for(int z = 0; z <= n; z++)
    {
        if (array[z] == dupcheck) return false;
    }
    return true;
}


int locateMinimum( const string array[], int n)
{
    if(n<=0) return -1;
    string small = array[0];
    
    for(int i = 1; i < n; i++)//incrementally checks that variable small is smalller than the other strings
    {
        if ( small > array[i])
        {
            small = array[i];
        }
            
    }
    for (int j = 0; j < n; j++) //This part returns the smallest index number of the smallest string
    {
        if (small == array[j]) return j;
    }
    return (-1);
}

int findLastOccurrence(const string array[], int n, string target)
{
    if(n<=0) return -1;
    for (int i = n - 1; i >= 0; i--) //we go backwards so that it reaches the largest index first
    {
        if (array[i] == target) //finds the target in the array
        {
            int index = i;
            
            return index;
        }
       
    }
    return (-1);
}

int flipAround(string array[], int n)
{
    if(n<=0) return -1;
    
    string arrayex; // uses arrayex to temporaryily store the flipping variable so we can replace it with the
                    //string it is being flipped with
    int counter = 0;
    for(int i = 0; i < n-1-i; i++)
    {
        arrayex = array[n-1-i];
        array[n-1-i] = array[i];
        array[i] = arrayex;
        counter++; //keeps track of the number of flips
        
    }
    return counter++;
}


bool hasNoDuplicates( const string array[], int n) //checks to make sure there are no repeating values
                                                    // in an array
{
    if (n < 0) return false;
    for( int i = 0; i < n; i++)
    {
        for( int j = 1; j < n; j++)
        {
            if ( i != j && array[i] == array [j]) return false;
        }
        
    }
    return true;
}

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ], int& resultingSize )
{
    int counter1 = 0;
    int counter2 = 0;
    if(n1 <= 0 || n2 <= 0) //ensures there are no nonsensical array sizes
    {
        resultingSize = -1;
        return;
    }
    
    
    resultingString[0] = array1[0];//since this is an original value it must be added
    for(int i = 0; i < n1; i++)// checks first aaray for duplicates then places them in resultingstring
    {
        for (int j = 0; j <= i; j++)
        {
            if (array1[i] == array1[j] && i != j) break;
            if (array1[i] == array1[j])
            {
                resultingString[i] = array1[j];
                counter1++;
            }
        }
    }
    //bool that checks if duplicate in the already reslutant string then just copy the above string
    
    for (int k = 0; k < n2; k++)//checks second array agaisnt itself and resultingString for duplicates
        //and then places it resultingstring, while counting size
    {
        if( isndup(resultingString, counter1 + counter2, array2[k]))
        {
            for (int m = 0; m <= k; m++)
            {
                if (array1[k] == array1[m] && k != m) break;
                if (array1[k] == array1[m])
                {
                    resultingString[k] = array1[m];
                    counter2++;
                }
            }
        }
    }
    resultingSize = counter1 + counter2;
}



//union with dupliicates use a counter and slowly dump numbers into the resulting array, which keeps filling

int shiftRight( string array[ ], int n, int amount, string   placeholderToFillEmpties )
{
    if(n<=0) return -1;
    int answer = 0;
    int counter = 0;
    if(n < amount || n < 0) return -1;//checks for nonsensical values of n
    string extra; //gives variable to temporarily store strings
    for(int i = 0; i < amount; i++)//moves strings over amount
    {
        if(i +amount < n)
        {
            extra = array[i+amount];
        array[i+amount] = array[i];
        }
        if (i + amount < n)
            array[i+amount+amount] = extra;
    }
    for(int i = 0; i < amount; i++)//fills empty moved spaces with a placeholder value

    {
        array[i] = placeholderToFillEmpties;
    }
    for(int i = 0; i < n; i++)//counts number of original values in resulting array
    {
        
        if (array[i] != placeholderToFillEmpties)
        counter++;
    }
    answer = counter;
    return answer;
}

bool isInIncreasingOrder( const string array[ ], int  n )//ensures the array is in increasing order of
                                                    //the numerical value of the string
{
    if (hasNoDuplicates(array, n))
    {
        for(int i = 0; i < n-1; i++)
        {
            if (array[i] > array[i+1]) return false;
        }
        return true;
    }
    return false;
}



int main()
{
    
    string a[5] = { "alpha", "beta", "gamma", "beta", "delta" };
    
    string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
    string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
    int answer;
    
    string output[6] = { " ", " ", " ", " ", " ", " "  };
    int outputSize = 6;

    assert(locateMinimum(h, 7 ) == 4);
    assert(locateMinimum(b, 3 ) == 2);
    
    assert(findLastOccurrence(a, 5, "beta" ) == 3);
    assert(findLastOccurrence(b, 3, "gamma" ) == 1);
    
    assert(hasNoDuplicates(a, 5) == false);
    assert(hasNoDuplicates(h, 6) == true);
    
    assert(isInIncreasingOrder(b, 2) == true);
    assert(isInIncreasingOrder(a, 6) == false);
    
    unionWithNoDuplicates(a, 5, b, 2, output, outputSize);
    assert( outputSize ==  4);
    assert( output[0] == "alpha" );
    
    answer = shiftRight(b, 6, 3, "foobar" );
    assert( answer == 3 );
    assert( b[0] == "foobar" );
    
    assert(flipAround(a, 5 ) == 2);
    assert(flipAround(a, 4 ) == 2);
    
    
    cerr << "All tests succeeded" << endl;
    return( 0 );
    
}
