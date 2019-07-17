//
// Created by dariusz.cabala on 7/15/2019.
//

#include "Hours.h"
#include "../Utilities/SuperUtilities.h"
#include <string>
#include <vector>
using namespace std;
const string &Hours::getText() const {
    return text;
}

void Hours::setText(const string &text) {
    Hours::text = text;
}

int Hours::getHour() const {
    return hour;
}

void Hours::setHour(int hour) {
    Hours::hour = hour;
}

int Hours::getMinutes() const {
    return minutes;
}

void Hours::setMinutes(int minutes) {
    Hours::minutes = minutes;
}

Hours::Hours(string text, int type) {
    vector<string>hours=split(text,":");
    setText(text);
    setHour(stoi(hours.at(0)));
    setMinutes(stoi(hours.at(1)));
}

Hours::Hours() {

}
