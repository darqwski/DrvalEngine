//
// Created by dariusz.cabala on 7/16/2019.
//

#include <iostream>
#include "Plan.h"
#include "Occurences.h"
#include <vector>
#include <fstream>
#include "../Utilities/DrvalUtilities.h"
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
           const vector<Subjects> &subjects, const vector<string> &weekDays, const vector<Groups> &groups,
           const vector<Leadings> &leadings, const vector<RoomSubject> &roomSubjects) {
    this->rooms=rooms;
    this->subjects=subjects;
    this->hours=hours;
    this->instructors=instructors;
    this->weekDays=weekDays;
    this->leadings=leadings;
    setGroups(groups);
    setRoomSubjects(roomSubjects);
    planMatrix=generatePlanMatrix(weekDays,hours,rooms);
}
void Plan::generatePlan(){
    vector<Occurences>occurences=generateOccurences();
    for(int i=0;i<leadings.size();i++){
        for(int j=0;j<instructors.size();j++){
            if(instructors.at(j).getId()==leadings.at(i).getInstructorId()){
                this->leadings.at(i).setInstructor(instructors.at(j));
                break;
            }
        }
        for(int j=0;j<subjects.size();j++){
            if(subjects.at(j).getSubjectId()==leadings.at(i).getSubjectId()){
                this->leadings.at(i).setSubject(subjects.at(j));
                break;
            }
        }
    }
    fillPlanMatrix(occurences);
}
vector<Occurences> Plan::generateOccurences(){
    vector<Occurences>occurences;

    for(int i=0;i<subjects.size();i++){
        for(int j=0;j<(subjects.at(i)).getLectures()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==LEC && subjects.at(i).getYear()==groups.at(k).getYear() && subjects.at(i).getStudyField() == groups.at(k).getStudyField())
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),LEC));
        }
        for(int j=0;j<(subjects.at(i)).getExercises()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==EXE&& subjects.at(i).getYear()==groups.at(k).getYear() && subjects.at(i).getStudyField() == groups.at(k).getStudyField())
                    occurences.push_back(Occurences(groups[k],subjects[i],EXE));
        }
        for(int j=0;j<(subjects.at(i)).getLaboratories()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==LAB&& subjects.at(i).getYear()==groups.at(k).getYear() && subjects.at(i).getStudyField() == groups.at(k).getStudyField())
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),LAB));
        }
        for(int j=0;j<(subjects.at(i)).getComputers()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==CMP&& subjects.at(i).getYear()==groups.at(k).getYear() && subjects.at(i).getStudyField() == groups.at(k).getStudyField())
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),CMP));
        }
        for(int j=0;j<(subjects.at(i)).getProjects()/WEEKINTERM;j++){
            for(int k=0;k<groups.size();k++)
                if(groups.at(k).getGroupType()==PRO&& subjects.at(i).getYear()==groups.at(k).getYear() && subjects.at(i).getStudyField() == groups.at(k).getStudyField())
                    occurences.push_back(Occurences(groups.at(k),subjects.at(i),PRO));
        }
    }
    return occurences;
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
        for(int j=0;j<planMatrix.size();j++){
            int availableLeadingIndex = availableInstructor(planMatrix.at(j),occurences.at(i));
            if(
                    occucerenceMayBeInRoom(planMatrix.at(j),occurences.at(i))
                &&planMatrix.at(j).isFree()
                &&anotherGroupHasClasses(planMatrix.at(j),occurences.at(i))
                &&availableLeadingIndex != -1){

                planMatrix.at(j).setGroup(occurences.at(i).getGroup());
                planMatrix.at(j).setSubject(occurences.at(i).getSubject());
                planMatrix.at(j).setLeading(leadings.at(availableLeadingIndex));
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
                //planMatrix.at(j).setShortSign(planMatrix.at(j).getShortSign()+leadings.at(availableLeadingIndex).getInstructor().getName().at(0));
                break;
            }
            if((j-1)==planMatrix.size()){
                cout<<"Nie ma możliwości dodania "<<occurences.at(i).getGroup().getStudyField()<<" "
                <<(occurences.at(i)).getGroup().getName()<<" "<<occurences.at(i).getSubject().getName()<<endl;
            }
        }

    }

}
int Plan::availableInstructor(Occurences plan, Occurences occurence){
    int hourNumber=0;

    for(int j=0;j<hours.size();j++){
        if(hours.at(j).getText()==plan.getHour().getText()){
            hourNumber=j;break;
        }
    }
    for(int i=0;i<leadings.size();i++){
        if((leadings.at(i)).getSubject().getSubjectId()==occurence.getSubject().getSubjectId() && leadings.at(i).getType()==occurence.getSubjectType()){
            bool isFree=isInstructorFreeAtHour(leadings.at(i).getInstructor(),plan.getWeekDay(),hourNumber);
            if(isFree){
                return i;
            }
        }
    }
    return -1;
}
bool Plan::isInstructorFreeAtHour(Instructors instructor, int day,int hour){
    for(int i=0;i<rooms.size();i++){
        if((planMatrix.at(getRoomDayHourAddress(i,day,hour))).getLeading().getInstructor()==instructor){
            return false;
        }
    }
    return true;
}
bool Plan::anotherGroupHasClasses(Occurences plan, Occurences occurence){
    for(int i=0;i<groups.size();i++){
        Groups currGroup=groups.at(i);
        if(currGroup.getGroupType()==occurence.getGroup().getGroupType() && !(currGroup==occurence.getGroup()))continue;
        int hourNumber=0;
        for(int j=0;j<hours.size();j++)if(hours.at(j).getText()==plan.getHour().getText()){
                hourNumber=j;break;
        }
        for(int j=0;j<rooms.size();j++){
            Groups currGroup=planMatrix.at(getRoomDayHourAddress(j,plan.getWeekDay(),hourNumber)).getGroup();
            if((currGroup.getGroupType()!=occurence.getGroup().getGroupType()&&currGroup.getGroupType()!=UNKNOWN) ||
                (currGroup == occurence.getGroup())) {
                  return false;
            }
        }
    }
    return true;
}

bool Plan::occucerenceMayBeInRoom(Occurences &plan, Occurences &occurence) {
    for(int i=0;i<roomSubjects.size();i++){
        if(roomSubjects[i].getSubjectId() == occurence.getSubject().getSubjectId()){
              if(roomSubjects[i].getRoomSubjectType()==occurence.getSubjectType()){
                return plan.getRoom().getNumber()== roomSubjects[i].getRoomNumber();
            }
        }

    }
    return plan.getRoom().getMainType()==occurence.getSubjectType();
}

bool Plan::saveToFile(string address){
    ofstream file(address);
    if (file.is_open()) {
        for(int i=0;i<planMatrix.size();i++){
            if(!planMatrix[i].isFree())file<<planMatrix[i].getCsvLine()<<endl;
        }
    }
    file.close();
    return true;

}

const vector<RoomSubject> &Plan::getRoomSubjects() const {
    return roomSubjects;
}

void Plan::setRoomSubjects(const vector<RoomSubject> &roomSubjects) {
    Plan::roomSubjects = roomSubjects;
}
