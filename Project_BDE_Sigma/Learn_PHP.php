<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Ao XIE Learn PHP</title>
</head>

<body>
	<h1>My first PHP page</h1>
	<?php
	class Player{
		var $speed = 100;
		var $locationX = 200;
		
		function getSpeed(){
			return $this->speed;
		}
		function setSpeed($speed = 0){
			$this->speed = $speed;
		}
		function setLocationX($location = 0){
			$this->locationX = $location;
		}
		function getLocationX(){
			return $this->locationX;
		}
	}
	
	$p1 = new Player();
	echo $p1->getSpeed();
	?>
	
	<h2>Hello World!</h2>
	<?php
	echo "<h2>PHP is fun!</h2>";
	echo "Hello world!<br>";
	echo "I'm about to learn PHP!<br>";
	echo "This", " string", " was", " made", " with multiple parameters.";
	?>
</body>
</html>