//
// Created by General Automatic on 2019-07-16.
//

#ifndef DRVALENGINE_OCCURENCES_H
#define DRVALENGINE_OCCURENCES_H


#include "Subjects.h"
#include "../Utilities/DrvalUtilities.h"
#include "Rooms.h"
#include "Hours.h"
#include "Groups.h"
#include "Leadings.h"

class Occurences {
public:
    const Subjects &getSubject() const;

    void setSubject(const Subjects &subject);

    SubjectType getSubjectType() const;

    void setSubjectType(SubjectType subjectType);

    const Leadings getLeading() const;

    void setLeading(const Leadings leading);

    const Groups &getGroup() const;

    void setGroup(const Groups &group);

    const Rooms &getRoom() const;

    void setRoom(const Rooms &room);

    const Hours &getHour() const;

    void setHour(const Hours &hour);

    int getWeekDay() const;

    void setWeekDay(int weekDay);


private:
    Leadings leading;
    Groups group;
    Rooms room;
    Hours hour;
    Subjects subject;
    SubjectType subjectType;
    string shortSign;
    int weekDay;
    bool free;
public:
    const string &getShortSign() const;

    void setShortSign(const string &shortSign);

private:
public:
    Occurences(const Rooms &room, const Hours &hour, int weekDay);

    Occurences(const Groups group, const Subjects subject, SubjectType subjectType);

    bool isFree() const;

    void setFree(bool isFree);

    string getCsvLine();
};


#endif //DRVALENGINE_OCCURENCES_H
