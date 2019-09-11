#include <TTGO.h>

TTGOClass *ttgo;

lv_obj_t *pos = nullptr;
char buf[128];
int counter =0;
void pressed()
{
    uint16_t color = random(0xFFFF);
    ttgo->eTFT->fillScreen(color);
    ttgo->eTFT->setTextColor(color, TFT_WHITE);
    ttgo->eTFT->drawString("User Button pressed",  5, 100, 4);
}
void released()
{
    uint16_t color = random(0xFFFF);
    ttgo->eTFT->fillScreen(color);
    ttgo->eTFT->setTextColor(color, TFT_WHITE);
    counter++;
    ttgo->eTFT->drawString(String(counter).c_str(),  5, 100, 4);
}

void setup()
{
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->eTFT->fillScreen(TFT_BLACK);
    ttgo->eTFT->setTextFont(2);
    ttgo->eTFT->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->eTFT->drawString("T-Watch Touch Test", 62, 90);
    // ttgo->button->setPressedHandler(pressed);
    ttgo->button->setReleasedHandler(released);

}

void loop()
{
   ttgo->button->loop();
    if (ttgo->touch->touched()) {
        TP_Point p =  ttgo->touch->getPoint();
        sprintf(buf, "x:%03d  y:%03d", p.x, p.y);
        ttgo->eTFT->drawString(buf, 80, 118);
        ttgo->eTFT->drawString(String(counter).c_str(),  5, 100, 4);
        counter =0;
    }
    delay(5);
}
