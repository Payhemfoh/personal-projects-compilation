<?php
    function printFormToHomepage(){
        echo "<br><br>";
        echo "<center>";
        echo "Please press the button below to return to homepage.";
        echo "<form action=\"Homepage.php\">";
		echo "<input type=\"submit\" value=\"go\">";
        echo "</form>";
        echo "</center>";
    }

    function printFormToLoginpage(){
        echo "<br><br>";
        echo "<center>";
        echo "Please press the button below to return to login page.";
        echo "<form action=\"Homepage.php\">";
		echo "<input type=\"submit\" value=\"go\">";
        echo "</form>";
        echo "</center>";
    }

    function validateUsername($username){
        $valid = true;

        if(empty($username)){
            echo "The username should not be empty!<br>";
            $valid = false;
        }
        
        else{
            //username length limit 30 character
            if(strlen($username)>30){
                echo "The username should not be more than 30 character!<br>";
                $valid = false;
            }
    
            $match = preg_match('/[^a-zA-Z0-9_]/',$username);
            if($match){
                echo "Username should only contain: lowercase character, uppercase character, digit and underscore(_)<br>";
                $valid = false;
            }
        }

        return $valid;
    }

    function validatePassword($password){
        $valid = true;

        if(empty($password)){
            echo "The password should not be empty!<br>";
            $valid = false;
        }
        else{
            //must more than 8 character
            if(strlen($password)<8){
                echo "The password length should be at least 8 character!<br>";
                $valid = false;
            }
            
            //must contain lowercase, uppercase and symbol
            $match1=preg_match('/[a-z]/',$password);
            $match2=preg_match('/[A-Z]/',$password);
            $match3=preg_match('/[0-9]/',$password);
    
            if(!$match1 || !$match2 || !$match3){
                echo "The password should be the combination of :lowercase character, uppercase character, digit.<br>";
                $valid = false;
            }
    
            $match = preg_match('/[^a-zA-Z0-9_]/',$password);
            if($match){
                echo "The password should only contain: lowercase character, uppercase character, digit and underscore(_)<br>";
                $valid = false;
            }
        }

        return $valid;
    }
    
    function validateEmail($email){
        $valid = true;

        if(empty($email)){
            echo "The email should not be empty!<br>";
            $valid = false;
        }
        //check format of email input
        else if(!filter_var($email,FILTER_VALIDATE_EMAIL)){
            echo "The email is in wrong format!<br>";
            $valid = false;
        }

        return $valid;
    }

    function validateCharacterOnly($name,$input_name){
        $valid = true;

        if(empty($name)){
            echo "The $input_name should not be empty!<br>";
            $valid = false;
        }
        else if(!ctype_alpha(str_replace(' ','',$name))){
            echo "The $input_name should only contain alphabet characters!<br>";
            $valid = false;
        }

        return $valid;
    }

    function validateAddress($address){
        $valid = true;
        if(empty($address)){
            echo "The address should not be empty!<br>";
            $valid = false;
        }
        //address length limit 50 character
        else if(strlen($address)>50){
            echo "The username should not be more than 50 character!<br>";
            $valid = false;
        }

        return $valid;
    }

    function validatePostcode($postcode){
        $valid = true;

        if(empty($postcode)){
            echo "The postcode should not be empty!<br>";
            $valid = false;
        }
        else {
            if(!is_numeric(str_replace(' ','',$postcode))){
                echo "The postcode should only contain numeric character!<br>";
                $valid = false;
            }
    
            //postcode length is 5 digit
            if(strlen($postcode)!=5){
                echo "The postcode is not match to the formal length of Malaysia postcode(5 character).<br>";
                $valid = false;
            }
        }

        return $valid;
    }

    function validatePhoneNo($phoneNo){
        $valid = true;

        if(empty($phoneNo)){
            echo "The phone number should not be empty!<br>";
            $valid = false;
        }
        //phone number should only contain digits(included '-')
        else {
            if(!is_numeric(str_replace(array(' ','-'),'',$phoneNo))){
                echo "The phone number should only contain numeric character!<br>";
                $valid = false;
            }
            //length of phone number is between 9-11 digits
            if(strlen($phoneNo)<9 || strlen($phoneNo)>11){
                echo "The phone number is not match to the formal length of Malaysia phone number.<br>";
                $valid = false;
            }
        }
        return $valid;
    }

    function validateTextArea($content){
        $valid = true;
        //content is not filled
        if(empty($content)){
            echo "content field should not be empty.<br>";
            $valid = false;
        }
        //the word in the content should not exceed 300 words
        else if(str_word_count($content)>300){
            echo "the content should not exceed 300 words limit.<br>";
            $valid = false;
        }
        return $valid;
    }
?>

