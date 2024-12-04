#include<iostream>
#include<vector>
using namespace std;

// Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.

// Example 1:

// Input: s = "owoztneoer"
// Output: "012"
// Example 2:

// Input: s = "fviefuro"
// Output: "45"

// Constraints:

// 1 <= s.length <= 105
// s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
// s is guaranteed to be valid.

    string originalDigits(string s) {

        vector<int> arr(26);
        for(auto val: s) {
            arr[val-'a']++;
        }

        int zero = arr[25];
        int one = arr[14] - arr[20] - arr[22] - arr[25];
        int two = arr[22];
        int three = arr[7] - arr[6]; 
        int four = arr[20];
        int five = arr[5] - arr[20];
        int six = arr[23];
        int seven = arr[18] - arr[23];
        int eight = arr[6];
        int nine = arr[8] - arr[23] - arr[6] - arr[5] + arr[20];

        vector<int> numbers;
        numbers.push_back(zero);
        numbers.push_back(one);
        numbers.push_back(two);
        numbers.push_back(three);
        numbers.push_back(four);
        numbers.push_back(five);
        numbers.push_back(six);
        numbers.push_back(seven);
        numbers.push_back(eight);
        numbers.push_back(nine);

        string ans = "";

        for(int i=0; i<10; i++) {
            while(numbers[i] > 0) {
                ans += (i + '0');
                numbers[i]--;
            }
        }
        return ans;

    }
int main() {
    string s = "owoztneoer";

    string ans = originalDigits(s);

    cout<<"Answer is "<<ans<<endl;
}


// logic for above question

// A	1
// B	2
// C	3
// D	4
// E	5
// F	6
// G	7
// H	8
// I	9
// J	10
// K	11
// L	12
// M	13
// N	14
// O	15
// P	16
// Q	17
// R	18
// S	19
// T	20
// U	21
// V	22
// W	23
// X	24
// Y	25
// Z	26

// Zero	One
// Two	Three
// Four	Five
// Six	Seven
// Eight	Nine

// z->0
// w->2
// U->4
// x->6
// g->8

// One
// Three
// Five
// Seven
// Nine

// o->1
// h->3
// f->5
// s->7

// Nine	

// i-9

// 0->occ of Z
// 1-> occ of O - occ of U - occ of W - occ of Z
// 2->occ of W
// 3-> occ of H - occ of G
// 4->occ of U
// 5->occ of F - occ of U
// 6->occ of X
// 7-> occ of S - occ of X
// 8-> occ of G
// 9-> occ of I - occ of X - occ of G - occ of F + occ of U
