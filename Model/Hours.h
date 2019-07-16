//
// Created by dariusz.cabala on 7/15/2019.
//

#ifndef DRVALENGINE_HOURS_H
#define DRVALENGINE_HOURS_H
#include<string>

using namespace std;
class Hours {
public:
    const string &getText() const;

    void setText(const string &text);

    int getHour() const;

    void setHour(int hour);

    int getMinutes() const;

    void setMinutes(int minutes);

    Hours(string text, int type);


private:
    string text;
    int hour,minutes;
};


#endif //DRVALENGINE_HOURS_H
