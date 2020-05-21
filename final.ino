void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  //Serial.println("CLEARDATA");
  //Serial.println(" LABEL, Time , A0 , A1, A2, A3, ... ");
  //Serial.println("RESETTIMER");
  pinMode ( A0, INPUT );
  pinMode ( A1, INPUT );
  pinMode ( A2, INPUT );
  pinMode ( A3, INPUT );
  pinMode ( A4, INPUT );
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
  
  pinMode(A11,INPUT);
  pinMode(A10,INPUT);
  pinMode(A12,INPUT);
  pinMode(A13,INPUT);
  pinMode(A14,INPUT);
  pinMode(A15,INPUT);
}

//void loop() {
//  // put your main code here, to run repeatedly:
//int a0 = analogRead (A0);
//int b0 = a0-650;
//Serial.print (" b0 = ");
//Serial.print (b0);
//int a1 = analogRead (A1);
//int b1 = a1-500;
//Serial.print (" b1 = ");
//Serial.print (b1);
//int a2 = analogRead (A2);
//int b2 = a2-500;
//Serial.print (" b2 = ");
//Serial.print (b2);
//int a3 = analogRead (A3);
//int b3 = a3-570;
//Serial.print (" b3 = ");
//Serial.print (b3);
//Serial.println("...");
//delay(1000);
//
//}

int arr[16];
char buf[60];

void loop() {
  // put your main code here, to run repeatedly:
arr[0] = analogRead(A0);
arr[1] = analogRead(A1);
arr[2] = analogRead(A2);
arr[3] = analogRead(A3);
arr[4] = analogRead(A4);
arr[5] = analogRead(A5);
arr[6] = analogRead(A6);
  if (arr[6]<400)
arr[6]=0;
else if (arr[6]>700)
arr[6]=1023;
else
arr[6]=512;
  arr[7] = analogRead(A7);

if (arr[7]<400)
arr[7]=0;
else if (arr[7]>800)
arr[7]=1023;
else
arr[7]=512;
  
  arr[8] = analogRead(A8);
  if (arr[8]<400)
arr[8]=0;
else if (arr[8]>700)
arr[8]=1023;
else
arr[8]=512;

  
  arr[15] = analogRead(A9);
  if (arr[15]<400)
arr[15]=0;
else if (arr[15]>700)
arr[15]=1023;
else
arr[15]=512;

  arr[9] = analogRead(A11);
  if (arr[9]<400)
arr[9]=0;
else if (arr[9]>700)
arr[9]=1023;
else
arr[9]=512;  
  arr[10] = analogRead(A10);
  if (arr[10]<400)
arr[10]=0;
else if (arr[10]>700)
arr[10]=1023;
else
arr[10]=512;
//Serial.println(arr);
arr[11] = analogRead(A12);
  if (arr[11]<400)
arr[11]=0;
else if (arr[11]>700)
arr[11]=1023;
else
arr[11]=512;

arr[12] = analogRead(A13);
  if (arr[12]<400)
arr[12]=0;
else if (arr[12]>700)
arr[12]=1023;
else
arr[12]=512;

arr[13] = analogRead(A14);
  if (arr[13]<400)
arr[13]=0;
else if (arr[13]>700)
arr[13]=1023;
else
arr[13]=512;

arr[14] = analogRead(A15);
  if (arr[14]<400)
arr[14]=0;
else if (arr[14]>700)
arr[14]=1023;
else
arr[14]=512;
sprintf(buf,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[15], arr[10], arr[9], arr[11], arr[12],arr[13],arr[14]);
//sprintf(buf,"%d    %d    %d    %d    %d    %d    %d   %d   %d   %d",arr[6],arr[7],arr[8],arr[15], arr[10], arr[9], arr[11], arr[12],arr[13],arr[14]);
Serial.println(buf);
//Serial.printf("%d|%d|%d|%d\r\n",arr[0],arr[1],arr[2],arr[3]);

delay(500);

}
