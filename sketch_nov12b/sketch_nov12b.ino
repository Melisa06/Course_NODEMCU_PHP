//#include <dummy.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

/* Set these to your desired credentials. */
const char *ssid = "Intel-IoT";  //ENTER YOUR WIFI SETTINGS
const char *password = "1N73RN37D3L45C0545";

//Web/Server address to read/write from 
const char *host = "172.31.150.237";   //https://circuits4you.com website or IP address of server

//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  delay(1000);
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, !LOW);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient

  String ADCData, temp, hum, mov, luz, postData;
  int v_luz = (1024-analogRead(A0))/10.24;
  luz = String(v_luz);
  //ADCData = String(842);   //String to interger conversion
  
  temp = "1";
  hum = "2";
  mov= "3";
  //luz ="4";
 

  //Post Data
  postData = "temp="  + temp  +  "&hum="  + hum +  "&mov="   + mov +  "&luz="  + luz;
 //postData = "$temp=12,$hum=65,$mov=59,$lum=78";
  
  http.begin("http://cidtai.uteq.edu.mx/intel/iot/variables/Pruebas1/Query/prueba1.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  //http.addHeader("Content-Type", "text/plain");    //Specify content-type header
   
  long httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  Serial.println(postData);

  http.end();  //Close connection

  //ACTUADORES
  if(payload.indexOf("1") > 0)
  {
    digitalWrite(LED_BUILTIN, !HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, !LOW);
  }

  
  
  delay(5000);  //Post Data at every 5 seconds
}



