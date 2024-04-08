#include <bits/stdc++.h>
using namespace std;


// Approach 1 using queue :)
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int n = students.size();
    int count_student_0 = 0, count_student_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i] == 0)
            count_student_0++;
        else
            count_student_1++;
    }
    queue<int> q_students;
    for (int i = 0; i < n; i++)
    {
        q_students.push(students[i]);
    }
    int i = 0;
    // traverse the sandwich and keep track of students
    while (!q_students.empty() && i < n)
    {
        int temp = sandwiches[i];

        if (temp == q_students.front())
        {
            q_students.pop();
            if (temp == 1)
                count_student_1--;
            else
                count_student_0--;
            i++;
        }
        else
        {
            if (temp == 1 && count_student_1 == 0)
                break;
            else if (temp == 0 && count_student_0 == 0)
                break;
            int temp2 = q_students.front();
            q_students.pop();
            q_students.push(temp2);
        }
    }
    return n - i;
}