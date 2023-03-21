<?php
    //connect to database
    $mysql = mysqli_connect("localhost","root","","ajaxTest");

    $query = "SELECT * FROM users";

    if($result = mysqli_query($mysql,$query)){
        $users = mysqli_fetch_all($result,MYSQLI_ASSOC);
        echo json_encode($users);
    }else{
        echo "Error: "+mysqli_error();
    }
?>