//
// Created by dariusz.cabala on 7/16/2019.
//

#ifndef DRVALENGINE_PLAN_H
#define DRVALENGINE_PLAN_H

#include <string>
#include <vector>
#include "Rooms.h"
#include "Hours.h"
#include "Instructors.h"
#include "Subjects.h"

using namespace std;
class Plan {
    vector<Rooms> rooms;
    vector<Hours> hours;
    vector<Instructors> instructors;
    vector<Subjects> subjects;
    vector<string> weekDays;
public:
    Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
         const vector<Subjects> &subjects, const vector<string> &weekDays);

public:
    Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
         const vector<Subjects> &subjects);

    void showEmptyPlan();
public:
    const vector<Rooms> &getRooms() const;

    void setRooms(const vector<Rooms> &rooms);

    const vector<Hours> &getHours() const;

    void setHours(const vector<Hours> &hours);

    const vector<Instructors> &getInstructors() const;

    void setInstructors(const vector<Instructors> &instructors);

    const vector<Subjects> &getSubjects() const;

    void setSubjects(const vector<Subjects> &subjects);

};


#endif //DRVALENGINE_PLAN_H
