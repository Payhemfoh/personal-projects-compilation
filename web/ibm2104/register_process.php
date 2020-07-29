<?php
    include("script/commonFunction.php");
    //get variables from register page
    $username   =$_POST['username'];
    $password   =$_POST['password'];
    $email      =$_POST['email'];
    $firstName  =$_POST['firstName'];
    $lastName   =$_POST['lastName'];
    $address    =$_POST['address'];
    $postcode   =$_POST['postcode'];
    $area       =$_POST['area'];
    $country    =$_POST['country'];
    $phoneNo    =$_POST['phoneNo'];

    echo "<center>";
    /*
    -----------------------check conditions--------------------
    */ 
    //boolean for check conditions
    $submit = true;
    //username
    if(!validateUsername($username))
        $submit = false;


    //password
    if(!validatePassword($password))
        $submit = false;

    //email
    if(!validateEmail($email))
        $submit = false;


    //firstName
    if(!validateCharacterOnly($firstName,"First Name"))
        $submit = false;


    //lastName
    if(!validateCharacterOnly($lastName,"Last Name"))
        $submit = false;


    //address
    if(!validateAddress($address))
        $submit = false;

    //postcode
    if(!validatePostcode($postcode))
        $submit = false;

    //area
    if(!validateCharacterOnly($area,"Area"))
        $submit = false;

    //country
    if(!validateCharacterOnly($country,"Country"))
        $submit = false;


    //phoneNo
    if(!validatePhoneNo($phoneNo))
        $submit = false;
    /*
    -----------decide either the registration success or failed and print message---------------
    */
    if($submit){
        echo "Your registration is submitted successfully.<br>
                Hello, <b>$username</b>";
    }
    else{
        echo "<br>Sorry, the form has not submitted successfully:<br>";
        printFormToHomepage();
    }
    echo "</center>";
?>

