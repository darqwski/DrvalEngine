//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_ROOMS_H
#define DRVALENGINE_ROOMS_H
#include <string>
#include <vector>
using namespace std;
class Rooms {
private:
    string number,mainType,secondType;
public:
    const string &getNumber() const;

    void setNumber(const string &number);

    const string &getMainType() const;

    void setMainType(const string &mainType);

    const string &getSecondType() const;

    void setSecondType(const string &secondType);

public:

    Rooms(string csvLine);
};


#endif //DRVALENGINE_ROOMS_H
