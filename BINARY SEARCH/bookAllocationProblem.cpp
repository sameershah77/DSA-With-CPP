#include<iostream>
using namespace std;



// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
    bool isPossibleSolution(int A[], int N, int M, int sol) {
        int count = 1;
        int pageSum = 0;
        for(int i=0; i<N; i++) {
            if(A[i] > sol) {
                return false;
            }
            
            if(A[i] + pageSum > sol) {
                pageSum = A[i];
                count++;
                
                if(count > M) {
                    return false;
                }
            }
            else {
                pageSum += A[i];
            }
        }
        return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        //code here
        
        if(M > N) { // students is more then books 
            return -1;
        }
        int start = 0;

        int sum = 0;
        for(int i=0; i< N; i++) {
            sum += A[i];
        }
        int end = sum;
        
        int mid = start + (end - start)/2;
        int ans = -1;
        while(start <= end) {
            
            if(isPossibleSolution(A,N,M,mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
int main() {

    int N = 4;
    int A[] = {12,34,67,90};
    int M = 2;

    cout<<"Answer is "<<findPages(A,N,M);

}