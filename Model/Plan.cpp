//
// Created by dariusz.cabala on 7/16/2019.
//

#include <iostream>
#include "Plan.h"

const vector<Rooms> &Plan::getRooms() const {
    return rooms;
}

void Plan::setRooms(const vector<Rooms> &rooms) {
    Plan::rooms = rooms;
}

const vector<Hours> &Plan::getHours() const {
    return hours;
}

void Plan::setHours(const vector<Hours> &hours) {
    Plan::hours = hours;
}

const vector<Instructors> &Plan::getInstructors() const {
    return instructors;
}

void Plan::setInstructors(const vector<Instructors> &instructors) {
    Plan::instructors = instructors;
}

const vector<Subjects> &Plan::getSubjects() const {
    return subjects;
}

void Plan::setSubjects(const vector<Subjects> &subjects) {
    Plan::subjects = subjects;
}

Plan::Plan(const vector<Rooms> &rooms, const vector<Hours> &hours, const vector<Instructors> &instructors,
           const vector<Subjects> &subjects, const vector<string> &weekDays) {
    this->rooms=rooms;
    this->subjects=subjects;
    this->hours=hours;
    this->instructors=instructors;
    this->weekDays=weekDays;
}

void Plan::showEmptyPlan() {
    for(int i=0;i<weekDays.size();i++)cout<<"        "<<weekDays.at(i)<<"      ";
    cout<<endl;
    for(int j=0;j<weekDays.size();j++){
        for(int k=0;k<rooms.size();k++){
            Rooms tempRoom = rooms.at(k);
            cout<<" "<<tempRoom.getNumber();
        }
        cout<<"|";
    }
    for(int i=0;i<hours.size();i++){
        for(int j=0;j<weekDays.size();j++){
            for(int k=0;k<rooms.size();k++){
                cout<<"E ";
            }
            cout<<"|";
        }
        cout<<endl;

    }

}

