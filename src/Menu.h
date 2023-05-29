void Main_Menu() {
  
  Feed_Display.clearDisplay();
  Feed_Display.setTextColor(SSD1327_WHITE);
  Feed_Display.setTextSize(2); 
  Feed_Display.setCursor(center(Mode_Array[Mode_Array_Pos].length()),0);
  Feed_Display.println(Mode_Array[Mode_Array_Pos]);

  //----Feed----//
  if (Mode_Array_Pos == 0) {
    Feed_Display.setCursor(19,30);
      if (Measure_Array_Pos == 0) {
        Feed_Display.fillRect(18,29,Measure_Array[0].length() * 12 + 1,16,SSD1327_WHITE);       //fill selection with a contrasting rectangle
        Feed_Display.setTextColor(SSD1327_BLACK);
        Feed_Display.print(Measure_Array[0]);
        Feed_Display.setTextColor(SSD1327_WHITE);
      } else {
        Feed_Display.setTextColor(SSD1327_WHITE);
        Feed_Display.print(Measure_Array[0]);
      }
      Feed_Display.print(" / "); 
      if (Measure_Array_Pos == 1) {
        Feed_Display.fillRect(77,29,Measure_Array[1].length() * 12 + 2,16,SSD1327_WHITE);       //fill selection with a contrasting rectangle
        Feed_Display.setTextColor(SSD1327_BLACK);
        Feed_Display.print(Measure_Array[1]);
        Feed_Display.setTextColor(SSD1327_WHITE);        
      } else {
        Feed_Display.setTextColor(SSD1327_WHITE);
        Feed_Display.print(Measure_Array[1]);
      }
    Feed_Adjust();
  
  }
//----Thread----//
  if (Mode_Array_Pos == 1) {
    Feed_Display.setTextSize(2);
    Feed_Display.setCursor(2,30);
      if (Thread_Mode == 0) {
        Feed_Display.fillRect(0,29,36,16,SSD1327_WHITE);       //fill selection with a contrasting rectangle
        Feed_Display.setTextColor(SSD1327_BLACK);
        Feed_Display.print("TPI ");
        Feed_Display.setTextColor(SSD1327_WHITE);
      } else {
        Feed_Display.setTextColor(SSD1327_WHITE);
        Feed_Display.print("TPI");
      }
      Feed_Display.print("/"); 
      if (Thread_Mode == 1) {
        Feed_Display.fillRect(59,29,64,16,SSD1327_WHITE);       //fill selection with a contrasting rectangle
        Feed_Display.setTextColor(SSD1327_BLACK);
        Feed_Display.print(" Pitch");
        Feed_Display.setTextColor(SSD1327_WHITE);
        
      } else {
        Feed_Display.setTextColor(SSD1327_WHITE);
        Feed_Display.print("Pitch");
      }
    Feed_Display.setTextSize(4);
    if (Thread_Mode == 0) {Feed_Display.setCursor(35,65); Feed_Display.print(TPI_Array[TPI_Array_Pos]);}
    else {Feed_Display.setCursor(10,65); Feed_Display.print(Pitch_Array[Pitch_Array_Pos]); 
      Feed_Display.setTextSize(2); Feed_Display.setCursor(80,100); Feed_Display.println("(mm)");}
  }

  if (Mode_Array_Pos > 1) {
    Feed_Display.setCursor(0 + Mode_Array_Pos * 6, 30 + Mode_Array_Pos * 5);
    Feed_Display.println("Coming");
    Feed_Display.setCursor(0 + Mode_Array_Pos * 10, 60 + Mode_Array_Pos * 5);
    Feed_Display.print("Soon");
  }
}

void Feed_Adjust(){
  Feed_Display.setTextSize(4);
  Feed_Display.setCursor(0,65);
  if (Measure_Array_Pos == 0) {Feed_Display.print(In_FeedRate, 3);}
  else {Feed_Display.print(mm_FeedRate, 3);}
}

int center(int ctr_int) {          
  ctr = 55-((9 * ctr_int)/2);
  return ctr;
}

void Feed_Clear(){
  Feed_Display.fillRect(0,65,128,30,SSD1327_BLACK);
}