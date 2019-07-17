//
// Created by General Automatic on 2019-07-16.
//

#include "Leadings.h"
#include "../Utilities/SuperUtilities.h"

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
