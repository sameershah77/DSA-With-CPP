#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
            vector<int> ans;
            set<int> st;
            int i=0;
            int j=0;
            int k=0;
            
            while(i<n1 && j<n2 && k<n3) {
                if(A[i]==B[j] && B[j]==C[k]) {
                    st.insert(A[i]);
                    i++;
                    j++;
                    k++;
                } else if(A[i] < B[j]) {
                    i++;
                } else if(B[j] < C[k]) {
                    j++;
                } else {
                    k++;
                }
            }
            for(auto i:st) {
                ans.push_back(i);
            }
            return ans;
        }
int main() {
    int n1 = 5;
    int n2 = 5;
    int n3 = 5;
    int A[] = {1,2,3,4,5};
    int B[] = {4,5,10,20,30};
    int C[] = {1,2,4,5,10};
   vector<int> ans = commonElements(A,B,C,n1,n2,n3);

   for(auto val:ans) {
    cout<<ans[val]<<" ";
   }
}

