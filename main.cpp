#include <bits/stdc++.h>
using namespace std;

/* Name: Youssif Hisham Mahmoud
 * ID : 20200675
 * Group : A
 * Section : S3,4
*/

class Student{
private:
    string studName;
    char group;
    int ID, numberofsubjectspassed;
    string *passedsubjects;
    int notpassedsubjects;
    static int studentcount;

public:
    void set_NAME(string n){studName = n;};
    void set_GROUP(char grp){group = grp;};
    void set_ID(int id){ID = id;};
    void set_NOOFSUBJECTS(int number){numberofsubjectspassed = number;};
    void set_passing(string s[]){
        passedsubjects = new string[notpassedsubjects];
        for(int i=0; i<notpassedsubjects; i++)
        {
            passedsubjects[i] = s[i];
        }
    }


    string get_NAME(){return studName;};
    int get_ID(){return ID;};
    char get_GROUP(){return group;};
    int get_notpassed(){return notpassedsubjects;};
    void get_passed(){
        for(int i=0; i<notpassedsubjects; i++)
        {
            cout << passedsubjects[i] <<" ";
        }
        cout << endl;
    }


    Student(){
        passedsubjects = new string;
    }
Student(string name, int id, char grp, int num, string subjects[])
{
        studentcount++;
        studName = name;
        ID = id;
        group = grp;
        notpassedsubjects = num;
        passedsubjects = new string[notpassedsubjects];
        for(int i=0; i<notpassedsubjects; i++)
        {
            passedsubjects[i] = subjects[i];
        }
}

Student(Student& obj)
{
        studName = obj.studName;
        ID = obj.ID;
        group = obj.group;
        notpassedsubjects = obj.notpassedsubjects;
        passedsubjects = new string[obj.notpassedsubjects];
        for(int i=0; i<notpassedsubjects; i++)
        {
            passedsubjects[i] = obj.passedsubjects[i];
        }
}

~Student(){
        delete [] passedsubjects;
        studentcount--;
    }
};

int Student::studentcount = 0;
void printing(Student array[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << array[i].get_NAME() << endl;
        cout << "ID: " << array[i].get_ID() << endl;
        cout << "Group: " << array[i].get_GROUP() << endl;
        cout << "Number of passed subjects: " << array[i].get_notpassed();
        cout << "Passed Subjects: ";
        array[i].get_passed();
    }
}


int main() {
    string arr[] = {"Math-1", "Math-2", "Math-3", "OOP", "Network"};
    Student obj1("Youssif", 20200675, 'A', 5, arr);
    Student obj2 = obj1;
    Student array[] = {obj2,obj1};
    printing(array, 2);

    return 0;
}
