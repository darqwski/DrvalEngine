//
// Created by General Automatic on 2019-07-19.
//

#include "RoomSubject.h"
#include "../Utilities/SuperUtilities.h"

const string &RoomSubject::getSubjectId() const {
    return subjectId;
}

void RoomSubject::setSubjectId(const string &subjectId) {
    RoomSubject::subjectId = subjectId;
}

const string &RoomSubject::getRoomNumber() const {
    return roomNumber;
}

void RoomSubject::setRoomNumber(const string &roomNumber) {
    RoomSubject::roomNumber = roomNumber;
}
RoomSubject::RoomSubject() {

}

RoomSubject::RoomSubject(string csvLine) {
    vector<string> items = split(csvLine,";");
    setSubjectId(items[0]);
    setRoomNumber(items[1]);
    setSubjectType(items[2]);
}

SubjectType RoomSubject::getRoomSubjectType() const {
    return subjectType;
}

void RoomSubject::setSubjectType(SubjectType subjectType) {
    RoomSubject::subjectType = subjectType;
}

void RoomSubject::setSubjectType(string subjectType) {
    RoomSubject::subjectType = getSubjectType(subjectType);
}
