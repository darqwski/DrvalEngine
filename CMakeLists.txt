cmake_minimum_required(VERSION 3.14)
project(DrvalEngine)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-m32)
add_link_options(-m32)
add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_range_for)
add_executable(DrvalEngine main.cpp Model/Instructors.cpp Model/Instructors.h Utilities/SuperUtilities.cpp Utilities/SuperUtilities.h Model/Rooms.cpp Model/Rooms.h Model/Groups.cpp Model/Groups.h Model/Subjects.cpp Model/Subjects.h Model/Hours.cpp Model/Hours.h Model/Plan.cpp Model/Plan.h Utilities/DrvalUtilities.cpp Utilities/DrvalUtilities.h Model/Occurences.cpp Model/Occurences.h Model/Leadings.cpp Model/Leadings.h Model/RoomSubject.cpp Model/RoomSubject.h)