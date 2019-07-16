//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Groups.h"
#include "../Utilities/SuperUtilities.h"

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

const string &Groups::getGroupType() const {
    return groupType;
}

void Groups::setGroupType(const string &groupType) {
    Groups::groupType = groupType;
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
