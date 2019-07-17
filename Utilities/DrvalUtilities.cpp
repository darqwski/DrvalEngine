//
// Created by General Automatic on 2019-07-16.
//

#include "DrvalUtilities.h"

SubjectType getSubjectType(string name){
    if(name=="LAB")
        return LAB;
    if(name=="EXE")
        return EXE;
    if(name=="LEC")
        return  LEC;
    if(name=="CMP")
        return CMP;
    if(name=="PRO")
        return PRO;
    return UNKNOWN;
}