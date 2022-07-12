int red = D1;
int green = D2;
int blue = D3;
int i;
int color;
int r=60;
int g=0;
int b=0;
int t=100;
void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);
}

void RGB_color(int red_light_value,int green_light_value,int blue_light_value)
{
  analogWrite(red,red_light_value);
  analogWrite(green,green_light_value);
  analogWrite(blue,blue_light_value);
}

void loop() 
{
  Serial.write("Enter a Mode no. \n");
  while (Serial.available()==0){}
  color=Serial.parseInt();
  label:
  switch(color)
    {
      case 1:
      RGB_color(255, 0, 0); // Red
      break;
      case 2:
      RGB_color(0, 255, 0); // Green
      break;
      case 3:
      RGB_color(0, 0, 255); // Blue
      break;
      case 4:
      RGB_color(255, 255, 125); // Raspberry
      break;
      case 5:
      RGB_color(0, 255, 255); // Cyan
      case 6:
      RGB_color(255, 0, 255); // Magenta
      break;
      break;
      case 7:
      RGB_color(255, 255, 0); // Yellow
      break;
      case 8:
      RGB_color(255, 255, 255); // White
      break;
      case 9:     //Dancing Mode
      {
        while(1)
        {
            for (/* no initialization */; r>=0, b<60; b++, r--) /*red -> blue*/
            {
            analogWrite(red, r);
            analogWrite(blue, b);
            delay(10);
            }
            
            for (/* no initialization */; b>=0, g<60; g++, b--) /*blue -> green*/
            {
            analogWrite(blue, b);
            analogWrite(green, g);
            delay(10);
            }
  
            for (/* no initialization */; g>=0, r<60; r++, g--) /*green -> red*/
            {
            analogWrite(red, r);
            analogWrite(green, g);
            delay(10);
            }
         
           color=Serial.parseInt();
           Serial.println(color);
           if(color!=0)
           {
            goto label;
            }
        }            
      }
     case 10:      //Gaming Mode
      {
        while(1)
        {
           for (/* no initialization */; r>=0, b<60; b++, r--) /*red -> blue*/
            {
            analogWrite(red, r);
            analogWrite(blue, b);
            delay(100);
            }

            for (/* no initialization */; b>=0, g<60; g++, b--) /*blue -> green*/
            {
            analogWrite(blue, b);
            analogWrite(green, g);
            delay(100);
            }
  
            for (/* no initialization */; g>=0, r<60; r++, g--) /*green -> red*/
            {
            analogWrite(red, r);
            analogWrite(green, g);
            delay(100);
            }
         
           color=Serial.parseInt();
           Serial.println(color);
           if(color!=0)
           {
            goto label;
            }
        }            
      }

    case 11:
    RGB_color(0, 20, 20); // Night Mode
    break;  
   
   case 12:             //red-blue
   {
    while(1)
    {
     for(;150<=r<=200, b<150; b++, r--)
     {
      analogWrite(red, r); 
      analogWrite(blue, b); 
      delay(t); 
     }
      for (; b>=0, r<155; r++, b--)
      {
       analogWrite(red, r); 
       analogWrite(blue, b);
       delay(t);
      }
     color=Serial.parseInt();
     Serial.println(color);
     if(color!=0)
     {
      digitalWrite(red,LOW); 
      digitalWrite(green,LOW);
      digitalWrite(blue,LOW);
      goto label;
      }
   }
 }
   case 13:      //red-green
   {
    for (; g>=0, r<255; r++, g--)
    {
     analogWrite(red, r); 
     analogWrite(green, g);
     delay(t);
    }
    for(;150<=r<=255, g<150; g++, r--)
    {
      analogWrite(red, r); 
      analogWrite(green, g); 
      delay(t); 
    }
    color=Serial.parseInt();
    Serial.println(color);
    if(color!=0)
    {
     digitalWrite(red,LOW); 
     digitalWrite(green,LOW);
     digitalWrite(blue,LOW);
     goto label;}
    }
   

    case 14:      //green-blue
   {
    while(1)
    {
      for(;150<=g<=255, b<150; b++, g--)
      {
       analogWrite(green, g); analogWrite(blue, b); 
       delay(t); 
       }
      for (;150<=b<=0, g<170; g++, b--)
      {
       analogWrite(blue, b); analogWrite(green, g);
       delay(t);
       }
    color=Serial.parseInt();
    Serial.println(color);
    if(color!=0)
    {
     digitalWrite(red,LOW); 
     digitalWrite(green,LOW);
     digitalWrite(blue,LOW);
     goto label;}
    }
  }
  
    case 15:
    RGB_color(0, 0, 0); //Led off
    break;
 }
}
