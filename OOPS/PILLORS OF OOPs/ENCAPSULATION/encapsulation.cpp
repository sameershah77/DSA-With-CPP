#include<iostream>
using namespace std;
class Person {
public:
    int id;
    string name;
    int age;

private:
    string email;
    string number;

public:
    // Constructor
    Person(int id, int age, string name, string email, string number) {
        this->age = age;
        this->id = id;
        this->name = name;
        this->email = email;
        this->number = number;
    }

    // Getter for email
    string getEmail() {
        return email;
    }

    // Setter for email
    void setEmail(string email) {
        this->email = email;
    }

    // Getter for number
    string getNumber() {
        return number;
    }

    // Setter for number
    void setNumber(string number) {
        this->number = number;
    }


    //public behaviours
    void sleeping() {
        cout<<this->name<<" is Sleeping"<<endl;
    }
    void studying() {
        cout<<this->name<<" is Studying"<<endl;
    }

private:
    void bunking() {
        cout<<this->name<<" is Bunking"<<endl;
    }

};

int main() {

    Person* person = new Person(1,22,"Sameer","sameershah9167@gmail.com","9167870411");

    //accessible attributes
    cout<<"age is "<<person->age<<endl;
    cout<<"name is "<<person->name<<endl;
    cout<<"id is "<<person->id<<endl;

    //accessible behaviours
    person->studying();
    person->sleeping();

    //unaccesible attributes
    // person->email;
    // person->number;
    // to access them
    cout<<"Hidden Email is "<<person->getEmail()<<endl;
    cout<<"Hidden number is "<<person->getNumber()<<endl;

    // to edit values of unccessible attributes
    person->setEmail("dsafaiz8100@gmail.com");
    person->setNumber("9702608500");
    cout<<"Hidden Email is "<<person->getEmail()<<endl;
    cout<<"Hidden number is "<<person->getNumber()<<endl;




    // if all the attributes(only) are private including id, name, age then This Encapsulation is called Perfect Encapsultaion. We have to make getter and setter for all the attributes to access.
    return 0;
}
