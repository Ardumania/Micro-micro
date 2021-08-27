void drawBatterieStatus(){
  // analog pin A5 is used for measure batterie level.
  int measure = analogRead(A5);

  // now the dificult part: 1023 corresponds to 5.0v
  // but our batterie is 4.2v at full charge and
  // 2.8v when empty, this is betwin 860 and 573, and
  // the nominal voltage (3.7v) is 757

  if(measure >= 788){
    display.drawBitmap(68, 0,  bat_full_bmp, 16, 7, 1);
  }else if(measure < 787 && measure >= 716){
    display.drawBitmap(68, 0,  bat_half_bmp, 16, 7, 1);
  }else if(measure < 715 && measure >= 644){
    display.drawBitmap(68, 0,  bat_empty_bmp, 16, 7, 1);
  }else if(measure < 643){
    display.drawBitmap(68, 0,  bat_panic_bmp, 16, 7, 1);
  }
}

