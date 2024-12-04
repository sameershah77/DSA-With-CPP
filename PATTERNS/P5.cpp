#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the value of k :-";
    int k;
    cin>>k;
    int x=1;
    for(int i=1;i <=k;i++) {
        for(int j=1;j <=k ;j++) {
            cout<<" ";
            cout<<x;
            cout<<" ";
            x++;
        }
        cout<<endl;
    }

    return 0;
}