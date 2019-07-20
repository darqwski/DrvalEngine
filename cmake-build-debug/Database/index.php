<?php
  session_start();
  include("../Modules/RequestReceiver.php");
  header('Content-Type: text/html; charset=utf-8');
  $type = explode('?',$_SERVER['REQUEST_URI']);
  $queryParam = explode('&',$type[count($type)-1]);
  $action=$queryParam[0];
  $validation=validation();

  if($validation == "OK"){
      $requestReceiver = new RequestReceiver();
      $requestReceiver->addRequestModule
      (new RequestFormat("GET","test",Array(PERM_NO_PERMISSION),"test"));
      $requestReceiver->addRequestModule
      (new RequestFormat("GET","getAllWeekView",Array(PERM_NO_PERMISSION),"getAllWeekView"));
      $requestReceiver->addRequestModule
      (new RequestFormat("GET","generatePlan",Array(PERM_NO_PERMISSION),"generatePlan"));
      $requestResult = $requestReceiver->checkRequestModules($_SERVER['REQUEST_METHOD'],$action,0,$_POST);
     echo $requestResult;
  }
  switch($validation){
      case "OK":
          http_response_code(200);
          break;
      default:
          http_response_code(401);
          break;
  }

function validation(){
    return "OK";
}
?>
