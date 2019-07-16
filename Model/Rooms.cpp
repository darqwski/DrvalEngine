//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Rooms.h"
#include "../Utilities/SuperUtilities.h"

const string &Rooms::getNumber() const {
    return number;
}

void Rooms::setNumber(const string &number) {
    Rooms::number = number;
}

const string &Rooms::getMainType() const {
    return mainType;
}

void Rooms::setMainType(const string &mainType) {
    Rooms::mainType = mainType;
}

const string &Rooms::getSecondType() const {
    return secondType;
}

void Rooms::setSecondType(const string &secondType) {
    Rooms::secondType = secondType;
}

Rooms::Rooms(string csvLine) {
        vector<string> items = split(csvLine,";");
        setNumber(items.at(0));
        setMainType(items.at(1));
        try{
            setSecondType(items.at(2));
        }catch (exception e){
            setSecondType("");
        }
}
