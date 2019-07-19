//
// Created by General Automatic on 2019-07-16.
//

#ifndef DRVALENGINE_LEADINGS_H
#define DRVALENGINE_LEADINGS_H


#include "Instructors.h"
#include "../Utilities/DrvalUtilities.h"
#include "Subjects.h"

class Leadings {
public:
    Leadings();

    Leadings(const Instructors &instructor, SubjectType type, const Subjects &subject);

    Leadings(string basicString);

    const Instructors &getInstructor() const;

    void setInstructor(const Instructors &instructor);

    SubjectType getType() const;

    void setType(SubjectType type);

    const Subjects &getSubject() const;

private:
    Instructors instructor;
    SubjectType type;
    Subjects subject;
    string subjectId;
    string instructorId;
public:
    const string &getSubjectId() const;

    void setSubjectId(const string &subjectId);

    const string &getInstructorId() const;

    void setInstructorId(const string &instructorId);

    void setSubject(const Subjects &subject);

    void setType(string type);

private:
};


#endif //DRVALENGINE_LEADINGS_H
