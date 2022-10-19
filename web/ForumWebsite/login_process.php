<?php
    //get variable from $_POST
    $username = $_POST['username'];
    $password = $_POST['password'];

    //validate varaibles
    $isValid = true;
    if(empty($username)){
        echo "Username should not be empty";
        $isValid = false;
    }else if(empty($password)){
        echo "Password should not be empty";
        $isValid = false;
    }

    if($isValid){
        //perform password salting
        $salt = "Good@Forum";
        $hashedpassword = md5($password.$salt);

        $mysql = new mysqli("localhost","root","","forumDemo");
        $query = "SELECT * FROM user WHERE username=? && password=?";
        $statement = $mysql->prepare($query);
        $statement->bind_param("ss",$username,$hashedpassword);
        if($result = $mysql->query($query,MYSQLI_USE_RESULT)){
            if($result->num_rows === 0){
                echo "User not found!";
            }else{
                //success login
                echo "Welcome $username";
            }
        }else{
            echo "Failed to retrieve record into database:".$mysql->error."<br>";
        }
    }
?>