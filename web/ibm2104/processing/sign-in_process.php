<?php
    //get variables from sign-in page
    $username = $_POST['username'];
    $password = $_POST['password'];

    //check conditions
    $submit=true;
        
    //Username is not filled
    if(empty($username)){
        echo "username field should not be empty.<br>";
        $submit = false;
    }
    else{ 
        
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

    //password is not filled
    if(empty($password)){
        echo "password field should not be empty.<br>";
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

    
    if($submit){
        echo "Your form is submitted successfully.<br>
                Hello, <b>$username</b>";
    }
    else{
        echo "Sorry, the form has not submitted successfully:<br>";
    }

?>