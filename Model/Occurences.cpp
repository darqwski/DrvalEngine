//
// Created by General Automatic on 2019-07-16.
//

#include <iostream>
#include "Occurences.h"

const Subjects &Occurences::getSubject() const {
    return subject;
}

void Occurences::setSubject(const Subjects &subject) {
    Occurences::subject = subject;
}

SubjectType Occurences::getSubjectType() const {
    return subjectType;
}

void Occurences::setSubjectType(SubjectType subjectType) {
    Occurences::subjectType = subjectType;
}

const Leadings Occurences::getLeading() const {
    return leading;
}

void Occurences::setLeading(const Leadings leading) {
    Occurences::leading = leading;
}

const Groups &Occurences::getGroup() const {
    return group;
}

void Occurences::setGroup(const Groups &group) {
    Occurences::group = group;
}

const Rooms &Occurences::getRoom() const {
    return room;
}

void Occurences::setRoom(const Rooms &room) {
    Occurences::room = room;
}

const Hours &Occurences::getHour() const {
    return hour;
}

void Occurences::setHour(const Hours &hour) {
    Occurences::hour = hour;
}

int Occurences::getWeekDay() const {
    return weekDay;
}

void Occurences::setWeekDay(int weekDay) {
    Occurences::weekDay = weekDay;
}

bool Occurences::isFree() const {
    return free;
}

void Occurences::setFree(bool isFree) {
    Occurences::free = isFree;
}

Occurences::Occurences(const Rooms &room, const Hours &hour, int weekDay){
    setFree(true);
    setRoom(room);
    setHour(hour);
    setSubjectType(UNKNOWN);
    setWeekDay(weekDay);
    setShortSign("O");
}

Occurences::Occurences(const Groups group, const Subjects subject, SubjectType subjectType) {
    setGroup(group);
    setSubject(subject);
    setSubjectType(subjectType);
    setFree(true);

}

const string &Occurences::getShortSign() const {
    return shortSign;
}

void Occurences::setShortSign(const string &shortSign) {
    Occurences::shortSign = shortSign;
}
string Occurences::getCsvLine(){
    string mainLine="";
    mainLine+=leading.getSubjectId()+";"+leading.getInstructorId()+";";
    mainLine+=group.getName()+";";
    mainLine+=room.getNumber()+";";
    mainLine+=getSubjectTypeString(subjectType)+";";
    mainLine+=hour.getText()+";";
    mainLine+=to_string(getWeekDay());
    return mainLine;
}
