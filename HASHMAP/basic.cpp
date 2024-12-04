#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    //creation
            //first vlaue is key & second value is value
    unordered_map<string,int> m;


    
    //insertion

        //method 1
    pair<string,int> p1 = make_pair("Scorpio",9);
    m.insert(p1);

        //method 2
    pair<string,int> p2("BMW",10);
    m.insert(p2);

        //method 3
    m["Suzuki"] = 8;


    //access
        // method 1
    cout<<m.at("BMW")<<endl;


        //method 2
    cout<<m["Scorpio"]<<endl;



    //search
        //method 1
    if(m.count("BMW") == true) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Absent"<<endl;
    }

        //method 2

    if(m.find("BMW") == m.end()) {
        cout<<"Absent"<<endl;
        
    }
    else {
        cout<<"Present"<<endl;
    }


    //size

    cout<<"Size is "<<m.size()<<endl;

    //another concept
    cout<<m["Sameer"]<<endl;//agar yeh entry exist nahi karti map me toh pehle yeh map me store hogi and value iski by default 0  hogi and ab size 1 se increament ho chuka hoga 

    cout<<"Modified size is "<<m.size()<<endl;


    // iteration on map

    cout<<"Printing all elements of Map"<<endl;

    for(auto val: m) {
        cout<<val.first<<"->"<<val.second<<endl;
    }
    
}