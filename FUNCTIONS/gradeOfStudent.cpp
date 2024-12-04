#include<iostream>
using namespace std;

char grade(int marks) {
    if (marks > 100) {
       return 0;
    }

if(marks > 90) {
    return 'A';
}
else if(marks > 80) {
    return 'B';
}
else if(marks > 70) {
    return 'C';
}
else if(marks > 60) {
    return 'D';
}
else {
    return 'E';
}
    
    


}

int main () {
    cout<<"Enter the marks "<<endl;
    int marks;
    cin>>marks;
    char answer = grade(marks);
    
    cout<<"You Got " << answer;

    return 0;

}