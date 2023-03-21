<?php
    session_start();
    $id = $_SESSION['id'];
    $phone = $_SESSION['phone'];
    $time = $_SESSION['time'];

    echo "<p>Welcome $id, your phone no: $phone<br> Login since: $time";
?>