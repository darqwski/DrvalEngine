//
// Created by dariusz.cabala on 7/16/2019.
//

#include <iostream>
#include "Plan.h"
#include <vector>
const int minWeekDayLength=9;

using namespace std;
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
           const vector<Subjects> &subjects, const vector<string> &weekDays, const vector<Groups> &groups) {
    this->rooms=rooms;
    this->subjects=subjects;
    this->hours=hours;
    this->instructors=instructors;
    this->weekDays=weekDays;
    setGroups(groups);
    planMatrix=generatePlanMatrix(weekDays,hours,rooms);
    vector<Occurences>occurences;
    for(int i=0;i<subjects.size();i++){
        for(int j=0;j<(subjects.at(i)).getLectures()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==LEC)
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),LEC));
        }
        for(int j=0;j<(subjects.at(i)).getExercises()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==EXE)
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),EXE));
        }
        for(int j=0;j<(subjects.at(i)).getLaboratories()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==LAB)
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),LAB));
        }
        for(int j=0;j<(subjects.at(i)).getComputers()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==CMP)
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),CMP));
        }
        for(int j=0;j<(subjects.at(i)).getProjects()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==PRO)
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),PRO));
        }
    }
    fillPlanMatrix(occurences);
}

void Plan::showPlan() {
    cout<<"| Days  ";
    for(int i=0;i<weekDays.size();i++)cout<<buildHeader(weekDays.at(i));
    cout<<endl;
    cout<<"| Rooms ";
    for(int j=0;j<weekDays.size();j++){
        cout<<"|";
        for(int k=0;k<rooms.size();k++){
            Rooms tempRoom = rooms.at(k);
            cout<<" "<<tempRoom.getNumber();
        }
        cout<<"|";
    }

    cout<<endl;
    for(int i=0;i<hours.size();i++){
        cout<<"| "<<(hours.at(i)).getText()<<" ";
        for(int j=0;j<weekDays.size();j++){
            cout<<"|";
            for(int k=0;k<rooms.size();k++){
                cout<<" ";
                cout<<(planMatrix.at(getRoomDayHourAddress(k,j,i))).getShortSign();
                if((rooms.at(k)).getNumber().length()==2){
                    cout<<" ";
                }
                if((rooms.at(k)).getNumber().length()==3){
                    cout<<"  ";
                }
                if((rooms.at(k)).getNumber().length()==4){
                    cout<<"   ";
                }
            }
            cout<<"|";
        }
        cout<<endl;

    }

}

int Plan::calculateMinimalWidth() {
    int forRooms = 0;
    int forWeekDays= (minWeekDayLength+2)*weekDays.size();
    for(int i=0;i<(rooms.size());i++){
        forRooms+=((rooms.at(i).getNumber()).length()+1);
    }
    forRooms*=weekDays.size();
    return (forWeekDays<forRooms)?forRooms:forWeekDays;
}

string Plan::buildHeader(string weekName) {
    int columnWidth=calculateMinimalWidth()/5;
    string header="|";
    for(int i=0;i<(columnWidth-weekName.length())/2;i++){
        header+=" ";
    }
    header+=weekName;
    for(int i=0;i<(columnWidth-weekName.length())/2;i++){
        header+=" ";
    }
    if(columnWidth%2!=weekName.length()%2){
        header+=" ";
    }
        header+="|";

    return header;
}
int Plan::getRoomDayHourAddress(int room,int day, int hour){
    return hour*weekDays.size()*rooms.size()+day*rooms.size()+room;
}
vector<Occurences>
Plan::generatePlanMatrix(const vector<string> &vector, const std::vector<Hours> &hours, const std::vector<Rooms> &rooms) {
    std::vector<Occurences> allOccurences;
    for(int i=0;i<hours.size();i++){
        for(int j=0;j<weekDays.size();j++){
            for(int k=0;k<rooms.size();k++){
                allOccurences.push_back(Occurences(rooms.at(k),hours.at(i),(j)));
            }
        }
    }
    for(int i=0;i<weekDays.size();i++){
        for(int j=0;j<rooms.size();j++){
        }
    }
    return allOccurences;
}

const vector<Groups> &Plan::getGroups() const {
    return groups;
}

void Plan::setGroups(const vector<Groups> &groups) {
    Plan::groups = groups;
}

void Plan::fillPlanMatrix(vector<Occurences> occurences) {
    for(int i=0;i<occurences.size();i++){
        cout<<occurences.at(i).getSubject().getName()<<endl;
        for(int j=0;j<planMatrix.size();j++){
            if(planMatrix.at(j).getRoom().getMainType()==occurences.at(i).getSubjectType()
                &&planMatrix.at(j).isFree()
                &&anotherGroupHasClasses(planMatrix.at(j),occurences.at(i))){
                planMatrix.at(j).setGroup(occurences.at(i).getGroup());
                planMatrix.at(j).setSubject(occurences.at(i).getSubject());
                planMatrix.at(j).setFree(false);
                switch(occurences.at(i).getSubjectType()){
                    case LAB:
                        planMatrix.at(j).setShortSign("L");
                        break;
                    case LEC:
                        planMatrix.at(j).setShortSign("W");
                        break;
                    case CMP:
                        planMatrix.at(j).setShortSign("K");
                        break;
                    case EXE:
                        planMatrix.at(j).setShortSign("C");
                        break;
                    case PRO:
                        planMatrix.at(j).setShortSign("P");
                        break;
                    case UNKNOWN:
                        planMatrix.at(j).setShortSign("X");
                        break;
                }
                cout<<"TYPE:"<<planMatrix.at(j).getShortSign()<<endl;
                break;
            }
        }

    }

}
bool Plan::anotherGroupHasClasses(Occurences plan, Occurences occurence){
    for(int i=0;i<groups.size();i++){
        Groups currGroup=groups.at(i);
        if(currGroup.getGroupType()==occurence.getSubjectType())continue;
        int hourNumber=0;
        for(int j=0;j<hours.size();j++)if(hours.at(j).getText()==plan.getHour().getText()){
                hourNumber=j;break;

        }
        cout<<getRoomDayHourAddress(0,plan.getWeekDay(),hourNumber)<<endl;
        cout<<plan.getWeekDay()<<hourNumber<<endl;
        for(int j=0;j<rooms.size();j++){
            if(planMatrix.at(getRoomDayHourAddress(j,2,hourNumber)).getGroup().getGroupType()!=occurence.getSubjectType()&&
                    planMatrix.at(getRoomDayHourAddress(j,2,hourNumber)).getGroup().getGroupType()!=UNKNOWN)
            {
                return false;
            }
        }
    }
    return true;
}
