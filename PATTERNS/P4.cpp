#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the value of k :-";
    int k;
    cin>>k;
    for(int i=1;i <=k;i++) {
        for(int j=1;j <=k ;j++) {
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}