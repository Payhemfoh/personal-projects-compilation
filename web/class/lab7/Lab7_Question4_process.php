<?php
    $satisfied=$_POST['satisfied'];
    $relavant=$_POST['relavant'];
    $key=$_POST['key'];
    
    //logistic
    $accommodation=$_POST['Acommodation'];
    $welcome_kit=$_POST['Welcome_kit'];
    $communication_emails=$_POST['Communication_emails'];
    $transportation=$_POST['Transportation'];
    $welcome_activity=$_POST['Welcome_activity'];
    $venue=$_POST['Venue'];
    $activities=$_POST['Activities'];
    $closing_ceremony=$_POST['Closing_ceremony'];

    $logistic_addition=$_POST['logistic_addition'];

    //relevant
    $welcome_activity=$_POST['Welcome_activity'];
    $speaker1=$_POST['Speaker_#1'];
    $speaker2=$_POST['Speaker_#2'];
    $activity1=$_POST['Activity_#1'];
    $activity2=$_POST['Activity_#2'];
    $closing_activity=$_POST['Closing_activity'];

    $session_content=$_POST['session_content'];
    $addition_comment=$_POST['addition_comment'];
    $overall=$_POST['overall'];
    $name=$_POST['name'];

    if(isset($satisfied)){
        echo '$satisfied='.$satisfied.'<br>';
    }
    else{
        echo '$satisfied=null<br>';
    }

    if(isset($relavant)){
        echo '$relavant='.$relavant.'<br>';
    }
    else{
        echo '$relavant=null<br>';
    }

    if(isset($key)){
        echo '$key='.$key.'<br>';
    }
    else{
        echo '$key=null<br>';
    }

    if(isset($accommodation)){
        echo '$accommodation='.$accommodation.'<br>';
    }
    else{
        echo '$accommodation=null<br>';
    }

    if(isset($welcome_kit)){
        echo '$welcome_kit='.$welcome_kit.'<br>';
    }
    else{
        echo '$welcome_kit=null<br>';
    }

    if(isset($communication_emails)){
        echo '$communication_emails='.$communication_emails.'<br>';
    }
    else{
        echo '$communication_emails=null<br>';
    }

    if(isset($transportation)){
        echo '$transportation='.$transportation.'<br>';
    }
    else{
        echo '$transportation=null<br>';
    }

    if(isset($welcome_activity)){
        echo '$welcome_activity='.$welcome_activity.'<br>';
    }
    else{
        echo '$welcome_activity=null<br>';
    }

    if(isset($venue)){
        echo '$venue='.$venue.'<br>';
    }
    else{
        echo '$venue=null<br>';
    }

    if(isset($activities)){
        echo '$activities='.$activities.'<br>';
    }
    else{
        echo '$activities=null<br>';
    }

    if(isset($closing_ceremony)){
        echo '$closing_ceremony='.$closing_ceremony.'<br>';
    }
    else{
        echo '$closing_ceremony=null<br>';
    }

    if(isset($logistic_addition)){
        echo '$logistic_addition='.$logistic_addition.'<br>';
    }
    else{
        echo '$logistic_addition=null<br>';
    }

    if(isset($welcome_activity)){
        echo '$welcome_activity='.$welcome_activity.'<br>';
    }
    else{
        echo '$welcome_activity=null<br>';
    }

    if(isset($speaker1)){
        echo '$speaker1='.$speaker1.'<br>';
    }
    else{
        echo '$speaker1=null<br>';
    }

    if(isset($speaker2)){
        echo '$speaker2='.$speaker2.'<br>';
    }
    else{
        echo '$speaker2=null<br>';
    }

    if(isset($activity1)){
        echo '$activity1='.$activity1.'<br>';
    }
    else{
        echo '$activity1=null<br>';
    }

    if(isset($activity2)){
        echo '$activity2='.$activity2.'<br>';
    }
    else{
        echo '$satisfied=null<br>';
    }

    if(isset($closing_activity)){
        echo '$closing_activity='.$closing_activity.'<br>';
    }
    else{
        echo '$closing_activity=null<br>';
    }

    if(isset($session_content)){
        echo '$session_content='.$session_content.'<br>';
    }
    else{
        echo '$session_content=null<br>';
    }

    if(isset($addition_comment)){
        echo '$addition_comment='.$addition_comment.'<br>';
    }
    else{
        echo '$addition_comment=null<br>';
    }

    if(isset($overall)){
        echo '$overall='.$overall.'<br>';
    }
    else{
        echo '$overall=null<br>';
    }

    if(isset($name)){
        echo '$name='.$name.'<br>';
    }
    else{
        echo '$name=null<br>';
    }
?>