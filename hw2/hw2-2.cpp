#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Student
{
public:
    string name;
    unsigned long int grade;

    Student(const string name, const unsigned long int grade)
    {
        this->name = name;
        this->grade = grade;
    }
    bool operator>(const Student& other)
    {
        if(grade > other.grade) return true;
        if(grade == other.grade && name.compare(other.name) < 0) return true;

        return false;
    }
    bool operator<(const Student& other)
    {
        return !(*this > other);
    }
};

int partition(vector<Student> &arr, int low, int high)
{
    Student pivot = arr[high];                                  
    int i = low;
    for (int j = low; j < high; j++)
    {                        
        if (arr[j] > pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
} 


void sort(vector<Student> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long int studentCount;
    cin >> studentCount;

    if(studentCount < 1 || studentCount > pow(10,5)) return 1;
    
    vector<Student> students;
    for (size_t i = 0; i < studentCount; i++)
    {
        string name;
        cin >> name;

        if(name.length() < 1 || name.length() > 10) return 1;

        students.push_back(Student(name, 0));
    }
    
    for (size_t i = 0; i < studentCount; i++)
    {
        unsigned long int grade;
        cin >> grade;

        if(grade < 1 || grade > pow(10,5)) return 1;

        students[i].grade = grade;
    }

    sort(students, 0, studentCount-1);
    
    for (size_t i = 0; i < studentCount; i++)
    {
        cout << students[i].name << " " << students[i].grade << endl;
    }
    
    return 0;
}

// for (size_t i = 0; i < studentCount - 1; i++)
    // {
    //     for (size_t j = 0; j < studentCount - i - 1; j++)
    //     {
    //         if(studentGrades[j] < studentGrades[j + 1])
    //         {
    //             swap(studentGrades[j], studentGrades[j + 1]);
    //             swap(studentNames[j], studentNames[j + 1]);
    //         }
    //         else if(studentGrades[j] == studentGrades[j + 1])
    //         {
    //             if(studentNames[j].compare(studentNames[j + 1]) > 0) swap(studentNames[j], studentNames[j + 1]);
    //         }
    //     }
    // }