//
// Created by General Automatic on 2019-07-16.
//

#include "Leadings.h"
#include "../Utilities/SuperUtilities.h"
#include "Plan.h"

const Instructors &Leadings::getInstructor() const {
    return instructor;
}

void Leadings::setInstructor(const Instructors &instructor) {
    Leadings::instructor = instructor;
}

SubjectType Leadings::getType() const {
    return type;
}

void Leadings::setType(SubjectType type) {
    Leadings::type = type;
}
void Leadings::setType(string type) {
    Leadings::type = getSubjectType(type);
}

const Subjects &Leadings::getSubject() const {
    return subject;
}

Leadings::Leadings() {
}

Leadings::Leadings(const Instructors &instructor, SubjectType type, const Subjects &subject)  {
    setInstructor(instructor);
    setType(type);
    setSubject(subject);
}

void Leadings::setSubject(const Subjects &subject) {
    Leadings::subject = subject;
}

Leadings::Leadings(string basicString) {
    vector<string> items = split(basicString,";");
    this->instructorId=(items.at(0));
    this->subjectId=(items.at(1));
    this->setType(items.at(2));
}

const string &Leadings::getSubjectId() const {
    return subjectId;
}

void Leadings::setSubjectId(const string &subjectId) {
    Leadings::subjectId = subjectId;
}

const string &Leadings::getInstructorId() const {
    return instructorId;
}

void Leadings::setInstructorId(const string &instructorId) {
    Leadings::instructorId = instructorId;
}
