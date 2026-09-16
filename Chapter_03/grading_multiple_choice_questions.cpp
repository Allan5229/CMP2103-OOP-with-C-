#include <iostream>
using namespace std;

int main() {
    const int STUDENTS = 8;
    const int QUESTIONS = 10;

    char studentAnswers[STUDENTS][QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    char key[QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    cout << "Grading Multiple Choice Questions\n";
    cout << "--------------------------------\n";

    for (int student = 0; student < STUDENTS; ++student) {
        int correct = 0;

        for (int question = 0; question < QUESTIONS; ++question) {
            if (studentAnswers[student][question] == key[question]) {
                ++correct;
            }
        }

        cout << "Student " << student << ": " << correct << " out of "
             << QUESTIONS << " correct\n";
    }

    return 0;
}
