<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market-Homepage</title>
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
					<h1>Welcome to Shipper Market</h1>
					
					<div id='searchbar'>
						<form method='get' action='./processing/searchbar-processing.php'>
							<input type='text' name='search' placeholder='Search product..'>
							<input type='submit' value='Submit' class='btn btn-warning'>
						</form>
					</div>
					
					<div id='titlePhoto'>
						<img src='pictures/item.jpg' class='title-img'>
					</div>
			";

			echo "
				<div id='suggestion'>
					<h2 style='padding-left:40px; font-family:George;'> Here are some suggestions:</h2>
					<ul type='none' id='sug-list'>
						<li class='sug-block'>
							<a href='detail-page/cadbury.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/cadbury.png' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Cadbury Chocolate</figcaption>
									<p class='sug-des'>Price:RM12.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
						
						<li class='sug-block'>
							<a href='detail-page/cola.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/cola.jpg' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Coca Cola</figcaption>
									<p class='sug-des'>Price:RM4.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
						
						<li class='sug-block'>
							<a href='detail-page/colgate.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/colgate.jpg' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Colgate toothpaste</figcaption>
									<p class='sug-des'>Price:RM12.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
						
						<li class='sug-block'>
							<a href='detail-page/farmhouse.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/farmhouse.jpg' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Farmhouse milk</figcaption>
									<p class='sug-des'>Price:RM6.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
						
						<li class='sug-block'>
							<a href='detail-page/dutchlady.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/dutchlady.jpg' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Dutchlady Milk</figcaption>
									<p class='sug-des'>Price:RM5.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
						
						<li class='sug-block'>
							<a href='detail-page/dove.php' class='sug-link'>
								<figure class='sug'>
									<img src='pictures/dove.jpeg' class='sug-img'>
									<div class='line'></div>
									<figcaption class='item-name'>Dove body wash</figcaption>
									<p class='sug-des'>Price:RM25.00/pic<br>
														Published by: Anonymous<br>
														Published on: 06/May/2020</p>
								</figure>
							</a>
						</li>
					</ul>
						<a href='ProductsListPage.php' class='sug-link'>
							<button id='more' class='btn btn-block btn-warning'>More</button>
						</a>
					</div>
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