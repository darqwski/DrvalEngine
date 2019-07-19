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

vector<Hours>definedHours;
vector<string>weekDays;
vector<Instructors>planInstructors;
vector<Groups>planGroups;
vector<Subjects>planSubjects;
vector<Rooms>planRooms;
vector<Leadings>planLeadings;
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

void initializeRooms(){
    planRooms.push_back(Rooms("A1;LEC;EXE"));
    planRooms.push_back(Rooms("A2;LEC;EXE"));
    planRooms.push_back(Rooms("A3;LEC;EXE"));
    planRooms.push_back(Rooms("A4;LEC;EXE"));
    planRooms.push_back(Rooms("10;EXE"));
    planRooms.push_back(Rooms("11;EXE"));
    planRooms.push_back(Rooms("18;CMP"));
    planRooms.push_back(Rooms("8;LAB"));
    planRooms.push_back(Rooms("9;LAB"));
}
void initializeGroups(){
    planGroups.push_back(Groups(("1i;1;Informatyka;LEC")));
    planGroups.push_back(Groups(("11i;1;Informatyka;EXE")));
    planGroups.push_back(Groups(("12i;1;Informatyka;EXE")));
    planGroups.push_back(Groups(("13i;1;Informatyka;EXE")));
    planGroups.push_back(Groups(("1lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("2lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("3lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("4lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("5lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("1lab1i;1;Informatyka;CMP")));
    planGroups.push_back(Groups(("2lab1i;1;Informatyka;CMP")));
    planGroups.push_back(Groups(("3lab1i;1;Informatyka;CMP")));
    planGroups.push_back(Groups(("4lab1i;1;Informatyka;CMP")));
    planGroups.push_back(Groups(("5lab1i;1;Informatyka;CMP")));

    planGroups.push_back(Groups(("1i;1;Elektrotechnika;LEC")));
    planGroups.push_back(Groups(("11i;1;Elektrotechnika;EXE")));
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

            }
        }
        file.close();
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
}


using namespace std;
int main() {
    initializeData();
    Plan mainPlan(planRooms,definedHours,planInstructors,planSubjects,weekDays,planGroups,planLeadings);
    mainPlan.showPlan();

    return 0;
}