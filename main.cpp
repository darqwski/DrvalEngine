#include <iostream>
#include <vector>
#include <string>
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
enum HourType {EARLY = 0, MIDDAY = 1, AFTERNOON =2 , EVENING = 3};
enum WeekDaysString {MONDAY,TUESDAY,W};
void initializeHours(){
    definedHours.push_back(Hours("7:30",1));
    definedHours.push_back(Hours("9:15",1));
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
void initializeInstructors(){
    planInstructors.push_back(Instructors(("Adam;Jagiello;Prof.Dr.Hab;90")));
    planInstructors.push_back(Instructors(("Mieczyslaw;Drabowski;Dr.Hab;80")));
    planInstructors.push_back(Instructors(("Damian;Grela;Dr;85")));
}
void initializeRooms(){
    planRooms.push_back(Rooms("A1;W;EX"));
    planRooms.push_back(Rooms("A2;W;EX"));
    planRooms.push_back(Rooms("A3;W;EX"));
    planRooms.push_back(Rooms("A4;W;EX"));
    planRooms.push_back(Rooms("10;EX"));
    planRooms.push_back(Rooms("11;EX"));
    planRooms.push_back(Rooms("18;LC"));
    planRooms.push_back(Rooms("8;LAB"));
}
void initializeGroups(){
    planGroups.push_back(Groups(("11i;1;Informatyka;EX")));
    planGroups.push_back(Groups(("12i;1;Informatyka;EX")));
    planGroups.push_back(Groups(("13i;1;Informatyka;EX")));
    planGroups.push_back(Groups(("1lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("2lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("3lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("4lab1i;1;Informatyka;LAB")));
    planGroups.push_back(Groups(("5lab1i;1;Informatyka;LAB")));
}
void initializeSubjects(){
    planSubjects.push_back(Subjects(("Matematyka;Informatyka;1;30;30;0;0;0")));
    planSubjects.push_back(Subjects(("Fizyka;Informatyka;1;30;30;0;0;0")));
    planSubjects.push_back(Subjects(("Elektrotechnika;Informatyka;1;30;15;15;0;0")));
    planSubjects.push_back(Subjects(("Grafika Komputerowa;Informatyka;1;30;15;15;0;0")));
}
void initializeData(){
    initializeHours();
    initializeWeekDays();
    initializeInstructors();
    initializeRooms();
    initializeGroups();
    initializeSubjects();
}


using namespace std;
int main() {
    initializeData();
    Plan mainPlan(planRooms,definedHours,planInstructors,planSubjects,weekDays);
    mainPlan.showEmptyPlan();

    return 0;
}