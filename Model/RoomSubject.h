//
// Created by General Automatic on 2019-07-19.
//

#ifndef DRVALENGINE_ROOMSUBJECT_H
#define DRVALENGINE_ROOMSUBJECT_H

#include <string>
#include "../Utilities/DrvalUtilities.h"

using namespace std;

class RoomSubject {
private:
    string subjectId, roomNumber;
    SubjectType subjectType;
public:
    SubjectType getRoomSubjectType() const;

    void setSubjectType(SubjectType subjectType);

    void setSubjectType(string subjectType);

public:
    const string &getSubjectId() const;

    void setSubjectId(const string &subjectId);

    const string &getRoomNumber() const;

    void setRoomNumber(const string &roomNumber);

    RoomSubject();

    RoomSubject(string csvLine);
};


#endif //DRVALENGINE_ROOMSUBJECT_H
