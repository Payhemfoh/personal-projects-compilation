<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>Date</title>
	</head>
	
	<body>
		<?php
            echo "<center>";

            echo "<form method='get' action='dateprocess.php'>";
            echo "<label for='day'>Day:</label>";
            echo "<select name='day'>";
            for($v = 1;$v<=31;$v++){
                echo "<option value=$v>$v</option>";
            }
            echo "</select>";

            echo "<br><br>";
            echo "<label for='month'>Month:</label>";
            echo "<select name='month'>";
            for($v = 1;$v<=12;$v++){
                echo "<option value=$v>$v</option>";
            }
            echo "</select>";

            echo "<br><br>";
            echo "<label for='Year'>year:</label>";
            echo "<select name='year'>";
            for($v = 1900;$v<=2020;$v++){
                echo "<option value=$v>$v</option>";
            }
            echo "</select>";
            
            echo "<br><br>";
            echo "<input type='submit'>";

            echo "</center>"
        ?>
	</body>
	
</html>