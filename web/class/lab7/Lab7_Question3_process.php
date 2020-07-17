<?php
    $name = $_POST['name'];
    $day = $_POST['day'];
    $month = $_POST['month'];
    $year = $_POST['year'];
    $age = $_POST['age'];

    echo "Welcome <b>$name</b>, you are born on <b>$day-$month-$year</b>. You are <b>$age</b> years old.";
?>