//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_ROOMS_H
#define DRVALENGINE_ROOMS_H
#include <string>
#include <vector>
#include "../Utilities/DrvalUtilities.h"

using namespace std;
class Rooms {
private:
    string number;
    SubjectType mainType,secondType;
public:
    const string &getNumber() const;

    void setNumber(const string &number);

    const SubjectType &getMainType() const;

    void setMainType(const string &mainType);

    const SubjectType &getSecondType() const;

    void setSecondType(const string &secondType);

public:
    Rooms();
    Rooms(string csvLine);
};


#endif //DRVALENGINE_ROOMS_H
