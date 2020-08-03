<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Lab7-Question4</title>
		<meta charset="utf-8">
        <style>
            body{
                background-color:orange;
            }
            form{
                background-color:rgba(255,255,255,0.7);
                padding:20px;
                margin: 20px 20%;
                border-radius:20px;
            }
            fieldset,.title {
                background-color:white;
                border-radius:10px;
                padding:20px;
                margin: 20px 20%;
            }
            input[type=text]{
                width:60%;
                margin:5px;
                margin-left:20px;
            }
            .redtext{
                color:red;
            }
            th,td{
                padding:5px;
            }
            .smalltext{
                font-size:12px;
            }
        </style>
	</head>
	
	<body>
		<form method="post" action="Lab7_Question4_process.php">
            <div class="title">
                <h1>Event Feedback</h1>
                <p>Thank you for participating in our event. We hope you had as much fun attending as we did organizing it.</p>
                <p>We want to hear your feedback so we can keep improving our logistics and content. 
                Please fill this quick survey and let us know your thoughts (your answers will be anonymous).</p>
                    
                <p class="redtext">* Required</p>
            </div>
            <br>

            <fieldset>
                <?php
                    echo "<label for=\"satisfied\">How satisfied were you with the event?<b class=\"redtext\">*</b></label><br>";
                    echo "<table>";
                    echo	"<tr>";
                    echo		"<td></td>";
                    for($i=1;$i<=5;$i++){
                        echo "<td> $i</td>";
                    }
                    echo		"<td></td>";
                    echo	"</tr>";
    
                    echo	"<tr>";
                    echo		"<td>Not very</td>";
                    for($i=1;$i<=5;$i++){
                        echo "<td><input type=\"radio\" value=$i name=\"satisfied\" required></td>";
                    }
                    echo		"<td>Very much</td>";
                    echo	"</tr>";
                    echo "</table>";
                ?>
                </fieldset>

                <fieldset>
                <?php
                    echo "<label for=\"relavant\">How relevant and helpful do you think it was for your job?<b class=\"redtext\">*</b></label><br>";
                    echo "<table>";
                    echo	"<tr>";
                    echo		"<td></td>";
                    for($i=1;$i<=5;$i++){
                        echo "<td> $i</td>";
                    }
                    echo		"<td></td>";
                    echo	"</tr>";

                    echo	"<tr>";
                    echo		"<td>Not very</td>";
                    for($i=1;$i<=5;$i++){
                        echo "<td><input type=\"radio\" value=$i name=\"relavant\" required></td>";
                    }
                    echo		"<td>Very much</td>";
                    echo	"</tr>";
                    echo "</table>";
                ?>
            </fieldset>

            <fieldset>
                <label for="key">What were your key take aways from this event? </label><br>
                <input type="text" name="key" placeholder="Your Answer">
            </fieldset>

            <fieldset>
            <?php
                $field = array("Acommodation","Welcome_kit","Communication_emails","Transportation",
                                "Welcome_activity","Venue","Activities","Closing_ceremony");
                
                echo "<label for=\"logistics\">How satisfied were you with the logistics?<b class=\"redtext\">*</b></label><br>";
                echo "<table>";
                echo	"<tr>";
                echo		"<td></td>";
                for($i=1;$i<=6;$i++){
                    if($i==6){
                        echo "<td> N/A </td>";
                    }
                    else{
                        echo "<td> $i</td>";
                    }
                }
                echo	"</tr>";

                for($i=0;$i<sizeof($field);$i++){
                    echo	"<tr>";
                    echo		"<td>$field[$i]</td>";
                    for($j=1;$j<=6;$j++){
                        if($j==6){
                            echo "<td><input type=\"radio\" value=\"N/A\" name=\"".$field[$i]."\" required></td>";
                        }
                        else{
                            echo "<td><input type=\"radio\" value=$j name=\"".$field[$i]."\" required></td>";
                        }
                    }
                    echo	"</tr>";
                }
                
                echo "</table>";
				
			?>
            </fieldset>

            <fieldset>
			<label for="logistic_additional">Additional feedback on logistics<b class=\"redtext\">*</b> </label><br>
			<input type="text" name="logistic_addition" placeholder="Your Answer" required>
            </fieldset>

            <fieldset>
            <?php
                $field = array("Welcome_activity","Speaker_#1","Activity_#1","Speaker_#2","Activity_#2","Closing_activity");

                $choice = array("Not relevant","Relevant","Very Relevant","Did not attend");

                echo "<label for=\"relevant_session\">Which sessions did you find most relevant?<b class=\"redtext\">*</b></label><br>";
                echo "<table>";
                echo	"<tr>";
                echo		"<td></td>";
                for($i=0;$i<sizeof($choice);$i++){
                    echo "<td> $choice[$i] </td>";
                }
                echo	"</tr>";

                for($i=0;$i<sizeof($field);$i++){
                    echo	"<tr>";
                    echo		"<td>$field[$i]</td>";
                    for($j=0;$j<sizeof($choice);$j++){
                        echo "<td><input type=\"radio\" value=\"$choice[$j]\" name=\"".$field[$i]."\" required></td>";
                    }
                    echo	"</tr>";
                }

                echo "</table>";
            ?>
            </fieldset>

            <fieldset>
            <?php
				echo "<label for=\"session content\">How satisfied were you with the session content?</label><br>";
                echo "<table>";
                echo	"<tr>";
                echo		"<td></td>";
                for($i=1;$i<=5;$i++){
                    echo "<td> $i</td>";
                }
                echo		"<td></td>";
                echo	"</tr>";

                echo	"<tr>";
                echo		"<td>Poor</td>";
                for($i=1;$i<=5;$i++){
                    echo "<td><input type=\"radio\" value=$i name=\"session_content\"></td>";
                }
                echo		"<td>Excellent</td>";
                echo	"</tr>";
                echo "</table>";
				
			?>
            </fieldset>

            <fieldset>
			<label for="addition_comment">Any additional comments regarding the sessions or overall agenda?</label><br>
			<input type="text" name="addition_comment" placeholder="Your Answer">
            </fieldset>

            <fieldset>
			<label for="overall">Any overall feedback for the event?</label><br>
			<input type="text" name="overall" placeholder="Your Answer">
            </fieldset>

            <fieldset>
                <label for="name">Name (optional)</label><br>
                <input type="text" name="name" placeholder="Your Answer">
            </fieldset>
            
            <center>
			<input type="submit">
            </center>
		</form>
	</body>
</html>