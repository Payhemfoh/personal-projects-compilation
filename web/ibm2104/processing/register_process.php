<?php
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
    if(empty($username)){
        echo "The username should not be empty!<br>";
        $submit = false;
    }
    
    else{
        //username length limit 30 character
        if(strlen($username)>30){
            echo "The username should not be more than 30 character!<br>";
            $submit = false;
        }

        $match = preg_match('/[^a-zA-Z0-9_]/',$username);
        if($match){
            echo "Username should only contain: lowercase character, uppercase character, digit and underscore(_)";
            $submit = false;
        }
    }


    //password
    if(empty($password)){
        echo "The password should not be empty!<br>";
        $submit = false;
    }
    else{
        //must more than 8 character
        if(strlen($password)<8){
            echo "The password length should be at least 8 character!<br>";
            $submit = false;
        }
        
        //must contain lowercase, uppercase and symbol
        $match1=preg_match('/[a-z]/',$password);
        $match2=preg_match('/[A-Z]/',$password);
        $match3=preg_match('/[0-9]/',$password);

        if(!$match1 || !$match2 || !$match3){
            echo "The password should be the combination of :lowercase character, uppercase character, digit.<br>";
            $submit = false;
        }

        $match = preg_match('/[^a-zA-Z0-9_]/',$username);
        if($match){
            echo "Username should only contain: lowercase character, uppercase character, digit and underscore(_)";
            $submit = false;
        }
    }

    //email
    if(empty($email)){
        echo "The email should not be empty!<br>";
        $submit = false;
    }
    //check format of email input
    else if(!filter_var($email,FILTER_VALIDATE_EMAIL)){
        echo "The email is in wrong format!<br>";
        $submit = false;
    }


    //firstName
    if(empty($firstName)){
        echo "The first name should not be empty!<br>";
        $submit = false;
    }
    else if(!ctype_alpha(str_replace(' ','',$firstName))){
        echo "The first name should only contain alphabet characters!<br>";
        $submit = false;
    }


    //lastName
    if(empty($lastName)){
        echo "The last name should not be empty!<br>";
        $submit = false;
    }
    else if(!ctype_alpha(str_replace(' ','',$lastName))){
        echo "The last name should only contain alphabet characters!<br>";
        $submit = false;
    }


    //address
    if(empty($address)){
        echo "The address should not be empty!<br>";
        $submit = false;
    }
    //address length limit 50 character
    else if(strlen($address)>50){
        echo "The username should not be more than 50 character!<br>";
        $submit = false;
    }


    //postcode
    if(empty($postcode)){
        echo "The postcode should not be empty!<br>";
        $submit = false;
    }
    else if(!is_numeric(str_replace(' ','',$postcode))){
        echo "The postcode should only contain numeric character!<br>";
        $submit = false;
    }
    //postcode length is 5 digit
    else if(strlen($postcode)!=5){
        echo "The postcode is not match to the formal length of Malaysia postcode(5 character).<br>";
        $submit = false;
    }


    //area
    if(empty($area)){
        echo "The area should not be empty!<br>";
        $submit = false;
    }
    else if(!ctype_alpha(str_replace(' ','',$area))){
        echo "The area should only contain alphabet characters!<br>";
        $submit = false;
    }

    //country
    if(empty($country)){
        echo "The country should not be empty!<br>";
        $submit = false;
    }
    else if(!ctype_alpha(str_replace(' ','',$country))){
        echo "The country should only contain alphabet characters!<br>";
        $submit = false;
    }


    //phoneNo
    if(empty($phoneNo)){
        echo "The phone number should not be empty!<br>";
        $submit = false;
    }
    //phone number should only contain digits(included '-')
    else if(!is_numeric(str_replace(array(' ','-'),'',$phoneNo))){
        echo "The phone number should only contain numeric character!<br>";
        $submit = false;
    }
    //length of phone number is between 9-11 digits
    if(strlen($phone)<9 || strlen($phone)>11){
        echo "The phone number is not match to the formal length of Malaysia phone number.<br>";
        $submit = false;
    }


    /*
    -----------decide either the registration success or failed and print message---------------
    */
    if($submit){
        echo "Your registration is submitted successfully.<br>
                Hello, <b>$username</b>";
    }
    else{
        echo "<br>Sorry, the form has not submitted successfully:<br>";
    }
    echo "</center>";
?>