#include <iostream>
#include <ctime> 

using namespace std;

/*Make a function which write marks of all students */

void printGrades(int** grades , int x , int y) {
    cout << "Marks of students :\n";
    for (int i = 0; i < x; ++i) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < y; ++j) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    /*Make a part of code where we make two value one is a num of students and second num of subjects*/
    int x , y = 0;

    cout << "Write a num of students : " << endl;
    cin >> x;
    cout << "Write a num of subjects : " << endl;
    cin >> y;

    /*Create a part of dynamic memory 2d  massive*/

    int** grades = new int*[x];
    for (int i = 0; i < x; i++) {
        grades[i] = new int[y];
    }

    /*create marks for students*/

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            grades[i][j] = rand() % 12 + 1;
        }
    }


    printGrades(grades , x , y);

    //Make a value which count a num of students with average marks over 9
    int excellentStudents = 0;
    //Мой словарный запас закончилсся на данном моменте
    //Создаем цикл для подсчета среднего арифметического оценок у уеников
    for (int i = 0; i < x; ++i) {
        double average = 0; 
        double  sum = 0;
        /*После того как создали две переменные , 
        одна из которых будет считать общую сумму всех оценок ученика,
        а вторая которая будет считать среднюю арифметическую лценок ученикам.
        Создаем цикл который будет считать сумму оценок ученика,
        а потом среднее арифметическое у ученика*/
        for (int j = 0; j < y; ++j) {
            sum += grades[i][j];
        }
        average = sum / y;
        cout << "Average marks of student  " << i + 1 << ": " << average << endl;

        /*Делаем оператор розгалуження 
        где показывается что студент 
        со среднем арифметическим 6 провалил учебный год,
        а ученик получивший 9  и выше прибавляет единицу к переменной
        которая подсчитывает отличников в классе*/
        if (average < 6) {
            cout << "Student " << i + 1 << " dont pass!" << endl;
        }


        if (average > 8) {
            excellentStudents++;
        }

        /*Создаем переменную и цикл для подсчета тогочто бы понимать 
         ученник являеться отличником или же нет*/
        int highGradesCount = 0;
        for (int i = 0; i < x; ++i) {
            for(int j = 0; j < y ; j++)
            if (grades[i][j] > 9) {
                highGradesCount++;
            }
        }

        //Оператор розгалудження который проверяте то являеться ли ученник отличником 
        if (highGradesCount > y / 2) {
            cout << "Student " << i + 1 << " has a perfect marks! His mark more than nine: ";
            /*Создаем цикл который будет повторно выводить оценки 
            одного из учеников если тот является отличником*/
            for (int j = 0; j < y; ++j) {
                if (grades[i][j] > 9) {
                    cout << grades[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    //Оператор if , else который пишет что класс отличники 
    //если больше половины учеников имеют оценки 9  и выше
    if (excellentStudents > x / 2) {
        cout << "Class with perfect students !" << endl;
    }

    //Цикл который позволяет ученикам перездать провалившийся проект
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (grades[i][j] < 9) {
                cout << "Student " << i + 1 << ", his subject " << j + 1 << " has a mark like " << grades[i][j] << ". U have a thee attemp to pass this subjetc.\n";
                //Цикл который реализует перездачу когда у человека всего 3 попытки
                for (int attempt = 0; attempt < 3; ++attempt) {
                    int newGrade = rand() % 12 + 1;
                    cout << "Attemp " << attempt << ": ";
                    if (newGrade >= 9) {
                        grades[i][j] = newGrade;
                        cout << "u r new mark is  " << newGrade << endl;
                        break;
                    }
                    else {
                        cout << "Unluck" << endl;
                    }
                }
            }
        }
    }

    //Цикл который показывает что если у ученика все оценки меньше чем 9
    //То его оценки полностью будут выведенны на екран.
    for (int j = 0; j < y; ++j) {
        bool allBelowNine = true;
        for (int i = 0; i < x; ++i) {
            if (grades[i][j] >= 9) {
                allBelowNine = false;
                break;
            }
        }
        if (allBelowNine) {
            cout << "All students have a mark small then nine " << j + 1 << endl;
        }
    }
    //delete a dynamic 2d massive
    for (int i = 0; i < x; i++) {
        delete[]grades[i];
    }
    delete[]grades;
    grades = nullptr;
}