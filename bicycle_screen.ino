#include <SoftwareSerial.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 //定义重置参数
Adafruit_SSD1306 display(OLED_RESET); //定义重置参数
const short ledIf = 3, buzIf = 9, ptIf = 11, blueRx = 4, blueTx = 5, pushButton = 2;
int pt = 0;
bool begin = false, finish = false;
SoftwareSerial BTserial(blueRx, blueTx); //建立Software对象

void setup()
{
    Serial.begin(9600);   //启动串口通讯
    BTserial.begin(9600); // HC-06 默认波特率为9600

    pinMode(ledIf, OUTPUT); //将引脚3设置为输出模式
    pinMode(buzIf, OUTPUT); //将引脚9设置为输出模式

    pinMode(ptIf, INPUT); //将引脚11设置为输入模式

    BTserial.print("AT"); //检测蓝牙通讯是否正常
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // here the 0x3c is the I2C address, check your i2c address if u have multiple devices.
    display.clearDisplay();//清除屏幕
    delay(2000);//清除屏幕
}

void loop()
{
    if (digitalWrite(pushButton) == LOW) //检测按钮是否摁下
    {

        if (BTserial.availabe() > 0) //检测串口是否有蓝牙传输的数据
        {
            if (led == false)
            {
                //开始界面
                 display.drawBitmap(0, 0, myBitmap, 128, 64, WHITE);
                 display.display();
                
                led = true; //记录使用信息
            }
            int distanceDate = BTserial.read(); //将蓝牙接收的路程信息赋值给distanceDate

            //显示路程图像
            finish = true; //记录使用信息
        }

        if (finish == true && BTserial.availabe() == 0)
        {
            //结束界面
            finish = false; //删去使用信息
            begin = false; //删去使用信息
        }

        if (pt = analogRead(A0) > 0) //如果有电位器传输的数据
        {
            //调整亮度
            pt = 0; //将pt数据清零
        }
    }
}
