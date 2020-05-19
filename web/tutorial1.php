<?php
	echo "Today I will learn PHP variabes.<br>";
	echo "Tomorrow I'll learn PHP arrays.<br>";
	echo "<h1>This is heading 1</h1>";
	echo "<h2>This is heading 2</h2>";
	echo "<h3>This is heading 3</h3>";
	echo "<h4>This is heading 4</h4>";
	echo "<h5>This is heading 5</h5>";
	echo "<h6>This is heading 6</h6>";
	
	$var = "PHP Tutorial";
	echo "<h3>$var</h3>
	<p>
		PHP, an acronym for Hypertext Preprocessor, is a widely-used open 
		source general-purpose scripting language. It is a cross-platform, HTML 
		embedded server-side scripting language and is especially suited for web 
		development.
		Go to the $var.
	</p>";
	
	$x = 10;
	$y = 7;
	$sum = $x + $y;
	$minus = $x - $y;
	$multiply = $x * $y;
	$moduler = $x % $y;
	$division = (float)$x / $y;
	printf("%d + %d = %d<br>",$x,$y,$sum);
	printf("%d - %d = %d<br>",$x,$y,$minus);
	printf("%d * %d = %d<br>",$x,$y,$multiply);
	printf("%d / %d = %d<br>",$x,$y,$division);
	printf("%d %% %d = %d<br>",$x,$y,$moduler);
	printf("%d / %d = %f<br>",$x,$y,$x/$y);
	
	$color = array("red"=>"ff0000","blue"=>"00ff00","green"=>"0000ff");
	var_dump($color);
	$bool = true;
	var_dump($bool);
	var_dump($x);
	var_dump($y);
	var_dump($x/$y);
	
	class str{
		public $se = "Hi";
		function show_str(){
			return this.$se;
		}
	}
	
	$message = new str;
	var_dump($message);
?>
