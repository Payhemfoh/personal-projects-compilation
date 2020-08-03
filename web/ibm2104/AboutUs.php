<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market-About Us</title>
		<?php
            include("headInclude.html");
        ?>
		<link rel="stylesheet" type="text/css" href="script/home-list-detail.css">
	</head>
	
	<body id="main">
		<?php
			include("header.php");
			
			echo "
				<div class='content fluid-container' id='content'>
					<div id='title-img'>
						<img src='pictures/item.jpg' class='title-img'>
					</div>
					<br><br>
					<article id='about-title1'>
						<figure>
							<figcaption class='about-title' id='about-title1'>What is Shipper Market? Our story?</figcaption>
						</figure>
						<p class='about-text'>
							We started Shipper Market because of the changes of social. Nowadays, more people require online portal for shopping purpose due to many problems such as MCO (Movement Control Order) or insufficient time.

							That\'s why we want to provide the online portal for users so that users can have an excellent experience when proceed the e-commerce.

							Along the way, we tried to build the website by learning and apply different technologies so that a better performance could be produce to the users.

							We want to provide a greater service to the usersregardless countries and races.
						</p>
						<br>
					</article>
					<br><br>
					<article id='about-title2'>
						<figure>
							<figcaption  class='about-title'  >Our target</figcaption>
						</figure>
						<p class='about-text'>
							Our main target is provide a comfortable environment to the users so that the users can gain a good experience during e-commerce. 
							To archieve the target, the upgrade and the maintenance of the website will be conducted so that the performance of the website could be improved.
							Besides, we would like to provide a better and safe portal for the users to conduct e-business.
						</p>
						<br>
					</article>
					<br><br>
					<article id='about-title3'>
						<figure>
							<figcaption  class='about-title'  >Our Service</figcaption>
						</figure>
						<p class='about-text'>
							Our website provide several services:
							<br><br>
							First, as a user, you may refer to the product list or search for certain products.
							You may buy the products you like through the website and contact the seller.
							<br><br>
							Second, you may become a seller which means that you may also sell your products to others through the website too.
							To become the seller, you need to refer to the <a href='Careers.php'>career page</a> for more information.
							<br><br>
							Third, our website provide a safe and rapid delivery system which could transport the products to the destination as soon as possible.
							By the way, the transport fee will be reduced as low as possible.
							<br><br>
							For more information, you may contact our staff through the <a href='ContactUs.php'>contact page.</a>
						</p>
						<br>
					</article>
				</div>
			";

			echo "
				<footer>
				
					<div class='footer-sign-up'> 
						Want to shopping in Shipper Market? Click here to <a href='Register.php' class='footer-link'>register your free account</a>
						or you already <a href='SignIn.php' class='footer-link'>have an account?</a>
						<br>
						Interesting in joining us? Please refer to our <a href='Career.php' class='footer-link'>career page</a> for more information!
						<br>
						More information about Shipper Market? Please refer to our <a href='AboutUs.php' class='footer-link'>about page</a>.
					</div>
					
					<div class='footer-line'>
					</div>
					
					<div class='footer-contact'>
						<p>E-mail:<a href='mailto:#'>#@mail.com</a>
						<p>More contact method please refer to the our <a href='ContactUs.php' class='footer-link'>contact page</a>.
					</div>
					<p class='copyright' style='font-size:10px;'>The website is owned by Shipper Market &copy;2020</p>
				</footer>
			";
		?>
	</body>
</html>