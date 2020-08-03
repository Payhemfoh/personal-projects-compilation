<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market-Careers</title>
		<?php
            include("headInclude.html");
        ?>
		<link rel="stylesheet" type="text/css" href="script/home-list-detail.css">
		<link rel="stylesheet" type="text/css" href="script/login-register.css">
	</head>
	
	<body id="main">
		<?php
			include("./script/commonFunction.php");
			include("header.php");
		
			echo "
				<div class='content fluid-container' id='content'>
					<div id='title-img'>
						<img src='pictures/item.jpg' class='title-img'>
					</div>
					<br><br>
					<article id='career-title1'>
						<figure>
							<img src=''>
							<figcaption class='career-title'>Want to Join Us?<figcaption>
						</figure>
						<p class='about-text'>
							Are you a fresh graduate?
							<br>or is finding a job?
							<br>or maybe you want to try the e-commerce?
							<br>Are you worried about no experience to gain the jobs?
							<br><br>
							Maybe you can join us! We are hiring members who are interested to e-commerce.
							Even you did not have any experience in e-commerce.
							<br>In Shipper Market, everyone of us are a family,we tend to help others who faced problems.
							<br><br>If you are interested in joining us, you may scroll down and submit the form.	
							<br>
						</p>
					</article>
					<br><br>
					<article id='career-title2'>
						<figure>
							<img src=''>
							<figcaption class='career-title'>Our Merit!<figcaption>
						</figure>
						<p class='about-text'>We contains several merits for our staffs:</p>
						<dl>
							<dt class='about-text'>EPF</dt>
							<dd class='about-text'>We offer the EPF for our staffs highest to 20% of the basic salary as our staffs working hard for our website.</dd>
							<dt class='about-text'>Bonus</dt>
							<dd class='about-text'>Every season, we will provide bonus to the staffs in order to encourage the staffs.</dd>
							<dt class='about-text'>Travelling</dt>
							<dd class='about-text'>Every year, we will conduct a travelling for our staffs for relaxing purposes.</dd>
							<dt class='about-text'>Training</dt>
							<dd class='about-text'>We offer several training lessons to improve our staffs in the certain fields.</dd>
						</dl>
					</article>
					<br><br>
					<article id='career-title3'>
						<figure>
							<img src=''>
							<figcaption class='career-title'>Our Department!<figcaption>
						</figure>
						<p class='about-text'>We contains of several departments as below:</p>
						<dl>
							<dt class='about-text'>Commercial & Marketing</dt>
							<dd class='about-text'>Promote the website to others to increase the popularity.</dd>
							<dt class='about-text'>Technology & Security</dt>
							<dd class='about-text'>Develop and improve the efficiency and the security of the website and prevent the website from cyber criminals such as hacking.</dd>
							<dt class='about-text'>Logistics & Corporate Function</dt>
							<dd class='about-text'>Corporate with the saler to get products and publish on the website to promote to others.</dd>
							<dt class='about-text'>Customer care & Strategy management</dt>
							<dd class='about-text'>Communicate with customer to solve the problems and determine the strategy suitable for the website.</dd>
						</dl>
					</article>
					<br><br>";
		
			if(isset($_POST['submitted'])){
				//get variables from career page
				$email      =$_POST['email'];
				$firstName  =$_POST['firstName'];
				$lastName   =$_POST['lastName'];
				$address    =$_POST['address'];
				$postcode   =$_POST['postcode'];
				$area       =$_POST['area'];
				$country    =$_POST['country'];
				$phoneNo    =$_POST['phoneNo'];
			
				/*
				-----------------------check conditions--------------------
				*/
				//boolean for check conditions
				$submit = true;
			
				//email
				if(!validateEmail($email))
					$submit = false;
		
		
				//firstName
				if(!validateCharacterOnly($firstName,"First Name"))
					$submit = false;
			
			
				//lastName
				if(!validateCharacterOnly($lastName,"Last Name"))
					$submit = false;
			
			
				//address
				if(!validateAddress($address))
					$submit = false;
			
				//postcode
				if(!validatePostcode($postcode))
					$submit = false;
			
				//area
				if(!validateCharacterOnly($area,"Area"))
					$submit = false;
			
				//country
				if(!validateCharacterOnly($country,"Country"))
					$submit = false;
			
			
				//phoneNo
				if(!validatePhoneNo($phoneNo))
					$submit = false;
			
				/*
				-----------decide either the registration success or failed and print message---------------
				*/
				echo "<center>";
				if($submit){
					echo "Your form is submitted to the website manager successfully.<br>";
				}
				else{
					echo "<br>Sorry, the form has not submitted successfully<br>";
				}
				echo "</center>";
				
			}else{
				echo "	<h1 class='text-center' style='color:red; font-family:Arial;'>Are you Interested in joining us? Fill in the Form and Submit now!</h1>
						<form method='post' action='Careers.php' class='sign-register-box'>
							<label for='email' class='label'>Email</label><br>
							<input type='email' name='email' placeholder='Email' class='sign-input' tabindex='1'><br>

							<label for='firstName' class='label'>First Name</label><br>
							<input type='text' name='firstName' placeholder='First name' class='sign-input' tabindex='2'><br>

							<label for='lastName' class='label'>Last Name</label><br>
							<input type='text' name='lastName' placeholder='Last name' class='sign-input' tabindex='3'><br>

							<label for='address' class='label'>Address</label><br>
							<input type='text' name='address' placeholder='Address' class='sign-input' tabindex='4'><br>

							<label for='postcode' class='label'>Postcode</label><br>
							<input type='number' name='postcode' placeholder='Postcode' class='sign-input' tabindex='5'><br>

							<label for='area' class='label'>Area</label><br>
							<input type='text' name='area' placeholder='Area' class='sign-input' tabindex='6'><br>

							<label for='country' class='label'>Country</label><br>
							<input type='text' name='country' placeholder='Country' class='sign-input' tabindex='7'><br>

							<label for='phoneNo' class='label'>Phone No</label><br>
							<input type='number' name='phoneNo' placeholder='+60' class='sign-input' tabindex='8'><br>

							<input type='submit' value='Enquiry Now!' class='sign-submit btn btn-warning text-center' tabindex='9'>
							<input type='hidden' name='submitted' value='true'>
						</form>
					</div>
				";
			}

			
			include("footer.html");
			
		?>
	</body>
</html>