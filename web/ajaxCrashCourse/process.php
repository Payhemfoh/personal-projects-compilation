<?php
    //connect to database
    $mysql = mysqli_connect("localhost","root","","ajaxTest");


    echo "Processing...";
    if(isset($_GET['name'])){
        $name = mysqli_real_escape_string($mysql,$_GET['name']);
        echo "GET: Your name is ".$_GET['name'];

        $query = "INSERT INTO users(name) VALUES ('$name')";

        if(mysqli_query($mysql,$query)){
            echo "User added...";
        }else{
            echo "Error: "+mysqli_error();
        }
    }

    if(isset($_POST['name'])){
        $name = mysqli_real_escape_string($mysql,$_POST['name']);
        echo "POST: Your name is ".$_POST['name'];

        $query = "INSERT INTO users(name) VALUES ('$name')";

        if(mysqli_query($mysql,$query)){
            echo "User added...";
        }else{
            echo "Error: "+mysqli_error();
        }
    }
?>