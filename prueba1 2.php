<meta charset="utf-8">
<?php
$servername = "localhost";
$username = "variables";
$password = "variables01";
$dbname = "variables";


// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$hum = $_POST['hum'];
$temp = $_POST['temp'];
$luz = $_POST['luz'];
$mov = $_POST['mov'];
$sql = "INSERT INTO yellow (temp,hum, mov, luz, fecha)
VALUES ('$temp', '$hum', '$mov','$luz', now())";

if ($temp!= null || $hum!= null || $luz!= null || $mov!= null) {
	# code...	
	$result = mysqli_query($conn, $sql);
echo "New record created successfully";
}

 else {
    echo "Error: " .$sql . "<br>" . $conn->error;
}

$conn->close();
?>