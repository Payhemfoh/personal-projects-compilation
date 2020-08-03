<?php
    $search = $_GET['search'];

    echo "<center>";

    //check search bar is empty or not
    if(empty($search)){
        echo "Sorry, the form has not submitted successfully:<br>
            search bar should not be empty.<br>";
    }else{
        echo "Start searching...";
        sleep(0.5);
        header("Location:../ProductsListPage.php?search=$search");
    }

    echo "</center>";
?>