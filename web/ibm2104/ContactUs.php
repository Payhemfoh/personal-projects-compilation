<!DOCTYPE html>
<html lang='en'>
	<head>
		<title>Shipper Market-Contact Us</title>
		<?php
            include("headInclude.html");
        ?>
		<link rel="stylesheet" 
		href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" 
		integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" 
		crossorigin="anonymous">
		<link rel="stylesheet" type="text/css" href="script/contact.css">
	</head>
	
	<body id="main">
		<?php
			include("./script/commonFunction.php");
			include("header.php");
		
			echo "
				<div class='content fluid-container' id='content'>
					<div class='contact_1' id='contact_1'>
						<p id='text'>For more informations about the website please follow us on the social media:</p>
						<a class='media' id='media1' href='https://www.facebook.com' target='_blank'><i class='fab fa-facebook-f'></i></a>
						<a class='media' id='media2' href='https://www.twitter.com' target='_blank'><i class='fab fa-twitter'></i></a>
						<a class='media' id='media3' href='https://www.instagram.com' target='_blank'><i class='fab fa-instagram'></i></a>
						<a class='media' id='media4' href='mailto:#'><i class='fab fa-google'></i></a>
						<a class='media' id='media5' href='https://web.whatsapp.com' target='_blank'><i class='fab fa-whatsapp'></i></a>
						<a class='media' id='media6' href='https://www.wechat.com' class='_blank'><i class='fab fa-weixin'></i></a>
					</div>
					<div class='line' id='line'>
					</div>";
			
			echo "<div class='contact_2' id='contact_2'>";

			if(isset($_POST['submitted'])){
				//get variables from previous contactUs webpage
				$username = $_POST['username'];
				$email = $_POST['email'];
				$content = $_POST['content'];

				//check conditions
				$submit = true;
        
				//username
				if(!validateUsername($username))
					$submit = false;
			
				//email
				if(!validateEmail($email))
					$submit = false;
			
				if(!validateTextArea($content))
					$submit = false;
			
				if($submit){
					echo "Your form has been sent to the website manager.<br>
							Hello, <b>$username</b>"; 
				}
				else{
					echo "Sorry, the form has not submitted successfully<br>";
				}
			}else{
			echo "
						<p>If you have any questions, you may send email to our staffs by the form below:
						<form method='post' action='ContactUs.php'>
							<label for='username' class='label'>Username</label><br>
							<input type='text' class='input' placeholder='Username' name='username' tabindex='1' required><br>
							<label for='email'class='label'>Email</label><br>
							<input type='email' class='input' placeholder='Email' name='email' tabindex='2' required><br>
							<label for='content' name='mail' class='label'>Content</label><br>
							<textarea class='textbox' name='content' placeholder='You may enter the text into the textbox.' tabindex='3' required></textarea><br>
							<input type='hidden' name='submitted' value='true'>
							<input type='submit' value='Send' class='button btn-warning btn'>
						</form>";
			}
			echo "	</div>
					
				</div>";
			
		?>
	</body>
</html>