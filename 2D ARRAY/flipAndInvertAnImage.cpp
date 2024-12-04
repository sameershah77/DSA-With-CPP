#include<iostream>
#include<vector>
using namespace std;


int main() {

    

    int row;
    int col;
    cout<<"Enter the size of row :- ";
    cin>>row;

    cout<<"Enter the size of coloumn :- ";
    cin>>col;

    cout<<"Please enter only '0' or '1'"<<endl;
    cout<<"Insert Elements in your "<<row<<" * "<<col<<" Matrix :- "<<endl;
    vector<vector<int> > image (row,vector<int>(col));
       for(int i=0; i<image.size(); i++) {
        for(int j=0; j<image[0].size(); j++) {
            cin>>image[i][j];
        }
        cout<<endl;
    }

    cout<<"Your Original Matrix is :- "<<endl;

    
        for(int i=0; i<image.size(); i++) {
            for(int j=0; j<image[0].size(); j++) {
                cout<<image[i][j]<<" ";
            }
        cout<<endl;
        }

     row = image.size();
        col = image[0].size();
        int size = image.size();


        for(int i=0; i<size; i++) {
            for(int j=0; j<size/2; j++ ) {
                int temp = 0;
                temp=image[i][j];
                image[i][j]=image[i][size-1-j];
                image[i][size-1-j]=temp;
            }
        }

        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if( image[i][j]==1) {
                    image[i][j] = 0;
                }
                else {
                    image[i][j] = 1;
                }
            }
        }

        cout<<"Your Fliped  and Invertd Martix is :- "<<endl;
        for(int i=0; i<image.size(); i++) {
            for(int j=0; j<image[0].size(); j++) {
                cout<<image[i][j]<<" ";
            }
        cout<<endl;
        }





}