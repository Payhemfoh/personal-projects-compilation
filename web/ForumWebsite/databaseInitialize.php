<?php
    $mysql = mysqli_connect("localhost","root","");

    while(!mysqli_select_db($mysql,"forumDemo")){
        $query = "CREATE DATABASE forumDemo";
        mysqli_query($mysql,$query);
    }

    //user
    $query = "CREATE TABLE user (
        userid int not null auto_increment primary key,
        username varchar(40) not null,
        password varchar(32) not null,
        email varchar(40) not null
    )";
    if(mysqli_query($mysql,$query)){
        echo "User table created<br>";
    }else{
        echo "Failed to create table:".mysqli_error($mysql)."<br>";
    }

    //post
    $query = "CREATE TABLE post (
        postid int not null auto_increment primary key,
        title varchar(50) not null,
        title_post varchar(300) not null,
        userid int not null,
        lastModify datetime not null,
        foreign key (userid) references user(userid)
    )";
    if(mysqli_query($mysql,$query)){
        echo "Post table created<br>";
    }else{
        echo "Failed to create table:".mysqli_error($mysql)."<br>";
    }

    //post detail
    $query = "CREATE TABLE reply (
        replyid int not null auto_increment primary key,
        postid int not null ,
        floorLevel int not null,
        post varchar(300) not null,
        userid int not null,
        lastModify datetime not null,
        foreign key (postid) references post(postid),
        foreign key (userid) references user(userid)
    )";
    if(mysqli_query($mysql,$query)){
        echo "Reply table created<br>";
    }else{
        echo "Failed to create table:".mysqli_error($mysql)."<br>";
    }
?>