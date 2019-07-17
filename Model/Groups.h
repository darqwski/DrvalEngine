//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_GROUPS_H
#define DRVALENGINE_GROUPS_H

#include <string>
#include <vector>
#include "../Utilities/DrvalUtilities.h"

using namespace std;
class Groups {
private:
    string name, studyField;
    SubjectType groupType;
    int year;
public :
    const string &getName() const;

    void setName(const string &name);

    const string &getStudyField() const;

    void setStudyField(const string &studyField);

    const SubjectType &getGroupType() const;

    void setGroupType(const string &groupType);

    int getYear() const;

    void setYear(int year);

    Groups(string csvLine);
    Groups();
    friend bool operator==(const Groups& g1, const Groups& g2);
};


#endif //DRVALENGINE_GROUPS_H
