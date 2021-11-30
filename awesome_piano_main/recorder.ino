int16_t recorder[5][100][2];//녹음된 곡을 저장할 배열.

int8_t record_melody(unsigned long rd_start)//'도'음을 녹음.
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int8_t  cnt;
    static int8_t  checker;
    static int16_t  dur_interval;
    static int16_t  m;
    static int16_t  m_dur;

    if (digitalRead(8) == 0)//피아노 버튼이 눌렸을 시
    {
        if (checker == 3)//피아노 버튼을 떼었다가 다시 눌렀을 때, 그 사이 텀 R을 배열에 저장.
        {
            recorder[0][cnt][0] = R;
            recorder[0][cnt][1] = dur_interval;
            cnt++;
            checker = 1;
        }
        if (checker == 0)//피아노 버튼을 누른 시각 - 시작버튼을 누른 시각만큼 초기 R 설정.
        {
            m_start = millis();
            recorder[0][cnt][0] = R;
            recorder[0][cnt][1] = m_start - rd_start;
            cnt++;
            checker = 1;
        }
        if (checker == 1)//피아노 버튼을 누른 시각을 m_start에 저장.
        {
            m_start = millis();
            checker = 2;
        }
        if (checker == 2)//음이 울리고 있는 시간을 m_dur에 계속 업데이트.
        {
            m_end = millis();
            m_dur = m_end - m_start;
            m = NOTE_C4;
        }
    }
    else if (checker == 2)//피아노 버튼을 떼었을 때, 해당 음과 해당 음이 울린 시간 배열에 저장.
    {
        recorder[0][cnt][0] = m;
        recorder[0][cnt][1] = m_dur;
        recorder[0][cnt + 1][0] = 0;
        recorder[0][cnt + 1][1] = 0;
        cnt++;
        checker = 3;
    }
    else if (checker == 3)//피아노 버튼을 떼었을 때 시각 저장.
        dur_interval = millis() - m_end;
        
    if (digitalRead(OK) == 0)//녹음을 완료하였을 시 변수를 초기화하고 1반환.
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int8_t record_melody2(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int8_t  cnt;
    static int8_t  checker;
    static int16_t  dur_interval;
    static int16_t  m;
    static int16_t  m_dur;

    if (digitalRead(9) == 0)
    {
        if (checker == 3)
        {
            recorder[1][cnt][0] = R;
            recorder[1][cnt][1] = dur_interval;
            cnt++;
            checker = 1;
        }
        if (checker == 0)
        {
            m_start = millis();
            recorder[1][cnt][0] = R;
            recorder[1][cnt][1] = m_start - rd_start;
            cnt++;
            checker = 1;
        }
        if (checker == 1)
        {
            m_start = millis();
            checker = 2;
        }
        if (checker == 2)
        {
            m_end = millis();
            m_dur = m_end - m_start;
            m = NOTE_D4;
        }
    }
    else if (checker == 2)
    {
        recorder[1][cnt][0] = m;
        recorder[1][cnt][1] = m_dur;
        recorder[1][cnt + 1][0] = 0;
        recorder[1][cnt + 1][1] = 0;
        cnt++;
        checker = 3;
    }
    else if (checker == 3)
        dur_interval = millis() - m_end;
        
    if (digitalRead(OK) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int8_t record_melody3(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int8_t  cnt;
    static int8_t  checker;
    static int16_t  dur_interval;
    static int16_t  m;
    static int16_t  m_dur;

    if (digitalRead(10) == 0)
    {
        if (checker == 3)
        {
            recorder[2][cnt][0] = R;
            recorder[2][cnt][1] = dur_interval;
            cnt++;
            checker = 1;
        }
        if (checker == 0)
        {
            m_start = millis();
            recorder[2][cnt][0] = R;
            recorder[2][cnt][1] = m_start - rd_start;
            cnt++;
            checker = 1;
        }
        if (checker == 1)
        {
            m_start = millis();
            checker = 2;
        }
        if (checker == 2)
        {
            m_end = millis();
            m_dur = m_end - m_start;
            m = NOTE_E4;
        }
    }
    else if (checker == 2)
    {
        recorder[2][cnt][0] = m;
        recorder[2][cnt][1] = m_dur;
        recorder[2][cnt + 1][0] = 0;
        recorder[2][cnt + 1][1] = 0;
        cnt++;
        checker = 3;
    }
    else if (checker == 3)
        dur_interval = millis() - m_end;
        
    if (digitalRead(OK) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int8_t record_melody4(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int8_t  cnt;
    static int8_t  checker;
    static int16_t  dur_interval;
    static int16_t  m;
    static int16_t  m_dur;

    if (digitalRead(11) == 0)
    {
        if (checker == 3)
        {
            recorder[3][cnt][0] = R;
            recorder[3][cnt][1] = dur_interval;
            cnt++;
            checker = 1;
        }
        if (checker == 0)
        {
            m_start = millis();
            recorder[3][cnt][0] = R;
            recorder[3][cnt][1] = m_start - rd_start;
            cnt++;
            checker = 1;
        }
        if (checker == 1)
        {
            m_start = millis();
            checker = 2;
        }
        if (checker == 2)
        {
            m_end = millis();
            m_dur = m_end - m_start;
            m = NOTE_F4;
        }
    }
    else if (checker == 2)
    {
        recorder[3][cnt][0] = m;
        recorder[3][cnt][1] = m_dur;
        recorder[3][cnt + 1][0] = 0;
        recorder[3][cnt + 1][1] = 0;
        cnt++;
        checker = 3;
    }
    else if (checker == 3)
        dur_interval = millis() - m_end;
        
    if (digitalRead(OK) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int8_t record_melody5(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int8_t  cnt;
    static int8_t  checker;
    static int16_t  dur_interval;
    static int16_t  m;
    static int16_t  m_dur;

    if (digitalRead(12) == 0)
    {
        if (checker == 3)
        {
            recorder[4][cnt][0] = R;
            recorder[4][cnt][1] = dur_interval;
            cnt++;
            checker = 1;
        }
        if (checker == 0)
        {
            m_start = millis();
            recorder[4][cnt][0] = R;
            recorder[4][cnt][1] = m_start - rd_start;
            cnt++;
            checker = 1;
        }
        if (checker == 1)
        {
            m_start = millis();
            checker = 2;
        }
        if (checker == 2)
        {
            m_end = millis();
            m_dur = m_end - m_start;
            m = NOTE_G4;
        }
    }
    else if (checker == 2)
    {
        recorder[4][cnt][0] = m;
        recorder[4][cnt][1] = m_dur;
        recorder[4][cnt + 1][0] = 0;
        recorder[4][cnt + 1][1] = 0;
        cnt++;
        checker = 3;
    }
    else if (checker == 3)
        dur_interval = millis() - m_end;
        
    if (digitalRead(OK) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

void play_record()//mp3_player.ino에 정의한 함수를 조금 수정하여 녹음된 곡 재생에 활용.
{
    int8_t m_flag[5] = {0, };

    //Serial.println("PLAY!");
    lcd.setCursor(0, 0);
    lcd.print(F("Playing"));
    lcd.setCursor(0, 1);
    lcd.print(F("recorded song.."));
    while (1)
    {
        //포인터가 녹음한 노래가 저장되는 배열을 가르키게 함.
        melody = recorder[0];
        melody2 = recorder[1];
        melody3 = recorder[2];
        melody4 = recorder[3];
        melody5 = recorder[4];
        break ;
    }
    while (1)
    {
        if (!m_flag[0])
            m_flag[0] = play_melody(100);
        if (!m_flag[1])
            m_flag[1] = play_melody2(100);
        if (!m_flag[2])
            m_flag[2] = play_melody3(100);
        if (!m_flag[3])
            m_flag[3] = play_melody4(100);
        if (!m_flag[4])
            m_flag[4] = play_melody5(100);
        //모든 멜로디가 끝나면 while문 종료(모든 play_melody 함수가 1을 반환 했을시)
        if (m_flag[0] && m_flag[1] && m_flag[2] && m_flag[3] && m_flag[4])
            break ;
    }
    //포인터를 다시 null로 초기화, flag값을 PIANO모드로 변경
    melody = 0;
    melody2 = 0;
    melody3 = 0;
    melody4 = 0;
    melody5 = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Completed!"));
}

void recording()
{
    unsigned long rd_start = millis();//녹음 시작버튼이 눌린 시간 측정.
    int8_t        checker[5] = {0, };

    //Serial.println(F("Recording selected!"));
    lcd.setCursor(0, 0);
    lcd.print(F("Recording"));
    lcd.setCursor(0, 1);
    lcd.print(F("selected!"));
    ft_delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Recording..."));
    while (1)
    {   
        play_piano();//누른 버튼음을 들을 수 있게 play_piano함수 실행.
        //녹음이 모두 마쳐지면 while문 탈출.
        if (!checker[0])
            checker[0] = record_melody(rd_start);
        if (!checker[1])
            checker[1] = record_melody2(rd_start);
        if (!checker[2])
            checker[2] = record_melody3(rd_start);
        if (!checker[3])
            checker[3] = record_melody4(rd_start);
        if (!checker[4])
            checker[4] = record_melody5(rd_start);
        if (checker[0] && checker[1] && checker[2] && checker[3] && checker[4])
            break ;
    }
    //Serial.println(F("Recording completed!"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Recording"));
    lcd.setCursor(0, 1);
    lcd.print(F("completed!"));
    lcd.clear();
    //Serial.println(F("Wait a moment to play recorded song..."));
    lcd.setCursor(0, 0);
    lcd.print(F("Wait a moment.."));
    ft_delay(1000);
    lcd.clear();
    //녹음한 배열을 재생.
    play_record();
    ft_delay(1000);
    lcd.clear();
    //Serial.println(F("Back to piano mode!"));
    lcd.setCursor(0, 0);
    lcd.print(F("Back to"));
    lcd.setCursor(0, 1);
    lcd.print(F("piano mode!"));
    ft_delay(1000);
    lcd.clear();
    flag = PIANO;
}
