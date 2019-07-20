<?php
include("../PDO.php");
function mainArrayWrapper($data){
  return 'mainArray:'.$data;
}
function getAllWeekView(){
  $rooms =getCommand("SELECT * FROM drval_room");
  $occurances =getCommand(
    "SELECT drval_occurences.hour AS `OccurenceHour`,drval_occurences.type AS `OccurenceType`,
    drval_room.number AS `RoomNumber`,
    drval_subject.name,
    drval_instructor.name,drval_instructor.surname,drval_instructor.title
    FROM drval_occurences
    INNER JOIN drval_room ON drval_room.id=drval_occurences.roomID
    INNER JOIN drval_instructor ON drval_instructor.id=drval_occurences.instructorID
    INNER JOIN drval_subject ON drval_subject.id=drval_occurences.subjectID"
  );
  $weekRoom = [];
    for($weekNumber=0;$weekNumber<5;$weekNumber++){
      $weekRoom[$weekNumber] = [];
        for($i=0;$i<count($rooms);$i++){
          $weekRoom[$weekNumber][$rooms[$i]['number']]=[];
        }
    }
    for($i=0;$i<count($occurances);$i++){
      $current = $occurances[$i];
      $weekRoom[$current['day']][$current['RoomNumber']]=$current;
    }
    return mainArrayWrapper(json_encode($weekRoom));
}
    function generatePlan(){
        exec("PlanCalculation.exe");
    }
 ?>
