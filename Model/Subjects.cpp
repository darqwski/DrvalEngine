//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Subjects.h"
#include "../Utilities/SuperUtilities.h"

const string &Subjects::getName() const {
    return name;
}

void Subjects::setName(const string &name) {
    Subjects::name = name;
}

const string &Subjects::getStudyField() const {
    return studyField;
}

void Subjects::setStudyField(const string &studyField) {
    Subjects::studyField = studyField;
}

int Subjects::getYear() const {
    return year;
}

void Subjects::setYear(int year) {
    Subjects::year = year;
}

int Subjects::getLectures() const {
    return lectures;
}

void Subjects::setLectures(int lectures) {
    Subjects::lectures = lectures;
}

int Subjects::getExercises() const {
    return exercises;
}

void Subjects::setExercises(int exercises) {
    Subjects::exercises = exercises;
}

int Subjects::getLaboratories() const {
    return laboratories;
}

void Subjects::setLaboratories(int laboratories) {
    Subjects::laboratories = laboratories;
}

int Subjects::getComputers() const {
    return computers;
}

void Subjects::setComputers(int computers) {
    Subjects::computers = computers;
}

int Subjects::getProjects() const {
    return projects;
}

void Subjects::setProjects(int projects) {
    Subjects::projects = projects;
}

Subjects::Subjects(string csvLine) {
    vector<string> items = split(csvLine,";");
    setName(items.at(0));
    setStudyField(items.at(1));
    setYear(stoi(items.at(2)));
    setLectures(stoi(items.at(3)));
    setLaboratories(stoi(items.at(4)));
    setExercises(stoi(items.at(5)));
    setComputers(stoi(items.at(6)));
    setProjects(stoi(items.at(7)));


}
