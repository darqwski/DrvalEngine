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
#include "RoomSubject.h"

using namespace std;
class Plan {
    vector<Rooms> rooms;
    vector<Hours> hours;
    vector<Instructors> instructors;
    vector<Subjects> subjects;
    vector<string> weekDays;
    vector<Occurences> planMatrix;
    vector<Groups>groups;
    vector<Leadings>leadings;
    vector<RoomSubject> roomSubjects;
public:
    const vector<RoomSubject> &getRoomSubjects() const;

    void setRoomSubjects(const vector<RoomSubject> &roomSubjects);

public:
    const vector<Groups> &getGroups() const;

    void setGroups(const vector<Groups> &groups);

public:
    Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
         const vector<Subjects> &subjects, const vector<string> &weekDays,const vector<Groups> &groups,
         const vector<Leadings> &leadings,const vector<RoomSubject> &roomSubjects);

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

    int availableInstructor(Occurences plan, Occurences occurence);

    bool isInstructorFreeAtHour(Instructors instructor, int hour, int day);

    vector<Occurences> generateOccurences();

    bool occucerenceMayBeInRoom(Occurences &plan, Occurences &occurence);

    void generatePlan();

    bool saveToFile(string address);
};


#endif //DRVALENGINE_PLAN_H
