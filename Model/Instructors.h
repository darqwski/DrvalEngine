//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_INSTRUCTORS_H
#define DRVALENGINE_INSTRUCTORS_H

#include <string>
#include <vector>
using namespace std;
class Instructors {
private:
    string name,surname,title;
    int priority;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const string &getTitle() const;

    void setTitle(const string &title);

    int getPriority() const;

    void setPriority(int priority);

    Instructors();

    Instructors(string csvLine);

    friend ostream& operator<<(ostream& os, const Instructors& instructors );
};


#endif //DRVALENGINE_INSTRUCTORS_H
