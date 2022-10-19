<?php
    //get values from post
    $username = $_POST['username'];
    $password = $_POST['password'];
    $repeatPassword = $_POST['repeat_password'];
    $email = $_POST['email'];

    //validate the values
    $isValid = true;
    if(empty($username)){
        $isValid = false;
        echo "The username should not be empty!";
    }
    else if(empty($password)){
        $isValid = false;
        echo "The password should not be empty!";
    }
    else if(!strcmp($password,$repeatPassword)){
        $isValid = false;
        echo "The repeat password should be same as the password!";
    }
    else if (empty($email)){
        $isValid = false;
        echo "The email should not be empty!";
    }

    if($isValid){
        //save into database
        $mysql = new mysqli("localhost","root","","forumDemo");
        
        //password salting
        $salt = "Good@Forum";
        $hashedPassword = md5($password.$salt);
        $query = "INSERT INTO user(username,password,email) VALUES ('$username','$hashedPassword','$email')";
        
        
        if($mysql->query($query)){
            echo "The record had been added into the database.<br>";
        }else{
            echo "Failed to insert record into database:".$mysql->error."<br>";
        }

        $mysql->close();
    }

?>