<?php
include("PDO.php");
include($_SERVER['DOCUMENT_ROOT']."/RequestFunctions/getFunctions.php");
function test(){
  $messages = [];
  $messages["message"]="OK";
  return '{"TheArray":'.json_encode($messages).'}';
}
function buildMessage($message){
  return '{"message":'.$message.'}';
}
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
        echo "<pre>";
        echo shell_exec("DrvalEngine.exe 125 70 127 220 0.5 0.4");
        echo shell_exec("drvalengine.exe 125 70 127 220 0.5 0.4");
        echo $output;
        echo shell_exec("ls -l");
        echo shell_exec("chmod 777 DrvalEngine");
        echo shell_exec("chmod 777 DrvalEngine.exe");
        echo shell_exec("chmod 777 index.php");
        echo shell_exec("ls -l");
        echo shell_exec("./DrvalEngine.exe");
        echo shell_exec("./DrvalEngine");
        echo shell_exec("DrvalEngine.exe");
        echo shell_exec("DrvalEngine");
        
        echo exec("DrvalEngine.exe 125 70 127 220 0.5 0.4");
        echo exec("drvalengine.exe 125 70 127 220 0.5 0.4");
        echo $output;
        echo exec("ls -l");
        echo exec("chmod 777 DrvalEngine");
        echo exec("chmod 777 DrvalEngine.exe");
        echo exec("ls -l");
        echo exec("./DrvalEngine.exe");
        echo exec("./DrvalEngine");
        echo exec("DrvalEngine.exe");
        echo exec("DrvalEngine");
        echo "<pre>".file_get_contents("Database/results.txt");
    }
