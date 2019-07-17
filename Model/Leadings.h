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

    const Instructors &getInstructor() const;

    void setInstructor(const Instructors &instructor);

    SubjectType getType() const;

    void setType(SubjectType type);

    const Subjects &getSubject() const;

private:
    Instructors instructor;
    SubjectType type;
    Subjects subject;
public:
    void setSubject(const Subjects &subject);

private:
    void setType(string type);
};


#endif //DRVALENGINE_LEADINGS_H
