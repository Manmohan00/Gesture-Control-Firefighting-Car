/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

WiFiClient client;


boolean fun = false;
int Fire = 15;
int lay = 16;

String MakerIFTTT_Key ;
;String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;

void setup()
{
  Serial.begin(9600);
  pinMode(Fire,INPUT);
  pinMode(lay,OUTPUT);
  WiFi.disconnect();
  delay(300);
  Serial.println("START");
   WiFi.begin("wonheda","the100100");
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
 

}

void aag()
{
 if (client.connect("maker.ifttt.com",80)) 
 {
    MakerIFTTT_Key ="bkOZVLNdgH_MdbLPBkTBKq53MQVOuqsZUPcnS4RA08f";
    MakerIFTTT_Event ="fire";
    p = post_rqst;
    p = append_str(p, "POST /trigger/");
    p = append_str(p, MakerIFTTT_Event);
    p = append_str(p, "/with/key/");
    p = append_str(p, MakerIFTTT_Key);
    p = append_str(p, " HTTP/1.1\r\n");
    p = append_str(p, "Host: maker.ifttt.com\r\n");
    p = append_str(p, "Content-Type: application/json\r\n");
    p = append_str(p, "Content-Length: ");
    content_length_here = p;
    p = append_str(p, "NN\r\n");
    p = append_str(p, "\r\n");
    json_start = p;
    p = append_str(p, "{\"value1\":\"");
    p = append_str(p, "7977740565");
    p = append_str(p, "\",\"value2\":\"");
    p = append_str(p, "Fire cannot kill a dragon");
    p = append_str(p, "\",\"value3\":\"");
    p = append_str(p, "");
    p = append_str(p, "\"}");

    compi= strlen(json_start);
    content_length_here[0] = '0' + (compi/10);
    content_length_here[1] = '0' + (compi%10);
    client.print(post_rqst);

  }
  fun = true;
}

void loop()
{
  
int Val = digitalRead(Fire);
Serial.println(Val);
//Serial.print("\n");

 if (Val == 0)
 {
  digitalWrite(lay,HIGH);
  Serial.println("Water motor working");
  if (fun == false)
  {
   Serial.println("Alerting");
   aag();
  }
 }
  else
  {
    digitalWrite(lay,LOW);
    if (fun == true)
    {
      fun = false;
    }
  }

}
