//
// Created by General Automatic on 2019-07-16.
//

#ifndef DRVALENGINE_DRVALUTILITIES_H
#define DRVALENGINE_DRVALUTILITIES_H

#include <string>

using namespace std;

const int MAXHOURSPERWEEK = 5;
const int WEEKINTERM=30;

enum SubjectType{
      LAB,EXE,CMP,LEC,PRO,UNKNOWN
};


SubjectType getSubjectType(string name);

class DrvalUtilities {

};


#endif //DRVALENGINE_DRVALUTILITIES_H
