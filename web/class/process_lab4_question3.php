<?php
	$choice = $_POST['choice'];
	$attend = $_POST['attend'];
	$type = $_POST['type'];
	$comment = $_POST['comment'];
	
	echo "You have chosen <b>$choice</b>. The people that attend are <b>$attend</b>.<br>

		I heard about this event from <b>$type</b>.<br>

		You have commented <b>$comment</b>";
?>
