#include <iostream>
using namespace std;
class bag
{
    private:
    int data[100];
    int used;
    public:
     bag()
    {
        used =0;
    }
    bag(int d[],int u)
    {
        used = u;
        for(int i =0 ; i < u;i++)
        {
               data[i] = d[i];
        }
    }
    // void getused(int use)
    // {
    //     used = use;
    // }
    // void getvalue(int value)
    // {
    //     data[used] = value;
    //     used++;
    // }
    void display()
    {
        for(int i =0; i < used;i++)
        {
            cout<<data[i]<<endl;
        }
    }
    void counttotal()
    {
          cout<<"The total count is "<<used<<endl;
    }
    int countinteger(int value)
    {
        int count =0;
        for(int i  =0 ; i < used;i++)
        {
            if(data[i] == value)
            {
                    count++;
            }
        }
        return count;
    }
   void removevalue(int value)
    {
        for(int i = 0; i < used;i++)
        {
            if(data[i] == value)
            {
                data[i] = data[used-1];
                used--;
            }
        }
    }
    int countchange()
    {
        return used;
    }
    bag operator+(const bag&other)
    {
        bag result;
        for(int i =0 ; i < used;i++)
        {
            result.data[result.used] = data[i];
            result.used++;
        }
        for(int i =0 ; i < other.used; i++)
        {
            result.data[result.used] =  other.data[i];
            result.used++;     
        }
        return result;
        
    }
};
int main()
{
    int arr1[] = {1,2,3,3,5};
    bag b(arr1,5);
    int arr2[] = {2,3,4,5,6};
    bag b1(arr2 ,5);

    // b.display();
    // b.counttotal();
    // cout<<b.countinteger(3)<<endl;
    // b.removevalue(2);
    // b.display();
    // cout<<b.countchange()<<endl;
    bag b3;
    b3 = b + b1;
    b3.display();
    b3.counttotal();
    
    return 0;
}