<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Lab7-Question4</title>
		<meta charset="utf-8">
	</head>
	
	<body>
		<form method="post" action="Lab7_Question4_process.php">
		<h1>Event Feedback</h1>
		<p>Thank you for participating in our event. We hope you had as much fun attending as we did organizing it.</p>
		<p>We want to hear your feedback so we can keep improving our logistics and content. 
		Please fill this quick survey and let us know your thoughts (your answers will be anonymous).</p>
		
		<p style="color:red">* Required</p>
		<?php
			
		?>
			<label for="addition_comment">Any additional comments regarding the sessions or overall agenda?</label><br>
			<input type="text" name="addition_comment" placeholder="Your Answer">
			<br><br>

			<label for="overall">Any overall feedback for the event?</label><br>
			<input type="text" name="overall" placeholder="Your Answer">
			<br><br>

			<label for="name">Name (optional)</label><br>
			<input type="text" name="name" placeholder="Your Answer">
			<br><br>

			<input type="submit">
		</form>
	</body>
</html>