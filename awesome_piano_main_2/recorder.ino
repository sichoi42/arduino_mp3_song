int16_t recorder[5][100][2];//녹음된 곡을 저장할 배열.

int record_melody(unsigned long rd_start)//'도'음을 녹음.
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int  cnt;
    static int  checker;
    static int  dur_interval;
    static int  m;
    static int  m_dur;

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
        
    if (digitalRead(SELECT_RECORDER) == 0)//녹음을 완료하였을 시 변수를 초기화하고 1반환.
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int record_melody2(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int  cnt;
    static int  checker;
    static int  dur_interval;
    static int  m;
    static int  m_dur;

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
        
    if (digitalRead(SELECT_RECORDER) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int record_melody3(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int  cnt;
    static int  checker;
    static int  dur_interval;
    static int  m;
    static int  m_dur;

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
        
    if (digitalRead(SELECT_RECORDER) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int record_melody4(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int  cnt;
    static int  checker;
    static int  dur_interval;
    static int  m;
    static int  m_dur;

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
        
    if (digitalRead(SELECT_RECORDER) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

int record_melody5(unsigned long rd_start)
{
    static unsigned long m_start;
    static unsigned long m_end;
    static int  cnt;
    static int  checker;
    static int  dur_interval;
    static int  m;
    static int  m_dur;

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
        
    if (digitalRead(SELECT_RECORDER) == 0)
    {
        checker = 0;
        cnt = 0;
        return (1);
    }
    return (0);
}

void play_record()//mp3_player.ino에 정의한 함수를 조금 수정하여 녹음된 곡 재생에 활용.
{
    int8_t m_flag = 0;
    int8_t m2_flag = 0;
    int8_t m3_flag = 0;
    int8_t h_flag = 0;
    int8_t h2_flag = 0;
    int    cnt = 0;
    int    ok = 0;

    while (1)
    {
        //노래가 저장되는 배열을 가르키는 포인터, 사용되는 배열만 포인터로 지정, 사용x -> null을 가르킴.
        melody = recorder[0];
        melody2 = recorder[1];
        melody3 = recorder[2];
        harmony = recorder[3];
        harmony2 = recorder[4];
        break ;
    }
    while (1)
    {
        m_flag = play_melody(100);
        m2_flag = play_melody2(100);
        m3_flag = play_melody3(100);
        h_flag = play_harmony(100);
        h2_flag = play_harmony2(100);
        //모든 멜로디, 화음부가 연주가 끝나면 while문 종료
        if (m_flag && m2_flag && m3_flag && h_flag && h2_flag)
            break ;
    }
    //포인터를 다시 null로 초기화, flag값을 PIANO모드로 변경
    melody = 0;
    melody2 = 0;
    melody3 = 0;
    harmony = 0;
    harmony2 = 0;
}

void recording()
{
    unsigned long rd_start = millis();//녹음 시작버튼이 눌린 시간 측정.
    int8_t        checker[5] = {0, };

    while (1)
    {   
        play_piano();//누른 버튼음을 들을 수 있게 play_piano함수 실행.
        //녹음이 모두 마쳐지면 while문 탈출.
        if (checker[0] != 1)
            checker[0] = record_melody(rd_start);
        if (checker[1] != 1)
            checker[1] = record_melody2(rd_start);
        if (checker[2] != 1)
            checker[2] = record_melody3(rd_start);
        if (checker[3] != 1)
            checker[3] = record_melody4(rd_start);
        if (checker[4] != 1)
            checker[4] = record_melody5(rd_start);
        if (checker[0] && checker[1] && checker[2] && checker[3] && checker[4])
            break ;
    }
    //녹음한 배열을 재생.
    play_record();
    flag = PIANO;
}
