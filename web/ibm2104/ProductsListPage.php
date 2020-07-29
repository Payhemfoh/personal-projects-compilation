<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market-Product List Page</title>
		<?php
            include("headInclude.html");
        ?>
		<link href='https://fonts.googleapis.com/css?family=Arvo' rel='stylesheet'>
		<link rel="stylesheet" type="text/css" href="script/list-detail-page.css">
	</head>
	
	<body id="main">
		<?php
			if(isset($_GET['search'])){
				$search = $_GET['search'];
			}else{
				$search = '';
			}

			include("header.php");
			
			echo "
				<div class='content fluid-container' id='content'>
					
				<div id='searchbar'>
					<form method='get' action='./processing/searchbar-processing.php'>
						<input type='text' name='search' placeholder='Search product..' value='$search'>
						<input type='submit' value='Submit' class='btn btn-warning'>
					</form>
				</div>
					
					<div class='product-list'>
						<div class='col-xs-3'>
							<a href='detail-page/cadbury.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/cadbury.png' class='list-img'>
									<figcaption class='list-name text-center'>Cadbury Chocolate</figcaption>
									<p class='text-center list-price'>RM12.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/cola.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/cola.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Coca Cola</figcaption>
									<p class='text-center list-price'>RM4.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/colgate.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/colgate.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Colgate Toothpaste</figcaption>
									<p class='text-center list-price'>RM12.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/dove.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/dove.jpeg' class='list-img'>
									<figcaption class='list-name text-center'>Dove body wash</figcaption>
									<p class='text-center list-price'>RM25.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/dutchlady.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/dutchlady.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Dutchlady</figcaption>
									<p class='text-center list-price'>RM5.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/farmhouse.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/farmhouse.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Farmhouse Milk</figcaption>
									<p class='text-center list-price'>RM6.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/kitket.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/kitket.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Kitket Chocolate</figcaption>
									<p class='text-center list-price'>RM3.50/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
						<div class='col-xs-3'>
							<a href='detail-page/lifebuoy.php' class='product-link'>
								<figure class='list-block'>
									<image src='pictures/lifebuoy.jpg' class='list-img'>
									<figcaption class='list-name text-center'>Lifebuoy Hand Soap</figcaption>
									<p class='text-center list-price'>RM8.00/pic</p>
									<p class='seller-name text-center'>Anonymous<br>06-May-2020</p>
								</figure>
							</a>
						</div>
						
							<button class='btn btn-default btn-block btn-warning btn-lg'>More</button>
					</div>
				</div>
			";

			include("footer.html");
		?>
	</body>
</html>