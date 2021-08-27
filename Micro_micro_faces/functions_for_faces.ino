void presentation(){
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(10, 10);
  display.println("Programed by");
  display.setCursor(20, 20);
  display.println("Josemanu");
  display.setCursor(20, 30);
  display.println("Push the");
  display.setCursor(26, 40);
  display.println("button");
}
  
void normal_face(){
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.setCursor(10, 0);
  display.println("Normal");
  display.fillRoundRect(posXleft, posYleft, 30, 20, radius, BLACK);
  display.fillRoundRect(posXright, posYright, 30, 20, radius, BLACK);
}

void sad_face(){
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.setCursor(20, 0);
  display.println("Sad");
  display.fillRoundRect(posXleft, posYleft, 30, 20, radius, BLACK);
  display.fillRoundRect(posXright, posYright, 30, 20, radius, BLACK);
  display.fillTriangle(posXleft, posYleft,
                       posXleft+30, posYleft,
                       posXleft, posYleft+5 , WHITE);
  display.fillTriangle(posXright, posYleft,
                       posXright+30, posYleft,
                       posXright+30, posYleft+5, WHITE);
}

void angry_face(){
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.setCursor(10, 0);
  display.println("Angry");
  display.fillRoundRect(posXleft, posYleft, 30, 20, radius, BLACK);
  display.fillRoundRect(posXright, posYright, 30, 20, radius, BLACK);
  display.fillTriangle(posXleft, posYleft,
                       posXleft+30, posYleft,
                       posXleft+30, posYleft+5 , WHITE);
  display.fillTriangle(posXright, posYleft,
                       posXright+30, posYleft,
                       posXright, posYleft+5, WHITE);
}

void skeptic_face(){
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.setCursor(10, 0);
  display.println("Skeptic");
  display.fillRoundRect(posXleft, posYleft, 30, 20, radius, BLACK);
  display.fillRoundRect(posXright, posYright, 30, 20, radius, BLACK);
  display.fillTriangle(posXright, posYleft,
                       posXright+30, posYleft,
                       posXright, posYleft+5, WHITE);
}                       
