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

const SubjectType &Rooms::getMainType() const {
    return mainType;
}

void Rooms::setMainType(const string &mainType) {
    if(mainType=="LAB")
        Rooms::mainType = LAB;
    else if(mainType=="EXE")
        Rooms::mainType = EXE;
    else if(mainType=="LEC")
        Rooms::mainType = LEC;
    else if(mainType=="CMP")
        Rooms::mainType = CMP;
    else if(mainType=="PRO")
        Rooms::mainType= PRO;
    else
        Rooms::mainType=UNKNOWN;
}

const SubjectType &Rooms::getSecondType() const {
    return secondType;
}

void Rooms::setSecondType(const string &secondType) {
    if(secondType=="LAB")
        Rooms::secondType = LAB;
    else if(secondType=="EXE")
        Rooms::secondType = EXE;
    else if(secondType=="LEC")
        Rooms::secondType = LEC;
    else if(secondType=="CMP")
        Rooms::secondType = CMP;
    else if(secondType=="PRO")
        Rooms::secondType= PRO;
    else
        Rooms::secondType=UNKNOWN;
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

Rooms::Rooms() {

}
