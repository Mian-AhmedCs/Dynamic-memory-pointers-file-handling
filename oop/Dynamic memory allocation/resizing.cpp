#include <iostream>
using namespace std;
int* realloc(int * old , int oldsize , int newsize)
{
    int * newarr = new int[newsize];
    int limit;
    if(oldsize < newsize)
    {
        limit = oldsize;
    }
    else
    {
        limit = newsize;
    }
    for(int i =0 ; i < limit ; i++)
    {
        newarr[i] = old[i];
    }
    return newarr;
}
int main()
{
    int size;
    cout<<"size of old";
    cin>>size;
    int * old = new int[size];
    for(int i =0 ; i < size ; i++)
    {
        cout<<"enter element "<<i<<": ";
        cin>>old[i];
    }
    int newsize;
    cout<<"size of new";
    cin>>newsize;
    int * arr = new int[newsize];
    arr = realloc(old,size,newsize);
    for(int i =0 ; i < newsize ; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}