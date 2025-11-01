#include<iostream>
using namespace std;

class student {
private:
    string name;
    int id;
    float grade;
    static int studentcount;

public:
    // default constructor
    student() {
        name = "unknown";
        id = 0;
        grade = 0.0;
        studentcount++;
    }

    // parameterized constructor
    student(string n, int i, float g) {
        name = n;
        id = i;
        grade = g;
        studentcount++;
    }

    void displayinfo() {
        cout << "Student name: " << name << endl;
        cout << "Student id: " << id << endl;
        cout << "Student grade: " << grade << endl;
    }

    void setgrade(float g) {
        if (g >= 0 && g <= 100)
            grade = g;
        else
            cout << "Grade invalid!" << endl;
    }

    string getname() { return name; }
    int getid() { return id; }
    float getgrade() { return grade; }

    static int getstudentcount() {
        return studentcount;
    }

    friend void updategrade(student &s, float newgrade);
};


int student::studentcount = 0;

// friend function
void updategrade(student &s, float newgrade) {
    if (newgrade >= 0 && newgrade <= 100)
        s.grade = newgrade;
    else
        cout << "Grade invalid!" << endl;
}
class instructor {
private:
    string name;
    int instructorid;

public:
    instructor() {
        name = "unknown";
        instructorid = 0;
    }

    instructor(string n, int iid) {
        name = n;
        instructorid = iid;
    }

    void displayinstructorinfo() {
        cout << "Instructor name: " << name << endl;
        cout << "Instructor id: " << instructorid << endl;
    }
};
class graduatestudent : public student {
private:
    string researchTopic;

public:
    graduatestudent(string n, int i, float g, string rT)
        : student(n, i, g) {
        researchTopic = rT;
    }

    void displayresearchinfo() {
        cout << "Graduate student name: " << getname() << endl;
        cout << "Graduate student id: " << getid() << endl;
        cout << "Graduate student grade: " << getgrade() << endl;
        cout << "Research Topic: " << researchTopic << endl;
    }
};


int main() {
    student s1;
    s1.displayinfo();

    student s2("Mahmoud", 233, 80);
    s2.displayinfo();

    cout << "---------------------------" << endl;
    cout << "Update the student grade:" << endl;
    s2.setgrade(95.5);
    cout << "New grade: " << s2.getgrade() << endl;
      cout << "---------------------------" << endl;
    instructor inst1;
    inst1.displayinstructorinfo();

    instructor inst2("Ahmed", 5678);
    inst2.displayinstructorinfo();

    cout << "---------------------------" << endl;

    updategrade(s2, 99.0);
    cout << "Grade after instructor update: " << s2.getgrade() << endl;

    graduatestudent g1("Sara", 300, 88.5, "Artificial Intelligence");
    g1.displayresearchinfo();

    cout << "Total students created: " << student::getstudentcount() << endl;

    return 0;
}


