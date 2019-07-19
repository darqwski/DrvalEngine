//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_SUBJECTS_H
#define DRVALENGINE_SUBJECTS_H
#include <string>
#include <vector>
using namespace std;

class Subjects {
private:
    string name,studyField,subjectId;
public:
    const string &getSubjectId() const;

    void setSubjectId(const string &subjectId);

private:
    int year,lectures,exercises,laboratories,computers,projects;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getStudyField() const;

    void setStudyField(const string &studyField);

    int getYear() const;

    void setYear(int year);

    int getLectures() const;

    void setLectures(int lectures);

    int getExercises() const;

    void setExercises(int exercises);

    int getLaboratories() const;

    void setLaboratories(int laboratories);

    int getComputers() const;

    void setComputers(int computers);

    int getProjects() const;

    void setProjects(int projects);

    Subjects(string csvLine);
    Subjects();

    friend bool operator==(const Subjects& s1, const Subjects& s2);

};


#endif //DRVALENGINE_SUBJECTS_H
