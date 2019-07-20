#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Model/Instructors.h"
#include "Model/Groups.h"
#include "Model/Subjects.h"
#include "Model/Rooms.h"
#include "Model/Hours.h"
#include "Model/Plan.h"
#include "Model/RoomSubject.h"

vector<Hours>definedHours;
vector<string>weekDays;
vector<Instructors>planInstructors;
vector<Groups>planGroups;
vector<Subjects>planSubjects;
vector<Rooms>planRooms;
vector<Leadings>planLeadings;
vector<RoomSubject>planRoomSubjects;
enum HourType {EARLY = 0, MIDDAY = 1, AFTERNOON =2 , EVENING = 3};
enum WeekDaysString {MONDAY,TUESDAY,W};
void initializeHours(){
    definedHours.push_back(Hours("07:30",1));
    definedHours.push_back(Hours("09:15",1));
    definedHours.push_back(Hours("10:30",1));
    definedHours.push_back(Hours("12:45",1));
    definedHours.push_back(Hours("14:30",1));
    definedHours.push_back(Hours("16:15",1));
    definedHours.push_back(Hours("17:45",1));
    definedHours.push_back(Hours("19:30",1));
    definedHours.push_back(Hours("21:15",1));
}
void initializeWeekDays(){
    weekDays.push_back("Monday");
    weekDays.push_back("Tuesday");
    weekDays.push_back("Wednesday");
    weekDays.push_back("Thursday");
    weekDays.push_back("Friday");
}

void initializeEvery(string address,const int type){
    ifstream file(address);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            switch (type){
                case 0:
                    planInstructors.push_back(Instructors((line)));
                    break;
                case 1:
                    planRooms.push_back(Rooms((line)));
                    break;
                case 2:
                    planGroups.push_back(Groups((line)));
                    break;
                case 3:
                    planLeadings.push_back(Leadings((line)));
                    break;
                case 4:
                    planSubjects.push_back(Subjects((line)));
                    break;
                case 5:
                    planRoomSubjects.push_back(RoomSubject((line)));
                    break;

            }
        }
        file.close();
    }
    else{
        cout<<"File is unable to open";
    }
}

void initializeData(){
    initializeHours();
    initializeWeekDays();
    initializeEvery("Database/instructors.txt",0);
    initializeEvery("Database/rooms.txt",1);
    initializeEvery("Database/groups.txt",2);
    initializeEvery("Database/leadings.txt",3);
    initializeEvery("Database/subjects.txt",4);
    initializeEvery("Database/roomSubject.txt",5);
}


using namespace std;
int main() {
    initializeData();
    Plan mainPlan(planRooms,definedHours,planInstructors,planSubjects,weekDays,planGroups,planLeadings,planRoomSubjects);
    mainPlan.generatePlan();
    mainPlan.showPlan();
    mainPlan.saveToFile("Database/results.txt");
    return 0;
}