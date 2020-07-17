<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Lab7-Question3</title>
		<meta charset="utf-8">
	</head>
	
	<body>
        <?php
            echo '<form method="post" action="Lab7_Question3_process.php">';
            
                echo '<label for="name">Name:</label><br>';
                echo '<input type="text" name="name"><br><br>';
            
                echo '<label for="day">Day:</label>';
                echo '<select name="day">';
                for($i=1;$i<=31;$i++){
                    echo "<option value=$i>$i";
                }
                echo '</select><br><br>';

                echo '<label for="month">Month:</label>';
                echo '<select name="month">';
                for($i=1;$i<=12;$i++){
                    echo "<option value='$i'>$i";
                }
                echo '</select><br><br>';

                
                echo '<label for="year">Year:</label>';
                echo '<select name="year">';
                for($i=1900;$i<=2020;$i++){
                    echo '<option value='.$i.'>'.$i;
                }
                echo '</select><br><br>';

                echo '<label for="age">Age:</label>';
                echo '<select name="age">';
                for($i=0;$i<=200;$i++){
                    echo "<option value='$i'>$i\n";
                }
                echo '</select><br><br>';
        
                echo '<input type="submit">';

            echo '</form>';
        ?>
	</body>
</html>