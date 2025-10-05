#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    int idx = findStudentByID(id);
    if (idx < 0) return;
    for (int i = idx; i < num_of_students - 1; ++i) {
        students[i] = students[i + 1];
    }
    --num_of_students;
}

void StudentManager::modifyStudent(const Student& student) {
    int idx = findStudentByID(student.getID());
    if (idx < 0) return;
    students[idx].updateRecord(student.getName().c_str(),
                               student.getRecord().getMidterm(),
                               student.getRecord().getFinal());
}

int StudentManager::findStudentByID(int id) const {
    for (int i = 0; i < num_of_students; ++i) {
        if (students[i].getID() == id)
            return i;
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    if (num_of_students == 0) return -1;
    int bestIndex = 0;
    float bestScore = students[0].getRecord().getMidterm();
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getMidterm() > bestScore) {
            bestScore = students[i].getRecord().getMidterm();
            bestIndex = i;
        }
    }
    return students[bestIndex].getID();
}

int StudentManager::findBestStudentInFinal() const {
    if (num_of_students == 0) return -1;
    int bestIndex = 0;
    float bestScore = students[0].getRecord().getFinal();
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getFinal() > bestScore) {
            bestScore = students[i].getRecord().getFinal();
            bestIndex = i;
        }
    }
    return students[bestIndex].getID();
}


int StudentManager::findBestStudent() const {
    if (num_of_students == 0) return -1;
    int bestIndex = 0;
    float bestScore = students[0].getRecord().getTotal();
    for (int i = 1; i < num_of_students; ++i) {
        if (students[i].getRecord().getTotal() > bestScore) {
            bestScore = students[i].getRecord().getTotal();
            bestIndex = i;
        }
    }
    return students[bestIndex].getID();
}

float StudentManager::getMidtermAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
        sum += students[i].getRecord().getMidterm();
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
        sum += students[i].getRecord().getFinal();
    return sum / num_of_students;
}


float StudentManager::getTotalAverage() const {
    if (num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < num_of_students; ++i)
        sum += students[i].getRecord().getTotal();
    return sum / num_of_students;
}

