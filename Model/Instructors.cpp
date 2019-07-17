//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Instructors.h"
#include "../Utilities/SuperUtilities.h"
#include <string>
#include <vector>

const string &Instructors::getName() const {
    return name;
}

void Instructors::setName(const string &name) {
    Instructors::name = name;
}

const string &Instructors::getSurname() const {
    return surname;
}

void Instructors::setSurname(const string &surname) {
    Instructors::surname = surname;
}

const string &Instructors::getTitle() const {
    return title;
}

void Instructors::setTitle(const string &title) {
    Instructors::title = title;
}

int Instructors::getPriority() const {
    return priority;
}

void Instructors::setPriority(int priority) {
    Instructors::priority = priority;
}

Instructors::Instructors(string csvLine) {
    vector<string> items = split(csvLine,";");
    setName(items.at(0));
    setSurname(items.at(1));
    setTitle(items.at(2));
    setPriority(stoi(items.at(3)));
}

Instructors::Instructors() {

}
ostream& operator<<(ostream& os, const Instructors& instructors)
{
    return os;
}

bool Instructors::findByID(string id) {
    return id==this->id;
}

bool operator==(const Instructors &g1, const Instructors &g2) {
    if(g2.getName()!=g1.getName())return false;
    if(g2.getSurname()!=g1.getSurname())return false;
    if(g2.getTitle()!=g1.getTitle())return false;
    if(g2.getPriority()!=g1.getPriority())return false;
    return true;
}

