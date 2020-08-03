<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Lab7-Question2</title>
		<meta charset="utf-8">
	</head>
	
	<body>
		<?php
            echo "<table border='1'>";

			for($i = 0;$i<=12;$i++){
                echo "<tr>";
				for($j=0;$j<=12;$j++){
					if($j==0){
                        echo "<th>$i</th>";
                    }
                    else if($i==0){
                        echo "<th>$j</th>";
                    }
                    else{
                        $mul = $i*$j;
                        echo "<td>$mul</td>";
                    }
				}
				echo "</tr>";
            }
            
            echo "</table>";
		?>
	</body>
</html>