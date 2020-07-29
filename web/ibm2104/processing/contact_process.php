<?php
    //get variables from previous contactUs webpage
    $username = $_POST['username'];
    $email = $_POST['email'];
    $content = $_POST['content'];

    echo "<center>";

    //check conditions
    $submit = true;
    
        
    //Username is not filled
    if(empty($username)){
        echo "username field should not be empty.<br>";
        $submit = false;
    }
    //username length limit 30 character
    else if(strlen($username)>30){
        echo "The username should not be more than 30 character!<br>";
        $submit = false;
    }

    //email is not filled
    if(empty($email)){
        echo "email field should not be empty.<br>";
        $submit = false;
    }
    //check format of email input
    else if(!filter_var($email,FILTER_VALIDATE_EMAIL)){
        echo "The email is in wrong format!<br>";
        $submit = false;
    }

    //content is not filled
    if(empty($content)){
        echo "content field should not be empty.<br>";
        $submit = false;
    }
    //the word in the content should not exceed 300 words
    else if(str_word_count($content)>300){
         echo "the content should not exceed 300 words limit.<br>";
         $submit = false;
    }

    if($submit)
        echo "Your form is submitted successfully.<br>
                Hello, <b>$username</b>"; 
    else{
        echo "Sorry, the form has not submitted successfully:<br>";
    }

    echo "</center>";
?>