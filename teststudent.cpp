#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Student Class
class Student
{
public:
    int rollNo;
    string name;
    int marks[3];

    Student() : rollNo(0), name("")
    {
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(int r, const string &n, int m1, int m2, int m3)
    {
        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
            throw invalid_argument("Marks must be between 0 and 100.");
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    double average() const
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Overload ++ to increment all marks by 1 (bonus)
    Student &operator++()
    {
        for (int i = 0; i < 3; ++i)
        {
            if (marks[i] < 100)
                marks[i]++;
        }
        return *this;
    }

    // Overload > to compare students by average marks
    bool operator>(const Student &other) const
    {
        return average() > other.average();
    }

    void display() const
    {
        cout << "Roll No: " << rollNo << ", Name: " << name
             << ", Marks: [" << marks[0] << ", " << marks[1] << ", " << marks[2]
             << "], Avg: " << average() << endl;
    }
};

// Gradebook Class
class GradeBook
{
    vector<Student> students;

public:
    GradeBook() {}

    void addStudent(const Student &s)
    {
        for (const auto &student : students)
        {
            if (student.rollNo == s.rollNo)
                throw invalid_argument("Duplicate roll number.");
        }
        students.push_back(s);
    }

    Student *search(int roll)
    {
        for (auto &student : students)
        {
            if (student.rollNo == roll)
                return &student;
        }
        return nullptr;
    }

    void updateMarks(int roll, int m1, int m2, int m3)
    {
        Student *s = search(roll);
        if (!s)
            throw runtime_error("Student not found.");
        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
            throw invalid_argument("Marks must be between 0 and 100.");
        s->marks[0] = m1;
        s->marks[1] = m2;
        s->marks[2] = m3;
    }

    void displayAll()
    {
        if (students.empty())
            throw runtime_error("GradeBook is empty.");
        for (const auto &student : students)
        {
            student.display();
        }
    }
};

int main()
{
    GradeBook gb;
    try
    {
        // Adding students
        gb.addStudent(Student(1, "Alice", 85, 90, 95));
        gb.addStudent(Student(2, "Bob", 70, 75, 80));

        // Display all students
        cout << "All Students:" << endl;
        gb.displayAll();

        // Search and update marks
        int roll = 1;
        Student *s = gb.search(roll);
        if (s)
        {
            cout << "\nUpdating marks for Roll No " << roll << endl;
            gb.updateMarks(roll, 88, 92, 96);
        }

        // Display again
        cout << "\nAfter Update:" << endl;
        gb.displayAll();

        // Compare two students
        Student *s1 = gb.search(1);
        Student *s2 = gb.search(2);
        if (s1 && s2)
        {
            cout << "\nComparison:" << endl;
            if (*s1 > *s2)
                cout << s1->name << " has a higher average than " << s2->name << endl;
            else
                cout << s2->name << " has a higher average than " << s1->name << endl;
        }

        // Increment marks of student 1
        cout << "\nIncrementing marks of " << s1->name << endl;
        ++(*s1);
        s1->display();

    }
    catch (const exception &ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}
