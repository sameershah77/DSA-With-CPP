#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the value of k :-";
    int k;
    cin>>k;
    char x = 'A';
    for(int i=1;i <=k;i++) {
        for(int j=1;j <=i ;j++) {
            
            cout<<" "<<x<<" ";
            x++;
        }
        cout<<endl;
    }

    return 0;
}   