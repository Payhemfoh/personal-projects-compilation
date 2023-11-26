/*
 * This program will play the music:
 * Happy Birthday (G Major) repeatly
 */

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587

const int Pin2 = 2;
const int Pin8 = 8;
const int SIZE = 25;


int main(){
  //initialize the device
  init();
  pinMode(Pin2,INPUT_PULLUP);

  //create array for melody and time duration
  int melody[SIZE] = {NOTE_D4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_G4,NOTE_FS4,
                      NOTE_D4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_A4,NOTE_G4,
                      NOTE_D4,NOTE_D4,NOTE_D5,NOTE_B4,NOTE_G4,NOTE_FS4,
                      NOTE_E4,NOTE_C5,NOTE_C5,NOTE_B4,NOTE_G4,NOTE_A4,NOTE_G4};

  //note duration: 4 for quarter
  int durations[SIZE] = {6,8,4,4,4,2,
                         6,8,4,4,4,2,
                         6,8,4,4,4,4,
                         4,6,8,4,4,4,2};
  
  
  while(true){
    //loop over each note
    for(int note=0; note<SIZE; ++note){
      
      //calculate the note duration based on the durations[]
      int noteDuration = 2000/ durations[note];
      tone(Pin8,melody[note],noteDuration);

      //place a break between notes
      int pauses = noteDuration * 1.30;
      delay(pauses);
      noTone(Pin8);
    }
  }
  
  return 0;
}
