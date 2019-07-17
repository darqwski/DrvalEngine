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
#include "Occurences.h"

using namespace std;
class Plan {
    vector<Rooms> rooms;
    vector<Hours> hours;
    vector<Instructors> instructors;
    vector<Subjects> subjects;
    vector<string> weekDays;
    vector<Occurences> planMatrix;
    vector<Groups>groups;
public:
    const vector<Groups> &getGroups() const;

    void setGroups(const vector<Groups> &groups);

public:
    Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
         const vector<Subjects> &subjects, const vector<string> &weekDays,const vector<Groups> &groups);

public:
    Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
         const vector<Subjects> &subjects);

    void showPlan();
public:
    const vector<Rooms> &getRooms() const;

    void setRooms(const vector<Rooms> &rooms);

    const vector<Hours> &getHours() const;

    void setHours(const vector<Hours> &hours);

    const vector<Instructors> &getInstructors() const;

    void setInstructors(const vector<Instructors> &instructors);

    const vector<Subjects> &getSubjects() const;

    void setSubjects(const vector<Subjects> &subjects);

    int calculateMinimalWidth();

    string buildHeader(string weekName);

    vector<Occurences>
    generatePlanMatrix(const std::vector<string> &vector, const std::vector <Hours> &hours, const std::vector <Rooms> &rooms);

    int getRoomDayHourAddress(int room, int day, int hour);

    void fillPlanMatrix(vector<Occurences> vector);

    bool anotherGroupHasClasses(Occurences plan, Occurences occurence);
};


#endif //DRVALENGINE_PLAN_H
