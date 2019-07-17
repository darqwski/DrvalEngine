//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Groups.h"
#include "../Utilities/SuperUtilities.h"
#include "../Utilities/DrvalUtilities.h"

const string &Groups::getName() const {
    return name;
}

void Groups::setName(const string &name) {
    Groups::name = name;
}

const string &Groups::getStudyField() const {
    return studyField;
}

void Groups::setStudyField(const string &studyField) {
    Groups::studyField = studyField;
}

const SubjectType &Groups::getGroupType() const {
    return groupType;
}

void Groups::setGroupType(const string &groupType) {
    if(groupType=="LAB")
        Groups::groupType = LAB;
    else if(groupType=="EXE")
        Groups::groupType = EXE;
    else if(groupType=="LEC")
        Groups::groupType = LEC;
    else if(groupType=="CMP")
        Groups::groupType = CMP;
    else if(groupType=="PRO")
        Groups::groupType= PRO;
    else
        Groups::groupType=UNKNOWN;
}

int Groups::getYear() const {
    return year;
}

void Groups::setYear(int year) {
    Groups::year = year;
}

Groups::Groups(string csvLine) {
        vector<string> items = split(csvLine,";");
        setName(items.at(0));
        setYear(stoi(items.at(1)));
        setStudyField(items.at(2));
        setGroupType(items.at(3));
}

Groups::Groups() {

}
