<?php
	$name = $_POST['name'];
	$time = $_POST['time'];
	$date = $_POST['date'];
	$type = $_POST['type'];
	$reason = $_POST['reason'];
	
	echo "Hi, <strong>$name</strong> ,has applied <strong>$time</strong>
			leave on <strong>$date</strong>.<br>";
	
	echo "You are applying for <b>$type</b> due to <b>$reason</b>.";
?>
