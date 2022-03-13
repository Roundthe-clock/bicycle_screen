#include<SoftwareSerial.h>

const short ledIf = 3, buzIf = 9, ptIf = 11, blueRx = 4, blueTx = 5, pushButton = 2;
int pt = 0;
SoftwareSerial BTserial(blueRx, blueTx);//建立Software对象

void setup() 
{
    Serial.begin(9600);//启动串口通讯
    BTserial.begin(9600);//HC-06 默认波特率为9600

    pinMode(ledIf, OUTPUT);//将引脚3设置为输出模式
    pinMode(ledIf, OUTPUT);//将引脚9设置为输出模式
    
    pinMode(ptIf, INPUT);//将引脚11设置为输入模式

    BTserial.print("AT");//检测蓝牙通讯是否正常
}


void loop() 
{
    if(digitalWrite(pushButton) == LOW) //检测按钮是否摁下
    {
        if(BTserial.availabe() > 0)//检测串口是否有蓝牙传输的数据
        {
            int distanceDate = BTserial.read();//将软件串口接收的路程信息赋值给distanceDate
            short Date = distanceDate%10;//取出数据中的最后一位数字
            distanceDate /= 10;//将最后一位数去除
            //显示路程图像
        }


        if(pt = analogRead(A0) > 0)//如果有电位器传输的数据
        {
            //调整亮度
            pt = 0;
        }
        
    }
}
