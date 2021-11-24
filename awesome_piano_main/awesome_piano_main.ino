/*mega board main melody*/

/*select play mode*/
#define PIANO 1
#define MP3 2
#define RECORDER 3
/****************/
/*define for mp3*/
#define R -1
#define BIT_1 600
/***************/
/*fixed Tone library*/
#include <Tone.h>
#include "SPARKLE.h"

Tone speaker[6];
int  flag = PIANO;

void setup()
{
  int i;
  for (i=0;i<6;i++)
  {
     pinMode(i + 8, INPUT_PULLUP);
     speaker[i].begin(i + 2);
  }
  pinMode(0, INPUT_PULLUP);
}

void play_piano()
{
    if (flag == PIANO)
    {
        if (digitalRead(8) == 0)
            speaker[0].play(NOTE_C4, 100);
        if (digitalRead(9) == 0)
            speaker[1].play(NOTE_D4, 100);
        if (digitalRead(10) == 0)
            speaker[2].play(NOTE_E4, 100);
        if (digitalRead(11) == 0)
            speaker[3].play(NOTE_F4, 100);
        if (digitalRead(12) == 0)
            speaker[4].play(NOTE_G4, 100);
        if (digitalRead(13) == 0)
            speaker[5].play(NOTE_A4, 100);
    }
}

void play_mp3()
{
    static int cnt = 0;
    int        m;//current melody
    int        m_dur;//current melody duration
    int        h[2];//current harmony
    int        h_dur[2];//current harmony duration
    int        len = sizeof(melody) / sizeof(int16_t) / 2;//total row

    //play melody
    m = melody[cnt][0];
    m_dur = melody[cnt][1];
    if (m > 0)
      speaker[0].play(m, m_dur);

    //play harmony1
    h[0] = harmony[cnt][0];
    h_dur[0] = harmony[cnt][1];
    if (h[0] > 0)
      speaker[1].play(h[0], h_dur[0]);

    //play harmony2
    h[1] = harmony[cnt][0];
    h_dur[1] = harmony[cnt][1];
    if (h[1] > 0)
      speaker[1].play(h[1], h_dur[1]);
    cnt++;
  
    delay(m_dur);
    //delay(h_dur + 10);
    //delay(min(m_dur, h_dur[0], h_dur[1]));
    if (cnt == len)
        flag = PAINO;
}

int16_t record_melody[6][50][2];

void recording()
{
    static int    checker[6] = {0, };
    int           m[6] = {0, };
    int           m_dur[6] = {0, };
    int           m_start[6] = {0, };
    
    for (int i=0;i<6;i++)
    {
        if (i == 0 && digitalRead(8) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_C4;
            m_dur[i] = millis() - m_start[i];
        }
        if (i == 1 && digitalRead(9) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_D4;
            m_dur[i] = millis() - m_start[i];
        }
        if (i == 2 && digitalRead(10) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_E4;
            m_dur[i] = millis() - m_start[i];
        }
        if (i == 3 && digitalRead(11) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_F4;
            m_dur[i] = millis() - m_start[i];
        }
        if (i == 4 && digitalRead(12) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_G4;
            m_dur[i] = millis() - m_start[i];
        }
        if (i == 5 && digitalRead(13) == 0)
        {
            if (checker[i] == 0)
            {
                m_start[i] = millis();
                checker[i] = 1;
            }
            m[i] = NOTE_A4;
            m_dur[i] = millis() - m_start[i];
        }
        if (digitalRead(i + 8) == 1)
        {
            checker[i] = 0;
            m_start[i] = 0;
        }
    }
}

void loop()
{
    play_piano();
    if (digitalRead(0) == 0)
        flag = MP3;
    if (digitalRead(1) == 0)
        flag = RECORDER;
    if (flag == MP3)
        play_mp3();
    if (flag == RECORDER)
        recording();
}
