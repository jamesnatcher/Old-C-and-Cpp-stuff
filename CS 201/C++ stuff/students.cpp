#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
    private:
        string first_name;
        string last_name;
        int id;
    public:
        Student(string first_name, string last_name, int id);
        Student(string first_name, string last_name);
        void setname(string first_name, string last_name);
        string get_first_name();
        string get_last_name();
        void set_id(int id);
        int get_id();
        void print();
};
Student::Student(string first_name, string last_name, int id) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = id;
}
Student::Student(string first_name, string last_name){
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = -1;
}
string Student::get_first_name(){
    return this->first_name;
}
string Student::get_last_name(){
    return this->last_name;
}
void Student::set_id(int id){
    this->id = id;
}
int Student::get_id(){
    return this->id;
}
void Student::print() {
    cout << first_name << " " << last_name << " " << id << endl;
}

int main(void) {
    Student studentA = Student("Grace", "Hopper", 17);
    Student studentB = Student("Alan", "Turing", 42);
    Student studentC = Student("Joe", "Mama");
    vector<Student> students;

    students.push_back(studentA);
    students.push_back(studentB);
    students.push_back(studentC);
   
    students[0].print();
    students[1].print();
    students[2].print();

    return 0;
}
