<?php
	if(empty($_COOKIE['currency'])){
		$currency = "RMY";
	}else{
		$currency = $_COOKIE['currency'];
	}

	if(empty($_COOKIE['country'])){
		$country = "Malaysia";
	}else{
		$country = $_COOKIE['country'];
	}

	if(empty($_COOKIE['language'])){
		$language = "English";
	}else{
		$language = $_COOKIE['language'];
	}

	session_start();
	if(!empty($_SESSION['username']))
		$usr = $_SESSION['username'];

?>

<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market-Register</title>
		<link rel="stylesheet" type="text/css" href="script/login-register.css">
		<?php
            include("headInclude.html");
        ?>
		<style>
		<?php
			if(!empty($_COOKIE['background_color']) && $_COOKIE['background_color']!="default"){
				echo "body{background-color:".$_COOKIE['background_color'].";}"; 
			}
			else{
				echo "body{background:url(\"pictures/background.JPEG\");}";
			}
		?>
			i{
				color:red;
			}
		</style>
	</head>
	
	<body id="main">
		
		<div class='header' id='myHeader'>
			<header>
				<nav id='navi'>
					<ul id='navigation'>
						<li class='nav-li'><a href='Homepage.php'  class='nav-logo'><img src='pictures/logo.png' alt='Logo' height='40px' width='40px' id='logo'></a></li>
						<li class='nav-li'><a href='Homepage.php'  class='nav-a'>Home</a></li>
						<li class='nav-li'><a href='ProductsListPage.php' class='nav-a'> Product list</a></li>
						<li class='nav-li'><a href='ContactUs.php'  class='nav-a'> Contact Us</a></li>
						<li class='nav-li'><a href='Careers.php' class='nav-a'>Career page</a></li>
						<li class='nav-li'><a href='AboutUs.php'  class='nav-a'>About Us</a></li>
						<li class='nav-li'><a href='SignIn.php' class='nav-b'>Sign In</a></li>
						<li class='nav-li'><a href='religionSetting.php' class='nav-b'>Change Religion Setting</a></li>
						<?php
							echo "<li class='nav-li'><a href='#' class='nav-b'>Language:<i>$language</i>  Country:<i>$country</i>  Currency:<i>$currency</i></a></li>";
						?>
					</ul>
				</nav>
			</header>
		</div>

	<?php	
			echo "
				<div class='content fluid-container' id='content'>
					<div class='sign-register-box'>";

			if(isset($_POST['submitted'])){
				include("register_process.php");
			}
			else{
				echo "	<h2 class='title'>Register</h2>
						<form method='post' action='Register.php'>
							<label for='username' class='label-text'>Username</label><br>
							<input type='text' name='username' placeholder='Username' class='sign-input' tabindex='1' required><br>

							<label for='password' class='label-text'>Password</label><br>
							<input type='password' name='password' placeholder='Password' class='sign-input' tabindex='2' required><br>

							<label for='email' class='label-text'>Email</label><br>
							<input type='text' name='email' placeholder='Email' class='sign-input' tabindex='3' required><br>

							<label for='firstName' class='label-text'>First Name</label><br>
							<input type='text' name='firstName' placeholder='First name' class='sign-input' tabindex='4' required><br>

							<label for='lastName' class='label-text'>Last Name</label><br>
							<input type='text' name='lastName' placeholder='Last name' class='sign-input' tabindex='5' required><br>

							<label for='address' class='label-text'>Address</label><br>
							<input type='text' name='address' placeholder='Address' class='sign-input' tabindex='6' required><br>

							<label for='postcode' class='label-text'>Postcode</label><br>
							<input type='text' name='postcode' placeholder='Postcode' class='sign-input' tabindex='7' required><br>

							<label for='area' class='label-text'>Area</label><br>
							<input type='text' name='area' placeholder='Area' class='sign-input' tabindex='8' required><br>

							<label for='country' class='label-text'>Country</label><br>
							<input type='text' name='country' placeholder='Country' class='sign-input' tabindex='9' required><br>

							<label for='phoneNo' class='label-text'>Phone No</label><br>
							<input type='text' name='phoneNo' placeholder='+60' class='sign-input' tabindex='10' required><br>

							<input type='submit' value='Register' class='sign-input btn btn-warning text-center' tabindex='11' required>
							<input type='hidden' name='submitted' value='true'>
						</form>
						<h6 class='link'>Already have an account? <a href='SignIn.php'>Click here to sign in to your account.</a></h6>";
			}
			echo"</div></div>";
		?>
	</body>
</html>