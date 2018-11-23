<meta charset="utf-8">
<?php
//Realizamos de nuevo la conexión al servidor de la base de datos 
$conn = new mysqli("localhost", "", "", "") or die("error de conexion " .mysql_error());
/*
En caso de que la conexión no haya sido realizada va a mostrar un error y se mostrará en la pagina web. 
*/
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
/*
En caso de que si haya hecho la conexión mostrará ese mensaje
*/

else{ echo "Conexion realizada exitosamente";}

/*
en la variable SQL guardaremos el Query que realiza la busqueda de los datos en la tabla donde le decimos que el dato que nos importa es que luz sea igual a 4  y ademas de ordenarlo por fecha con un limite de 10 datos por ver 
*/
$sql ="SELECT * FROM yellow WHERE  luz = '4' ORDER BY fecha LIMIT 10" ;
//En la variable result guardaremos el resultado de de query
$result = $conn->query($sql);

//revisamos si el resultado es mayor a 0 
if (mysqli_num_rows($result) > 0  ) {
	# code...
	//En caso de que si realizamos un ciclo while donde se realiza un array y se guardaran ahi los resultados
	while ($row = mysqli_fetch_array($result)) {
		# code...
		//Se imprimen los resultados en la pagina web 
		echo $row ['ID'] . "\t" . $row['temp'] . "\t" .$row['hum'] . "\t" . $row['mov'] . "\t" . $row['luz'] ."\t" .$row['fecha'] . "\n\r";

	}
}

$conn->close();


  ?>