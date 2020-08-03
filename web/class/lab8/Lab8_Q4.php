<?php
    $subject_marks = array(
                    "ICT2100" => 90,
                    "ICT2101" => 80,
                    "IBM2102" => 80,
                    "IBM2104" => 90);

    //sort array in ascending order based on value
    asort($subject_marks);

    echo "<h1>My marks:</h1><br>";
    
    foreach($subject_marks as $subject => $mark){
        echo "<p>subject:$subject mark:$mark</p>";
    }

?>