<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>Date</title>
	</head>
	
	<body>
		<?php

            echo "<form method='post' action='Lecprocess.php'>";
            echo "<label for='punctuality'>Punctuality:</label><br>";
            for($v = 1;$v<=10;$v++){
                echo "<input type='radio' name='punctuality' value='$v'>$v<br>";
            }

            echo "<br><br>";
            echo "<label for='preparation'>Preparation:</label><br>";
            for($v = 1;$v<=10;$v++){
                echo "<input type='radio' name='preparation' value='$v'>$v<br>";
            }

            echo "<br><br>";
            echo "<input type='submit'>";

        ?>
	</body>
	
</html>